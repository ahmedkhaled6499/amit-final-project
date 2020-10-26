/*
 * IR.c
 *
 *  Created on: Oct 26, 2020
 *      Author: ahmed
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void IR (){

SREG |=(1<<7);
MCUCR = (1<<1) | (1<<0);

GICR |=(1<<6);

}
