/*
 * uart.c
 *
 *  Created on: 05-Nov-2017
 *      Author: CPSG-WB-4
 */
#include "uart.h"


void init_usart0(uint16_t baud)
{
	//uint16_t MYUBRR  = FOSC/16/baud-1
	uint16_t UBRR_VALUE = 0;
	UBRR_VALUE = (((F_CPU / (baud * 16UL))) - 1);
	/*Set baud rate */
	UBRR0H = (uint8_t)(UBRR_VALUE>>8);
	UBRR0L = (uint8_t)UBRR_VALUE;
	/*Enable receiver and transmitter */
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
	// Set frame format to 8 data bits, no parity, 1 stop bit
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);

}

void transmitByte(uint8_t data) {
                                     /* Wait for empty transmit buffer */
  loop_until_bit_is_set(UCSR0A, UDRE0);
  //or while( !( UCSR0A & (1<<UDRE0) ) );
  /*UDRE0 = 1 when buffer is empty, then only we can write our data,
  so we have to loop untill buffer has data,if buffer dont have data ,UDRE0
  will become 1,indicting buffer is empty*/

  UDR0 = data;                                            /* send data */
}

uint8_t receiveByte(void) {
	//// Wait for byte to be received
  /* This flag bit is set when there are unread data in the receive buffer and cleared when the receive buffer is
	empty (i.e., does not contain any unread data). */
  loop_until_bit_is_set(UCSR0A, RXC0);       /* Wait for incoming data */
  // or while( !(UCSR0A & (1<<RXC0) ) );
  return UDR0;                                /* Return received data */
}

void printBinaryByte(uint8_t byte) {
                       /* Prints out a byte as a series of 1's and 0's */
  uint8_t bit;
  for (bit = 7; bit < 255; bit--) {
    if (bit_is_set(byte, bit))
      transmitByte('1');
    else
      transmitByte('0');
  }
  transmitByte('\n');
}

void printString(char *str) {
	while(*str != '\0')
		 transmitByte(*str++); //++ is to increase the strPointer
}

char nibbleToHexCharacter(uint8_t nibble) {
                                   /* Converts 4 bits into hexadecimal */
  if (nibble < 10) {
    return ('0' + nibble);
  }
  else {
    return ('A' + nibble - 10);
  }
}

void printHexByte(uint8_t byte) {
                        /* Prints a byte as its hexadecimal equivalent */
  uint8_t nibble;
  nibble = (byte & 0b11110000) >> 4;
  transmitByte(nibbleToHexCharacter(nibble));
  nibble = byte & 0b00001111;
  transmitByte(nibbleToHexCharacter(nibble));
}

void printFloat(double val,uint8_t decPosition)
{
	char tempStr[8];
	uint8_t width = 6;
	dtostrf(val,width,decPosition,tempStr);
	printString(tempStr);
}

void printInt(int num, uint8_t radix)
{
	// here 2 means binary, 10 means Decimal, 16 means Hexa
	char numStr[20];
	itoa(num,numStr,radix);
	printString(numStr);
}

void printLong(uint32_t num, uint8_t radix)
{
	// here 2 means binary, 10 means Decimal, 16 means Hexa
	char numStr[34];
	ltoa(num,numStr,radix);
	printString(numStr);
}

void println()
{
	printString("\r\n");
}
