/*
 * i2c_master.h
 *
 *  Created on: 04-Mar-2018
 *      Author: CPSG-WB-4
 */

#ifndef I2C_MASTER_H
#define I2C_MASTER_H
#include <stdint.h>
#define I2C_READ 0x01
#define I2C_WRITE 0x00

//#define I2C_DEBUG 1

void i2c_init(void);
uint8_t i2c_start(uint8_t address);
uint8_t i2c_write(uint8_t data);
uint8_t i2c_read_ack(void);
uint8_t i2c_read_nack(void);
uint8_t i2c_transmit(uint8_t iaddress, uint8_t* data, uint16_t length);
uint8_t i2c_receive(uint8_t iaddress, uint8_t* data, uint16_t length);
uint8_t i2c_writeMultipleReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);
uint8_t i2c_readMultipleReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);
void i2c_stop(void);
uint8_t address(uint8_t ADDRESS, uint8_t MODE);
uint8_t i2c_writeReg(uint8_t devaddr, uint8_t regaddr, uint8_t data);
uint8_t i2c_readReg(uint8_t devaddr, uint8_t regaddr);

#endif // I2C_MASTER_H
