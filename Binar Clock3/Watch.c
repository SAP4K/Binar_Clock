
#include "Watch.h"
void get_current_time(uint8_t* hours,uint8_t* minutes)
{
	Start_I2C();
	Send_I2C(0b11010000);
	Send_I2C(0);
	
	//Transmit_UART_TTL('a');
	Start_I2C();
	Send_I2C(0b11010001);
	Read_I2C();
	(*minutes)=Read_I2C();
	(*hours) = Read_I2C();
}
void run_minutes()
{
	ONLED7();
	ONLED8();
	ONLED9();
	ONLED10();
	ONLED11();
	ONLED12();
	ONLED13();
	_delay_ms(500);
}
void run_hours()
{
	ONLED1();
	ONLED2();
	ONLED3();
	ONLED4();
	ONLED5();
	ONLED6();
	_delay_ms(500);
}
void init_watch(uint8_t minutes_units,uint8_t minutes_tenths,uint8_t hours_units,uint8_t hours_tenths)
{
	init_I2C();
	//UART_TTL();
	Start_I2C();
	uint8_t hours = hours_tenths<<4;
	hours += hours_units;
	uint8_t minutes = minutes_tenths<<4;
	minutes+=minutes_units;
	Send_I2C(0b11010000);
	Send_I2C(0);
	Send_I2C(0);
	Send_I2C(minutes);
	Send_I2C(hours);
	Send_I2C(0x04);
	Send_I2C(0x05);
	Send_I2C(0x06);
	Stop_I2C();

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
void Start()
{
		ONLED1();
		_delay_ms(500);
		OFFLED1();
		ONLED2();
		_delay_ms(500);
		OFFLED2();
		ONLED3();
		_delay_ms(500);
		OFFLED3();
		ONLED4();
		_delay_ms(500);
		OFFLED4();
		ONLED5();
		_delay_ms(500);
		OFFLED5();
		ONLED6();
		_delay_ms(500);
		OFFLED6();
		ONLED7();
		_delay_ms(500);
		OFFLED7();
		ONLED8();
		_delay_ms(500);
		OFFLED8();
		ONLED9();
		_delay_ms(500);
		OFFLED9();
		ONLED10();
		_delay_ms(500);
		OFFLED10();
		ONLED11();
		_delay_ms(500);
		OFFLED11();
		ONLED12();
		_delay_ms(500);
		OFFLED12();
		ONLED13();
		_delay_ms(500);
		OFFLED13();
}

void set_minutes(uint8_t minutes_units,uint8_t minutes_tenths)
{	
		if(minutes_units & (1<<0))
		{
			if(100>TCNT0)
			{
				ONLED10();
			}
			else
			{
				OFFLED10();
			}
		}
		else
		{
			OFFLED10();
		}
		if(minutes_units & (1<<1))
		{
			if(100>TCNT0)
			{
				ONLED11();			
			}
			else
			{
				OFFLED11();
			}
		}
		else
		{
			OFFLED11();
		}
		if(minutes_units & (1<<2))
		{
			if(100>TCNT0)
			{
				ONLED12();
			}
			else
			{
				OFFLED12();
			}
		}
		else
		{
			OFFLED12();
		}
		if(minutes_units & (1<<3))
		{
			if(100>TCNT0)
			{
				ONLED13();
			}
			else
			{
				OFFLED13();
			}
		}
		else
		{
			OFFLED13();
		}
		if(minutes_tenths & (1<<0))
		{
			if(100>TCNT0)
			{
				ONLED7();
			}
			else
			{
				OFFLED7();	
			}
		}
		else
		{
			
			OFFLED7();
		}
		if(minutes_tenths & (1<<1))
		{
			if(100>TCNT0)
			{
				ONLED8();
			}
			else
			{
				OFFLED8();
			}
		}
		else
		{
			
			OFFLED8();
		}
		if(minutes_tenths & (1<<2))
		{
			if(100>TCNT0)
			{
				ONLED9();
			}
			else
			{
				OFFLED9();
			}
		}
		else
		{
			OFFLED9();
		}
	}
void set_hours(uint8_t hours_units,uint8_t hours_tenths)
{
		if(hours_units & (1<<0))
		{
			if(100>TCNT2)
			{
				ONLED3();
			}
			else
			{
				OFFLED3();
			}
		}
		else
		{
			OFFLED3();
		}
		if(hours_units & (1<<1))
		{
			if(100>TCNT2)
			{
				ONLED4();
			}
			else
			{
				OFFLED4();
			}
		}
		else
		{
			OFFLED4();
		}
		if(hours_units & (1<<2))
		{
			if(100>TCNT0)
			{
				ONLED5();
			}
			else
			{
				OFFLED5();
			}
		}
		else
		{
			OFFLED5();
		}
		if(hours_units & (1<<3))
		{
			if(100>TCNT2)
			{
				ONLED6();
			}
			else
			{
				OFFLED6();
			}
		}
		else
		{
			OFFLED6();
		}
		if(hours_tenths & (1<<0))
		{
			if(100>TCNT2)
			{
				ONLED1();
			}
			else
			{
				OFFLED1();
			}
		}
		else
		{
			OFFLED1();
		}
		if(hours_tenths & (1<<1))
		{
			if(100>TCNT2)
			{
				ONLED2();
			}
			else
			{
				OFFLED2();
			}
		}
		else
		{
			OFFLED2();
		}
}
