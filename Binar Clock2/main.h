/*
 * main.h
 *
 * Created: 1/20/2024 8:20:34 PM
 *  Author: SAP4K
 */ 


#ifndef MAIN_H_
#define MAIN_H_
#define F_CPU 8000000UL
#define BAUD_PRESCALER (((F_CPU / (9600 * 16UL))) - 1)
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#include<stdbool.h>
#include<avr/io.h>
#include<util/delay.h>
#include<stdlib.h>
#include<avr/interrupt.h>
#include<util/twi.h>
#define ONLED1( ) PORTD |= ( 1 << PD5 )
#define OFFLED1( ) PORTD &= ~( 1 << PD5 )

#define ONLED2( ) PORTD |= ( 1 << PD6 )
#define OFFLED2( ) PORTD &= ~( 1 << PD6 )

#define ONLED3( ) PORTD |= ( 1 << PD7 )
#define OFFLED3( ) PORTD &= ~( 1 << PD7 )

#define ONLED4( ) PORTB |= ( 1 << PB0 )
#define OFFLED4( ) PORTB &= ~( 1 << PB0 )

#define ONLED5( ) PORTD |= ( 1 << PD3 )
#define OFFLED5( ) PORTD &= ~( 1 << PD3 )

#define ONLED6( ) PORTD |= ( 1 << PD4 )
#define OFFLED6( ) PORTD &= ~( 1 << PD4 )

#define ONLED7( ) PORTC |= ( 1 << PC3 )
#define OFFLED7( ) PORTC &= ~( 1 << PC3 )

#define ONLED8( ) PORTC |= ( 1 << PC2 )
#define OFFLED8( ) PORTC &= ~( 1 << PC2 )

#define ONLED9( ) PORTC |= ( 1 << PC1 )
#define OFFLED9( ) PORTC &= ~( 1 << PC1 )

#define ONLED10( ) PORTC |= ( 1 << PC0 )
#define OFFLED10( ) PORTC &= ~( 1 << PC0 )

#define ONLED11( ) PORTB |= ( 1 << PB5 )
#define OFFLED11( ) PORTB &= ~( 1 << PB5 )

#define ONLED12( ) PORTB |= ( 1 << PB4 )
#define OFFLED12( ) PORTB &= ~( 1 << PB4 )

#define ONLED13( ) PORTB |= ( 1 << PB3 )
#define OFFLED13( ) PORTB &= ~( 1 << PB3 )

#endif /* MAIN_H_ */