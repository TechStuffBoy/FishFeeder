/*
 * rtc.c
 *
 *  Created on: 28-Feb-2018
 *      Author: CPSG-WB-4
 */

#include "rtc.h"
#include "i2c.h"

uint8_t decToBcd(uint8_t val)
{
	return( (val/10*16) + (val%10) );
}

uint8_t bcdToDec(uint8_t val)
{
	return( (val/16*10) + (val%16) );
}


void ConfigureDateTime(rtc_t *rtcPtr, uint8_t iHour, uint8_t iMin,
		uint8_t  iSec,  uint8_t iWeekDay, uint8_t iDate,  uint8_t iMonth, uint8_t iYear)
{
	rtcPtr->hour = iHour;
	rtcPtr->min = iMin;
	rtcPtr->sec = iSec;
	rtcPtr->weekDay = iWeekDay;
	rtcPtr->date = iDate;
	rtcPtr->month = iMonth;
	rtcPtr->year = iYear;
}


void setDateTime(rtc_t *rtcPtr)
{
	i2c_start();
	i2c_address(DS3231_ADDRESS, WRITE);
	i2c_write(0x00); //Set Register Starting address
	i2c_write(decToBcd(rtcPtr->sec));
	i2c_write(decToBcd(rtcPtr->min));
	i2c_write(decToBcd(rtcPtr->hour));
	i2c_write(decToBcd(rtcPtr->weekDay));
	i2c_write(decToBcd(rtcPtr->date));
	i2c_write(decToBcd(rtcPtr->month));
	i2c_write(decToBcd(rtcPtr->year));
	i2c_stop();
}

void getDateTime(rtc_t *rtcPtr)
{
	i2c_start();
	i2c_address(DS3231_ADDRESS,WRITE);
	i2c_write(0x00);
	i2c_repeated_start();
	i2c_address(DS3231_ADDRESS,READ);
	rtcPtr->sec = bcdToDec(i2c_read(1) & 0x7F);
	rtcPtr->min = bcdToDec(i2c_read(1));
	rtcPtr->hour = bcdToDec(i2c_read(1) & 0x3F);
	rtcPtr->weekDay = bcdToDec(i2c_read(1));
	rtcPtr->date = bcdToDec(i2c_read(1));
	rtcPtr->month = bcdToDec(i2c_read(1));
	rtcPtr->year = bcdToDec(i2c_read(0)); // return NACK
	i2c_stop();
}

void displayDateTime(rtc_t *rtcPtr)
{
	printString("Time :");
	printInt((uint16_t)rtcPtr->hour,10);
	printString(":");
	printInt((uint16_t)rtcPtr->min,10);
	printString(":");
	printInt((uint16_t)rtcPtr->sec,10);
	printString("\t\t");

	printString("Date :");
	printInt((uint16_t)rtcPtr->date,10);
	printString(":");
	printInt((uint16_t)rtcPtr->month,10);
	printString(":");
	printInt((uint16_t)rtcPtr->year,10);
	printString("\r\n");

}

void rtc_Init()
{
	i2c_init();

	//controlReg
	i2c_start();
	i2c_address(DS3231_ADDRESS,WRITE);
	i2c_write(DS3231_CONTROL_REG);
	i2c_write(0x00);
	i2c_stop();

	//controlReg
	i2c_start();
	i2c_address(DS3231_ADDRESS,WRITE);
	i2c_write(DS3231_STATUS_REG);
	i2c_write(0x08);
	i2c_stop();
}
