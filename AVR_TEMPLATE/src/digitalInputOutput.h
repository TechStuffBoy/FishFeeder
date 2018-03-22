/*
 * digitalInputOutput.h
 *
 *  Created on: 19-Feb-2017
 *      Author: CPSG-WB-4
 */

#ifndef DIGITALINPUTOUTPUT_H_
#define DIGITALINPUTOUTPUT_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0

void turnBit(volatile uint8_t *port,uint8_t pinNo,uint8_t value);
void setPinMode(volatile uint8_t *port,uint8_t pinNo, uint8_t pinMode);
void enablePullup(volatile uint8_t *port,uint8_t pinNo, uint8_t value);
uint8_t checkBitValue(volatile uint8_t *port,uint8_t pinNo);

#endif /* DIGITALINPUTOUTPUT_H_ */
