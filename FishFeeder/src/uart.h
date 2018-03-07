/*
 * uart.h
 *
 *  Created on: 05-Nov-2017
 *      Author: CPSG-WB-4
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
void init_usart0(uint16_t baud);
void transmitByte(uint8_t data);
uint8_t receiveByte(void);
void printBinaryByte(uint8_t byte);
void printString(char *str);
char nibbleToHexCharacter(uint8_t nibble);
void printHexByte(uint8_t byte);
void printFloat(double val,uint8_t decPosition);
void printInt(int num, uint8_t radix);
void printLong(uint32_t num, uint8_t radix);
void println();

#endif /* UART_H_ */
