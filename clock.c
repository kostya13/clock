// -*- coding: windows-1251 -*-

// Март 2014г. Константин Ильяшенко <kx13@ya.ru>

// Макросы:
// F_CPU - частота процессора
// MCU - тип микроконтроллера
// определены в Makefile


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "ds1307/ds1307.h"

uint8_t hour[2];
uint8_t minute[2];
uint8_t second[2];

ISR (TIMER0_COMPA_vect)
{
}

int main(void)
{


  // CTC mode
  TCCR0A =  _BV(WGM01);
  //prescaler at 8
  TCCR0B = _BV(CS01);
  TCNT0 = 0x00;
  // max value
  OCR0A = 130;
  OCR0B = 0;


  // CTC mode
  TCCR1A =  _BV(WGM12);
  // max value
  OCR0A = 255;
  //prescaler at 8
  TCCR1B = _BV(CS11);
  
  // выключаем Universal Serial Interface
  USICR=0x00;
  // выключаем Analog Comparator 
  ACSR=0x80;
  
  // прерывания от таймеров
  TIMSK =  _BV(OCIE0A) |  _BV(OCIE1A);
  
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
//  ds1307_setdate(1, 1, 1, 1, 1, 1);

  for(;;)
  {
    if(get_date)
      ds1307_getdate(&hour, &minute, &second);
    if(set_date)
      ds1307_setdate(&hour, &minute, &second);
  }
}
