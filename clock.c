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

#define TIMER_FREQ 1UL // ��������� ������� ������� (����)
#define TIMER_PRESCALER 256 // ���������� �������� �������� ������� � TCCR1B (Bits 2:0)

#define MAX_TIMER  (F_CPU / TIMER_PRESCALER) / TIMER_FREQ // ������������ �������� ������� � ������ CTC
#if MAX_TIMER > UINT16_MAX
// �������� MAX_TIMER ������� �������, ���������� ��������� TIMER_PRESCALER.
# error "MAX_TIMER too large, need increase TIMER_PRESCALER."
#endif

#define low(x)  ((x) & 0xFF)
#define high(x) (((x) >> 8) & 0xFF)

#define set_bit(port,bit)   port |= _BV(bit)
#define reset_bit(port,bit) port &= ~(_BV(bit))

#define READ_INTERVAL 10
#define FIRST_DIGIT 2
#define LAST_DIGIT  5

#define ALL_KEYS_UP 3
#define HOUR_KEY 1
#define MINUTE_KEY 2

uint8_t time[4];

uint8_t read_time = 1;
uint8_t oldkeys = ALL_KEYS_UP;

const int8_t led_digits[] = {64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

uint8_t current_digit = FIRST_DIGIT;

//������������ ���������
ISR (TIMER0_COMPA_vect)
{
  //�������� �������
  reset_bit(PORTD, current_digit);

  current_digit++;
  if(current_digit > LAST_DIGIT)
    current_digit = FIRST_DIGIT;
  
  PORTB = led_digits[time[current_digit - FIRST_DIGIT]];

  //������ ��������� ���������
  set_bit(PORTD, current_digit);

}


uint8_t is_key_pressed(void)
{
  uint8_t keys = PIND & 0x03;
  uint8_t pressed = 0;

  //��������� �����
  if (!(keys & HOUR_KEY) && (oldkeys & HOUR_KEY))
  {
    time[1]++;
    if ((time[1]>9 && time[0]<2) || (time[1]>3 && time[0]==2 )  )
    {
      time[1] = 0;
      time[0]++;
    }
    if (time[0]>2)
      time[0]=0;
    pressed = 1;
  }
  //��������� �����
  else if ( !(keys & MINUTE_KEY) && (oldkeys & MINUTE_KEY))
  {
    time[3]++;
    if (time[3]>9)
    {
      time[3]=0;
      time[2]++;
    }

    if (time[2]>5)
      time[2]=0;

    pressed = 1;    
  }
  oldkeys = keys;
  return pressed;    
}

// ������ ���������� ���������� ���������
ISR (TIMER1_COMPA_vect)
{
  read_time = 1;
}

int main(void)
{
  DDRB = 0xFF; // ��� �� �����
  PORTB = 0x00;

  DDRD =  0b11111100; // ��� ����� �� ���� ��� ������
  PORTD = 0b00000011; // ��������� � ����� �����
  
  TCCR0A =  _BV(WGM01);  // CTC mode
  TCCR0B = _BV(CS02);  //prescaler at 256
  OCR0A = 5;
  OCR0B = 0;
 
  TCCR1A =  _BV(WGM12);  // CTC mode
  TCCR1B = _BV(CS12);  //prescaler at 256
  OCR1AH = high(MAX_TIMER);
  OCR1AL = low(MAX_TIMER);
  
  ACSR = _BV(ACD);  // ��������� Analog Comparator 
  
  // ���������� ���������� �� ��������
  TIMSK = _BV(OCIE0A) | _BV(OCIE1A);
  
  ds1307_init();
  sei();

  for(;;)
  {
    if(read_time)
    {
      read_time = 0;
      ds1307_gettime(time);
    }
    if(is_key_pressed())
    {
      ds1307_settime(time);
    }
  
    
  }
}
