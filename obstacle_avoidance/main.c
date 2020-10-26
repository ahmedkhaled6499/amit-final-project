/*
 * main.c
 *
 *  Created on: Oct 24, 2020
 *      Author: ahmed
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "motors_pwm.h"
#include "LCD_16x2_H_file.h"
#include "UART.h"
#include "IR.h"

#define  Trigger_pin	PB0	/* Trigger pin */

int TimerOverflow =0;
unsigned char left_dis =0;
unsigned char right_dis =0;


ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

ISR(INT0_vect){

	pwm1(0);
	pwm2(0);
	_delay_ms(1000);
	/*
	 * CHECK IF THERE IS AN OBSTACLE IN THE RIGHT while the black line is in front of the car
	 */
	if (PIND & (1<<3)){
		/*
		 * turn to the left
		 */
		pwm2_backward(250); //left motor
		pwm1_backward(100); // right motor

		_delay_ms(2000);

}

	/*
* CHECK IF THERE IS AN OBSTACLE IN THE RIGHT while the black line is in front of the car
		 */
	else if (PINB & (1<<4)){
		/*
		 * TURN RIGHT
		 */
		pwm2_backward(100); //left motor
		pwm1_backward(250); // right motor

		_delay_ms(2000);


	}
	else {
/*
 * if there is no obstacle while the black line is in front of the car
 * turn right
 * or you the car could turn left but i chose right
 */
		pwm2_backward(100); //left motor
		pwm1_backward(250); // right motor

		_delay_ms(2000);


	}

}



int main (){

	char string[10];
	long count;
	double distance;
DDRB = 0x01;		// make trigger pin as output
PORTD |= (1<<6);		/* Turn on Pull-up for the echo pin */

DDRC = 0x0F; //MOTOR
PORTC =0x00;


DDRD &= ~(1<<2); // front sensors as input
PIND &= ~(1<<2);

DDRD &= ~(1<<3); // RIGHT IR sensors  as input
PIND &= ~(1<<3);

DDRB &= ~(1<<4); // LEFT IR sensors  as input
PINB &= ~(1<<4);

DDRB |=(1<<1); // trigger pin
PORTB &= ~(1<<1);

LCD_Init();
LCD_String_xy(1, 0, "Ultrasonic");

sei();			/* Enable global interrupt */
TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
TCCR1A = 0;		/* Set all bit to zero Normal operation */

IR();

	while (1){

		/* Give 10us trigger pulse on trig. pin to the sensor */
				PORTB |= (1 << Trigger_pin);
				_delay_us(10);
				PORTB &= (~(1 << Trigger_pin));

				TCNT1 = 0;	// Clear Timer counter
				TCCR1B = 0x41;	// Capture on rising edge, No prescaler
				TIFR = 1<<ICF1;	// Clear ICP flag (Input Capture flag)
				TIFR = 1<<TOV1;	// Clear Timer Overflow flag

				/*Calculate width of Echo by Input Capture (ICP) */

				while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
				TCNT1 = 0;	/* Clear Timer counter */
				TCCR1B = 0x01;	// Capture on falling edge
				TIFR = 1<<ICF1;	// Clear Input Capture flag
				TIFR = 1<<TOV1;	// Clear Timer Overflow flag
				TimerOverflow = 0; // Clear Timer overflow count

				while ((TIFR & (1 << ICF1)) == 0);// Wait for falling edge
				count = ICR1 + (65535 * TimerOverflow);	// Take count
				/* 8MHz Timer freq, sound speed =343 m/s */
				distance = (double)count / 466.47;

				dtostrf(distance, 2, 2, string);// distance to string
				strcat(string, " cm   ");
				LCD_String_xy(2, 0, "Dist = ");
				LCD_String_xy(2, 7, string);	// Print distance
				_delay_ms(200);

if (distance > 20 ){

	pwm1(250); // if there is nothing infront of the car then move forward
	pwm2(250);

}

else if (distance < 20){
	/*
	 * brakes
	 */
	pwm1(0);//right wheel
	pwm2(0);//left wheel
	_delay_ms(250);
	/*
	 * move left just to let the car adjust it self then stop to take the reading
	 */
	pwm1(250);
	pwm2 (100);

_delay_ms(150);

pwm1(0); // stop to record the reading
pwm2(0);

left_dis =distance;

_delay_ms(150);

pwm1_backward(250); //go back to normal location
pwm2_backward(100);

_delay_ms(150);

pwm1(0);// brakes
pwm2(0);

_delay_ms(150);

pwm2(250); //turn right
pwm1(100);

_delay_ms(150);

pwm1(0); // stop to record the readings
pwm2(0);

right_dis =distance;

_delay_ms(150);

pwm2_backward(250); // go back to normal location
pwm1_backward(100);

_delay_ms(150);

pwm1(0); //brake to take a decision
pwm2(0);

_delay_ms(150);

/*
 * check where is the nearest obstacle
 */
if (right_dis > left_dis  ){

	pwm2(250); //turn right
	pwm1(100);


}
else if (left_dis > right_dis){

	pwm1(250); // turn left
	pwm2 (100);


}


}

			}



		}




