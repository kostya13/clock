/*
ds1307 lib 0x01

copyright (c) Davide Gironi, 2013

Released under GPLv3.
Please refer to LICENSE file for licensing information.
*/

#include "avr/io.h"
#include "avr/pgmspace.h"
#include "util/delay.h"

#include "ds1307.h"

//path to i2c fleury lib
#include DS1307_I2CFLEURYPATH

/*
 * initialize the clock
 */
void ds1307_init() {
	i2c_init();
}

uint8_t ds1307_settime(uint8_t* time) {
  uint8_t minute = time[2]<<4 | time[3];
  uint8_t hour =  time[0]<<4 | time[1];
  
  //write date
  i2c_start_wait(DS1307_ADDR | I2C_WRITE);
  i2c_write(0x00);
  i2c_write(0);
  i2c_write(minute);
  i2c_write(hour);
  i2c_stop();

  return 1;
}

void ds1307_gettime(uint8_t *time)
{
  uint8_t minute;
  uint8_t hour ;

  i2c_start_wait(DS1307_ADDR | I2C_WRITE);
  i2c_write(0x01);
  i2c_rep_start(DS1307_ADDR | I2C_READ);
  minute = i2c_readAck();
  hour = i2c_readNak();
  i2c_stop();

  time[0] = hour >>4;
  time[1] = hour & 0x0F;

  time[2] = minute >>4;
  time[3] = minute & 0x0F;
}
