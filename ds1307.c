/*
Функции для работы с таймером
*/
#include "avr/io.h"

#include "ds1307.h"
#include "i2cmaster.h"

void ds1307_init()
{
	i2c_init();
}

void ds1307_settime(uint8_t* time)
{
  uint8_t minute = time[2] << 4 | time[3];
  uint8_t hour =  time[0] << 4 | time[1];
  
  i2c_start_wait(DS1307_ADDR | I2C_WRITE);
  i2c_write(0x00);
  i2c_write(0); // сброс секунд при записи времени
  i2c_write(minute);
  i2c_write(hour);
  i2c_stop();
}

void ds1307_gettime(uint8_t *time)
{
  uint8_t minute;
  uint8_t hour ;
  uint8_t status =0;
  
  i2c_start_wait(DS1307_ADDR | I2C_WRITE);
  i2c_write(0x01);
  i2c_rep_start(DS1307_ADDR | I2C_READ);
  minute = i2c_readAck();
  hour = i2c_readNak();
  i2c_stop();

  time[0] = hour >> 4;
  time[1] = hour & 0x0F;

  time[2] = minute >> 4;
  time[3] = minute & 0x0F;

  if(status)
  {
    time[0] = 8;
    time[1] = 8;
  }

}
