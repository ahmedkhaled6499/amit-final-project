/*
 * UART.h
 *
 *  Created on: Oct 26, 2020
 *      Author: ahmed
 */

#ifndef UART_H_
#define UART_H_

#define clear_bit(reg,bit) (reg & ~(1<<bit));

void uart_init();
void uart_sendbyte(unsigned char data );
unsigned char uart_receivebyte();

#endif /* UART_H_ */
