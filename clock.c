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
#include "util/delay.h"

#include "ds1307.h"

#define TIMER_FREQ 100UL // ��������� ������� ������� (����)
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

#define FIRST_DIGIT 2
#define LAST_DIGIT  5

#define ALL_KEYS_UP 3
#define HOUR_KEY 1
#define MINUTE_KEY 2

const  int8_t led_digits[] = {64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

uint8_t time[4];

volatile uint8_t read_time = 1;
volatile uint8_t key_pressed = 0;
volatile uint8_t oldkeys = ALL_KEYS_UP;

volatile uint8_t current_digit = FIRST_DIGIT;


inline void show_clock(void)
{
  //�������� �������
//  reset_bit(PORTD, current_digit);
  PORTD =  0x03;
//  int a=0;
//  for(int i=0;i<255;i++)a++;

  current_digit++;
  if(current_digit > LAST_DIGIT)
    current_digit = FIRST_DIGIT;


  uint8_t c = time[current_digit - FIRST_DIGIT];
  PORTB = led_digits[c];//
//  _delay_ms(1)
//  _delay_ms(1);

 
  //������ ��������� ���������
  set_bit(PORTD, current_digit);
//  PORTD = 1 << current_digit | 0x03;
}


inline void is_key_pressed(void)
{
  uint8_t keys = PIND & 0x03;
  uint8_t pressed = 0;
  if(key_pressed)
    return;
  
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
  key_pressed =  pressed;    
}

//������������ ���������
ISR (TIMER0_COMPA_vect)
{
  show_clock();
}

// ������ ���������� ���������� ���������
ISR (TIMER1_COMPA_vect)
{
  read_time = 1;
}

//����� ����������
ISR (TIMER0_COMPB_vect)
{
  is_key_pressed();
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
  OCR0B = 1;
 
  TCCR1B = _BV(WGM12) | _BV(CS12);  //CTC mode; prescaler at 256
  OCR1AH = high(MAX_TIMER);
  OCR1AL = low(MAX_TIMER);
  
  ACSR = _BV(ACD);  // ��������� Analog Comparator 
  
  // ���������� ���������� �� ��������
  TIMSK = _BV(OCIE0A) | _BV(OCIE0B) | _BV(OCIE1A);
  
  ds1307_init();
//   time[0]=1;time[1]=2;time[2]=3;time[3]=4;

  // ds1307_settime(time);
//  time[0]=2;time[1]=2;time[2]=5;time[3]=5;

   ds1307_gettime(time);

  sei();

  for(;;)
  {
    
    if(read_time)
    {
          read_time = 0;
          cli();    
          ds1307_gettime(time);
          sei();
    }
    if(key_pressed)
    {
      cli();    
      ds1307_settime(time);
      sei();
      key_pressed = 0;
    }
    
  }
}
