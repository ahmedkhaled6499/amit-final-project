/*
 * motors_pwm.c
 *
 *  Created on: Oct 25, 2020
 *      Author: ahmed
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "motors_pwm.h"

void pwm1 (unsigned char X){
OCR0=X;
	TCCR0 =(1<<3)|(1<<6); //FAST PWM
	TCCR0 |= (1<<5); // non inverting mode
	TCCR0 |= (1<<1); //PRESCALER =8
	DDRB |=(1<<3) ;

	PORTC |= (1<<0);
	PORTC &= ~(1<<1);


	PORTC |= (1<<2);
	PORTC &= ~(1<<3);

}

void pwm2 (unsigned char Y){
OCR2 =Y;
	TCCR2 =(1<<3)|(1<<6); //FAST PWM
	TCCR2 |= (1<<5);
	TCCR2 |= (1<<1);
    DDRD |=(1<<7);

	PORTC |= (1<<0);
	PORTC &= ~(1<<1);


	PORTC |= (1<<2);
	PORTC &= ~(1<<3);
}

void pwm1_backward (unsigned char X){
OCR0=X;
	TCCR0 =(1<<3)|(1<<6); //FAST PWM
	TCCR0 |= (1<<5); // non inverting mode
	TCCR0 |= (1<<1); //PRESCALER =8
	DDRB |=(1<<3) ;

	PORTC &= ~(1<<0);
	PORTC |= (1<<1);

	PORTC &= ~(1<<2);
	PORTC |= (1<<3);
}

void pwm2_backward (unsigned char Y){
OCR2 =Y;
	TCCR2 =(1<<3)|(1<<6); //FAST PWM
	TCCR2 |= (1<<5);// non inverting mode
	TCCR2 |= (1<<1);//PRESCALER =8
    DDRD |=(1<<7);

    PORTC &= ~(1<<0);
    PORTC |= (1<<1);

    PORTC &= ~(1<<2);
    PORTC |= (1<<3);

}

