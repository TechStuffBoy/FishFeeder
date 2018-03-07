/*
 * rtc.h
 *
 *  Created on: 28-Feb-2018
 *      Author: CPSG-WB-4
 */

#ifndef RTC_H_
#define RTC_H_
#include <stdint.h>
#include "uart.h"

#define DS3231_ADDRESS 0x68
#define DS3231_CONTROL_REG  0x0E
#define DS3231_STATUS_REG  0x0F
typedef struct
{
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t weekDay;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}rtc_t;

uint8_t decToBcd(uint8_t val);
uint8_t bcdToDec(uint8_t val);
rtc_t rtc_set;
rtc_t rtc_read;
void ConfigureDateTime(rtc_t *rtcPtr, uint8_t iHour, uint8_t iMin,
		uint8_t  iSec,  uint8_t iWeekDay, uint8_t iDate,  uint8_t iMonth, uint8_t iYear);
void setDateTime(rtc_t *rtcPtr);
void getDateTime(rtc_t *rtcPtr);
void displayDateTime(rtc_t *rtcPtr);
void rtc_Init();
#endif /* RTC_H_ */


/*
  	rtc.hour = 0x10; //  10:40:20 am
    rtc.min =  0x40;
    rtc.sec =  0x00;

    rtc.date = 0x01; //1st Jan 2016
    rtc.month = 0x01;
    rtc.year = 0x16;
    rtc.weekDay = 5; // Friday: 5th day of week considering monday as first day.
 */
