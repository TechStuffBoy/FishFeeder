

/*




DDRB = 0b00001111; //0->Input,1->Output (PB7,PB6,PB5,PB4,PB3,PB2,PB1,PB0)
//Both are Same
DDRB &= ~((1<<PINB7) | (1<<PB6) | (1<<PB5) | (1<<PB4)); //Setting as input
DDRB |= ( (1<<PB3) | (1<<PB2) |(1<<PB1) |(1<<PB0) ); //setting as Output

PORTB &= ~((1<<PB3) | (1<<PB2) | (1<<PB1) | (1<<PB0)); //clearing the Output Pins initially

If we want to enable pullups for Input pins
PORTB |= ( (1<<PB7) | (1<<PB6) |(1<<PB5) |(1<<PB4) );


#include <util/delay.h>
#include "digitalInputOutput.h"

#define LED1 PC0
#define LED2 PC1
#define SW1 PC2
#define SW2 PC3

#define INDDR DDRC
#define OUTDDR DDRC
#define INPORT PORTC
#define OUTPORT PORTC
#define INPIN PINC

int main()
{
	//Set Pin as Output
	setPinMode(&OUTDDR, LED1, OUTPUT);
	setPinMode(&OUTDDR, LED2, OUTPUT);

	//Set pin as Input
	setPinMode(&INDDR, SW1, INPUT);
	setPinMode(&INDDR, SW2, INPUT);

	//Initially turn output to zero state
	turnBit(&OUTPORT, LED1, LOW);
	turnBit(&OUTPORT, LED2, LOW);

	while(1) {


		if(checkBitValue(&INPIN,SW1)){
			turnBit(&OUTPORT, LED1, HIGH);
			turnBit(&OUTPORT, LED2, LOW);
		} else{
			turnBit(&OUTPORT, LED1, LOW);
			turnBit(&OUTPORT, LED2, LOW);
		}

		if(checkBitValue(&INPIN,SW2)){
			turnBit(&OUTPORT, LED1, LOW);
			turnBit(&OUTPORT, LED2, HIGH);
		} else{
			turnBit(&OUTPORT, LED1, LOW);
			turnBit(&OUTPORT, LED2, LOW);
		}


	}
	return 0;
}
*/
