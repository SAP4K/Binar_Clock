#include "UART_TTL.h"
void UART_TTL()
{
	UCSR0B = 0;
	UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
	UCSR0B |= (1<<RXC0);
	UCSR0B |= (1<<TXC0);
	//sei();
	UBRR0L = BAUD_PRESCALE;
	UBRR0H = (BAUD_PRESCALE >> 8);
}
void Transmit_UART_TTL(uint8_t data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}
uint8_t Recive_UART_TTL()
{
	while(!(UCSR0A & (1<<RXC0) ));
	uint8_t for_return  = UDR0;
	return for_return;
}
