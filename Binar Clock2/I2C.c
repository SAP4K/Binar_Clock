
#include "I2C.h"
void init_I2C(void)
{
	TWBR = 0;
	TWBR = 0x20;
	TWCR = 0;
}
void Start_I2C(void)
{
	TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT); 
	while((TWCR&(1<<TWINT)) == 0 );	
}
void Stop_I2C(void)
{
	TWCR=(1<<TWSTO)|(1<<TWEN)|(1<<TWINT); 
}
void Send_I2C(uint8_t data)
{
	TWDR = data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT)) == 0 );
}
uint8_t Read_I2C()
{
	TWCR=(1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}