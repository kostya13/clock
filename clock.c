// -*- coding: windows-1251 -*-

// ���� 2014�. ���������� ��������� <kx13@ya.ru>

// �������:
// F_CPU - ������� ����������
// MCU - ��� ����������������
// ���������� � Makefile

#include <avr/cpufunc.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <inttypes.h>

#include "ds1307.h"

#define TIMER_FREQ 100UL // ��������� ������� ������� (����)
#define TIMER_PRESCALER 1 // ���������� �������� �������� ������� � TCCR1B (Bits 2:0)

#define MAX_TIMER  (F_CPU / TIMER_PRESCALER) / TIMER_FREQ // ������������ �������� ������� � ������ CTC
#if MAX_TIMER > UINT16_MAX
// �������� MAX_TIMER ������� �������, ���������� ��������� TIMER_PRESCALER.
# error "MAX_TIMER too large, need increase TIMER_PRESCALER."
#endif

#define low(x)  ((x) & 0xFF)
#define high(x) (((x) >> 8) & 0xFF)

#define set_bit(port,bit)   port |= _BV(bit)
#define reset_bit(port,bit) port &= ~(_BV(bit))

const uint8_t READ_INTERVAL = 100; // �������� ������ ������� �� DS1307

uint8_t hour[2];
uint8_t minute[2];
//uint8_t second[2];

volatile uint8_t get_time;
volatile uint8_t set_time;

const int8_t led_digits[] = {64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

enum TRUE_FALSE {FALSE = 0, TRUE = 1};

volatile uint8_t current_digit = 2;//MAX_DIGIT;

//������������ ���������
ISR (TIMER0_COMPA_vect)
{
  static const uint8_t FIRST_DIGIT = 2;
  static const uint8_t LAST_DIGIT = 5;

   //�������� �������
   reset_bit(PORTD, current_digit);

   current_digit++;
   if(current_digit > LAST_DIGIT)
    current_digit = FIRST_DIGIT;
  
  switch(current_digit)
  {
  case 2:
      PORTB = hour[0];
    break;
  case 3:
      PORTB = hour[1];
    break;
  case 4:
    PORTB = minute[0];
    break;
  case 5:
    PORTB = minute[1];
    break;
  default:
    break;
  };

  //������ ��������� ���������
  set_bit(PORTD, current_digit);

}

// ������ ���������� ���������� ���������
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

// ����� ������
ISR (TIMER1_COMPB_vect)
{
}

int main(void)
{
  DDRB = 0xFF;
  PORTB = 0;

  DDRD =  0b11111100;
  PORTD = 0b00000011;
  
  TCCR0A =  _BV(WGM01);  // CTC mode
  TCCR0B = _BV(CS02);  //prescaler at 256
  OCR0A = 5;
  OCR0B = 0;
 
  TCCR1A =  _BV(WGM12);  // CTC mode
  TCCR1B = _BV(CS10);  //prescaler at 1
  OCR1AH = high(MAX_TIMER);
  OCR1AL = low(MAX_TIMER);
  OCR1BH = 0x00;
  OCR1BL = 0x00;
  
  ACSR = _BV(ACD);  // ��������� Analog Comparator 
  
  // ���������� �� ��������
  TIMSK = _BV(OCIE0A) | _BV(OCIE1A) | _BV(OCIE1B);
  
  //init ds1307
  ds1307_init();
  
  get_time = FALSE;
  set_time = FALSE;

  hour[0] = led_digits[1];
  hour[1] = led_digits[2];
  minute[0] = led_digits[3];
  minute[1] = led_digits[4];

//check set date
//  ds1307_setdate(1, 1, 1, 1, 1, 1);
  sei();
  
  for(;;)
  {
    /*
    if(get_time)
    {
      ds1307_gettime(&hour, &minute, &second);
      get_time = FALSE;
      }
    if(set_time)
      ds1307_settime(&hour, &minute, &second);
    */
  }
}
