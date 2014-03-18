/*
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "ds1307/ds1307.h"

int main(void) {

  //init ds1307
  ds1307_init();

  sei();

  uint8_t year = 0;
  uint8_t month = 0;
  uint8_t day = 0;
  uint8_t hour = 0;
  uint8_t minute = 0;
  uint8_t second = 0;

  //check set date
  ds1307_setdate(1, 1, 1, 1, 1, 1);


  for(;;) {
    //get date
    ds1307_getdate(&year, &month, &day, &hour, &minute, &second);

    _delay_ms(1000);
  }

}
