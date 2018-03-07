/*
DDRB = 0b00001111; //0->Input,1->Output (PB7,PB6,PB5,PB4,PB3,PB2,PB1,PB0)
//Both are Same
DDRB &= ~((1<<PINB7) | (1<<PB6) | (1<<PB5) | (1<<PB4)); //Setting as input
DDRB |= ( (1<<PB3) | (1<<PB2) |(1<<PB1) |(1<<PB0) ); //setting as Output

PORTB &= ~((1<<PB3) | (1<<PB2) | (1<<PB1) | (1<<PB0)); //clearing the Output Pins initially

If we want to enable pullups for Input pins
PORTB |= ( (1<<PB7) | (1<<PB6) |(1<<PB5) |(1<<PB4) );
 */

#include <util/delay.h>
#include "digitalInputOutput.h"
#include "uart.h"

#define LED1 PB5

#define OUTDDR DDRB
#define OUTPORT PORTB

int main()
{
	//Set Pin as Output
	setPinMode(&OUTDDR, LED1, OUTPUT);

	//Initially turn output to zero state
	turnBit(&OUTPORT, LED1, LOW);
	init_usart0(9600);
	while(1) {
		printString("port is ON\r\n");
		turnBit(&OUTPORT, LED1, HIGH);
		_delay_ms(1000);
		printString("port is OFF\r\n");
		turnBit(&OUTPORT, LED1, LOW);
		_delay_ms(1000);


	}
	return 0;
}
