
#include "Watch.h"
void get_current_time()
{
	Start_I2C();
	Send_I2C(0b11010000);
	Send_I2C(0);
	
	//Transmit_UART_TTL('a');
	Start_I2C();
	Send_I2C(0b11010001);
	Transmit_UART_TTL(Read_I2C());
	Transmit_UART_TTL(Read_I2C());
	Transmit_UART_TTL(Read_I2C());
}
void init_watch()
{	
	init_I2C();
	UART_TTL();
	
	Start_I2C();
	Send_I2C(0b11010000);
	Send_I2C(0x00);
	Send_I2C(0b01011000);
	Send_I2C(0b01011001);
	Send_I2C(0b00100011);
	Send_I2C(0x04);
	Send_I2C(0x05);
	Send_I2C(0x06);
	Stop_I2C();

}
void PWM_function(uint32_t PWM){
	if(PWM > TCNT0)
	{
		ONLED1();
		ONLED2();
		ONLED3();
		ONLED4();
		ONLED5();
		ONLED6();
		ONLED7();
		ONLED8();
		ONLED9();
		ONLED10();
		ONLED11();
		ONLED12();
		ONLED13();
	}
	else
	{
		OFFLED1();
		OFFLED2();
		OFFLED3();
		OFFLED4();
		OFFLED5();
		OFFLED6();
		OFFLED7();
		OFFLED8();
		OFFLED9();
		OFFLED10();
		OFFLED11();
		OFFLED12();
		OFFLED13();
	}
}
void LED_OFF()
{
	OFFLED1();
	OFFLED2();
	OFFLED3();
	OFFLED4();
	OFFLED5();
	OFFLED6();
	OFFLED7();
	OFFLED8();
	OFFLED9();
	OFFLED10();
	OFFLED11();
	OFFLED12();
	OFFLED13();
}
void first_run(bool *status_init, uint32_t *counter_time,uint8_t* counter)
{
	if((*counter_time) == 50000)
	{
		(*counter)++;
		(*counter_time) = 0;
	}
	if((*counter)%2 == 0)
	{
		LED_OFF();
	}
	else
	{
		PWM_function(25);
	}
	(*counter_time)++;
	if((*counter) == 4)
	{
		(*status_init) = 1;
		free(counter);
		free(counter_time);
	}
}

void set_minutes()
{

}