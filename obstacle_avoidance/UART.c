/*
 * UART.c
 *
 *  Created on: Oct 26, 2020
 *      Author: ahmed
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "UART.h"

void uart_init(){

	UCSRA |= (1<<1);

	UCSRB = (1<<3) | (1<<4) ;

	UCSRC = (1<<URSEL) | (1<<UCSZ1) |(1<<UCSZ0) ;
UBRRL =12;
}

void uart_sendbyte(unsigned char data ){

while (UCSRA &= ~(1<<UDRE));

UDR = data;

}

unsigned char uart_receivebyte(){

while (UCSRA &=~(1<<RXC));


return UDR;
}
