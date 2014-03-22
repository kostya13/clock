/*
ds1307 lib 0x01

copyright (c) Davide Gironi, 2013

Released under GPLv3.
Please refer to LICENSE file for licensing information.

References: parts of the code taken from https://github.com/adafruit/RTClib
*/


#ifndef DS1307_H
#define DS1307_H

//definitions
#define DS1307_ADDR (0x68<<1) //device address

//path to i2c fleury lib
#define DS1307_I2CFLEURYPATH "i2cmaster.h" //define the path to i2c fleury lib
#define DS1307_I2CINIT 1 //init i2c

//functions
extern void ds1307_init(void);
extern uint8_t ds1307_settime(uint8_t* time);
extern void ds1307_gettime(uint8_t *time);
 
#endif

