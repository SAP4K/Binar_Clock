#include "Watch.h"
void init_function(void)
{
	DDRD = 0;
	DDRD = (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6) | (1<<PD7);
	PORTD &= ~(1<<PD2);
	DDRB = 0;
	DDRB = (1<<PB5) | (1<<PB4) | (1<<PB3);
	DDRC = 0;
	DDRC = (1<<PC3) | (1<<PC2) | (1<<PC1) | (1<<PC0);
}
void init_first_timing(void)
{
	TCCR0B = 0;
	TCCR0B = (1<<CS01);
	TCNT0 = 0;
}
int main()
{
	uint8_t controler=0;
	//init_function();
	init_first_timing();
	//init_watch();
	uint8_t PWM = 25;
	uint8_t minutes = 0;
	uint8_t* counter = (uint8_t*)malloc(sizeof(uint8_t));
	uint32_t* counter_time = (uint32_t*)malloc(sizeof(uint32_t));
	(*counter_time) = 0;
	(*counter) = 1;
	while(1)
	{
		switch(controler){
			case 0: first_run(&controler,counter_time,counter); break;
		}
	//get_current_time();
	}
}
