// -*- coding: windows-1251 -*-

// Март 2014г. Константин Ильяшенко <kx13@ya.ru>

// Макросы:
// F_CPU - частота процессора
// MCU - тип микроконтроллера
// определены в Makefile

#include <avr/cpufunc.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <inttypes.h>

#include "ds1307/ds1307.h"

#define TIMER_FREQ 100UL // Требуемая частота таймера (Герц)
#define TIMER_PRESCALER 1 // Установить значение делителя таймера в TCCR1B (Bits 2:0)

#define MAX_TIMER  (F_CPU / TIMER_PRESCALER) / TIMER_FREQ // максимальное значение таймера в режиме CTC
#if MAX_TIMER > UINT16_MAX
// значение MAX_TIMER слишком большое, необходимо увеличить TIMER_PRESCALER.
# error "MAX_TIMER too large, need increase TIMER_PRESCALER."
#endif


#define low(x)  ((x) & 0xFF)
#define high(x) (((x) >> 8) & 0xFF)

#define set_bit(port,bit)   port |= _BV(bit)
#define reset_bit(port,bit) port &= ~(_BV(bit))


const uint8_t READ_INTERVAL = 100; // интервал чтения времени из DS1307

uint8_t hour[2];
uint8_t minute[2];
uint8_t second[2];

const int8_t led_digits[] PROGMEM = {64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

enum TRUE_FALSE {FALSE = 0, TRUE = 1};

//динамическая индикация
ISR (TIMER0_COMPA_vect)
{
  static const uint8_t OFFSET = 2;
  static const uint8_t MAX_DIGIT = 3 + OFFSET;
  static uint8_t current_digit = MAX_DIGIT;

   //погасить текущий
  reset_bit(PORTD, current_digit);
  PORTB = 0xFF;

  current_digit++;
  if(current_digit > MAX_DIGIT)
    current_digit = OFFSET;
  
  //зажечь следующий индикатор
  switch(current_digit)
  {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    break;
  };
 
}

// отсчет интервалов считывания показаний
ISR (TIMER1_COMPA_vect)
{
  static uint8_t counter = 0;

  counter++;
  if(counter == READ_INTERVAL)
  {
    get_time = TRUE;
    counter = 0;
  }
}

// опрос кнопок
ISR (TIMER1_COMPB_vect)
{
}

int main(void)
{
  TCCR0A =  _BV(WGM01);  // CTC mode
  TCCR0B = _BV(CS01);  //prescaler at 8
  OCR0A = 130;
  OCR0B = 0;
 
  TCCR1A =  _BV(WGM12);  // CTC mode
  TCCR1B = _BV(CS10);  //prescaler at 1
  OCR1AH = high(MAX_TIMER);
  OCR1AL = low(MAX_TIMER);
  OCR1BH = 0x00;
  OCR1BL = 0x00;
  
  ACSR= _BV(ACD);  // выключаем Analog Comparator 
  
  // прерывания от таймеров
  TIMSK =  _BV(OCIE0A) | _BV(OCIE1A) | _BV(OCIE1B);

  
  //init ds1307
  ds1307_init();

  
  get_time = FALSE;
  set_time = FALSE;

  uint8_t year = 0;
  uint8_t month = 0;
  uint8_t day = 0;
  uint8_t hour = 0;
  uint8_t minute = 0;
  uint8_t second = 0;


//check set date
//  ds1307_setdate(1, 1, 1, 1, 1, 1);
  sei();
  
  for(;;)
  {
    if(get_time)
      ds1307_gettime(&hour, &minute, &second);
    if(set_time)
      ds1307_settime(&hour, &minute, &second);
  }
}
