/*
 * digitalInputOutput.c
 *
 *  Created on: 19-Feb-2017
 *      Author: CPSG-WB-4
 */


#include "digitalInputOutput.h"


void turnBit(volatile uint8_t *port,uint8_t pinNo,uint8_t value)
{
	if(value)
		*port |= (1<<pinNo);//TurnOnBit
	else
		*port &= ~(1<<pinNo);//TurnOffBit
}

void setPinMode(volatile uint8_t *port,uint8_t pinNo, uint8_t pinMode)
{
	if(pinMode == OUTPUT)
		*port |= (1<<pinNo);//turnBitToOutput
    else if (pinMode == INPUT)
    	*port &= ~(1<<pinNo); //turnBitToInput
}
void enablePullup(volatile uint8_t *port,uint8_t pinNo, uint8_t value)
{
	if(value)
		*port |= (1<<pinNo);//turnPullupresistor
	else
		*port &= ~(1<<pinNo);//TurnOffPullupresistor

}
uint8_t checkBitValue(volatile uint8_t *port,uint8_t pinNo)
{

	if((*port & (1<<pinNo)) == (1<<pinNo) ){
		return 1;
	} else
		return 0;
}
