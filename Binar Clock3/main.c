#include "Watch.h"
void init_function(void)
{
	DDRD = 0;
	DDRD = (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6) | (1<<PD7);
	DDRD &= ~(1<<PD2);
	PORTD |= (1<<PD2);
	DDRB = 0;
	DDRB = (1<<PB5) | (1<<PB4) | (1<<PB3) | (1<<PB0);
	DDRC = 0;
	DDRC = (1<<PC3) | (1<<PC2) | (1<<PC1) | (1<<PC0);
	
	ACSR |= (1 << ACD); //Disable ADC
	cli();
	unsigned char rg = (MCUCR & ~(1 << BODSE)) | (1 << BODS);
	MCUCR = rg | (1 << BODSE);
	MCUCR = rg;


}
void init_first_timing(void)
{
	TCCR0B = 0;
	TCCR0B = (1<<CS01);
	//TCCR1B = (1<<CS11);
	TCNT0 = 0;
	//TCNT1 = 0;
	TCCR2B = 0;
	TCCR2B = (1<<CS21);
	TCNT2 = 0;
}
uint32_t click_cont = 0;
uint8_t check_button(uint16_t* button_counter,bool *check_if_button_is_pressed)
{
	if(click_cont > 1000)
	{
		if(!(PIND & (1<<PD2)))
		{	
			(*check_if_button_is_pressed) = false;
			(*button_counter)++;		
		}
		click_cont = 0;
	}
	click_cont++;
	if((PIND & (1<<PD2)))
	{
		if(((*button_counter) > 1)  && ((*button_counter) < 50))
		{
			(*button_counter) = 0;
			return 1;
		}
	}
	if((*button_counter) >= 50)
	{
		(*button_counter) = 0;
		//Transmit_UART_TTL(97);
		return 2;
	}
	return 0;
}
int main()
{
	init_function();
	init_first_timing();
	UART_TTL();
	uint8_t controler = 0;
	uint16_t button_counter = 0;
	uint8_t result1 = 1;
	uint8_t result2 = 0;
	uint8_t minutes_units = 0;
	uint8_t minutes_tenths = 0;	
	uint8_t hours_units = 0;
	uint8_t hours_tenths = 0;
	bool check_if_button_is_pressed = false;
	while(1)
	{
		
		switch(controler)
		{
			case 0: { Start(); 
				controler = 1; 
				run_minutes();  
				LED_OFF();
				} break;
			case 1:
			{
				result2 = check_button(&button_counter,&check_if_button_is_pressed);
				if(result2 == 2)
				{
					result1++;
					if(result1 == 2)
					{
						run_hours();	
						LED_OFF();	
					}
					if(result1 == 3)
					{
						
						controler = 2;
					}
				}
				if(result1 == 1)
				{
					if(result2 == 1)
					{
						minutes_units++;
						if(minutes_units>9)
						{
							minutes_units = 0;
							minutes_tenths++;
							if(minutes_tenths>5)
							{
								minutes_tenths = 0;
							}
						}
					}
				}
				if(result1 == 2)
				{
					if(result2 == 1)
					{
						hours_units++;
						if(hours_units>9)
						{
							hours_units = 0;
							hours_tenths++;
							if(hours_tenths>2)
							{
								hours_tenths = 0;
								hours_units = 0;
							}	
						}
						if(hours_tenths>=2 && hours_units>3)
							{
								Transmit_UART_TTL(hours_tenths);
								Transmit_UART_TTL(hours_units);
								hours_tenths = 0;
								hours_units = 0;
								
							}
					}
				}
				set_minutes(minutes_units,minutes_tenths);
				set_hours(hours_units,hours_tenths);
				result2 = 0;
			} break;
			case 2:
			{	
				LED_OFF();	
				init_watch(minutes_units,minutes_tenths,hours_units,hours_tenths);
				button_counter = 0;
				controler = 3;
				_delay_ms(1000);
			}break;
			case 3: {
				if(button_counter == 0)
				{
					EICRA |= (1<<ISC01); 
					EIMSK |= (1<<INT0); 
					sei();
					set_sleep_mode(SLEEP_MODE_PWR_SAVE);
					sleep_enable();
					sleep_cpu();
					sleep_disable();
					init_I2C();
					get_current_time(&hours_tenths,&minutes_tenths);
					minutes_units = 0b00001111 & minutes_tenths;
					minutes_tenths&= 0b11110000;
					minutes_tenths = minutes_tenths >> 4;
					hours_units = 0b00001111 & hours_tenths;
					hours_tenths &= 0b11110000;
					hours_tenths = hours_tenths>>4;
				}
					set_minutes(minutes_units,minutes_tenths);
					set_hours(hours_units,hours_tenths);
					button_counter++;
					if(button_counter>=65500)
					{
						LED_OFF();
						button_counter=0;
					}				
				}break;
		}
	}
}

ISR(INT0_vect)
{
}