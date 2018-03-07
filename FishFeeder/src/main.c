/*
 * main.c
 *
 *  Created on: 28-Feb-2018
 *      Author: CPSG-WB-4
 */


#include "i2c_master.h"
#include "rtc.h"
int main()
{
	init_usart0(9600);
	printString("Starting of Code\r\n");
	rtc_Init();
	/*
	uint8_t iHour, uint8_t iMin, uint8_t  iSec,  uint8_t iWeekDay,
	uint8_t iDate,  uint8_t iMonth, uint8_t iYear
	 */
	//Enable to Set Date
//	ConfigureDateTime(&rtc_set,16,18,20,0,4,3,18);
//	setDateTime(&rtc_set);
	while(1) {
		getDateTime(&rtc_read);
		displayDateTime(&rtc_read);
		_delay_ms(1000);
	}
	return 0;
}
