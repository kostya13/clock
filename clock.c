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
#include "util/delay.h"

#include "ds1307.h"

#define TIMER_FREQ 100UL // Требуемая частота таймера (Герц)
#define TIMER_PRESCALER 256 // Установить значение делителя таймера в TCCR1B (Bits 2:0)

#define MAX_TIMER  (F_CPU / TIMER_PRESCALER) / TIMER_FREQ // максимальное значение таймера в режиме CTC
#if MAX_TIMER > UINT16_MAX
// значение MAX_TIMER слишком большое, необходимо увеличить TIMER_PRESCALER.
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
  //погасить текущий
  reset_bit(PORTD, current_digit);

  current_digit++;
  if(current_digit > LAST_DIGIT)
    current_digit = FIRST_DIGIT;

  PORTB = led_digits[time[current_digit - FIRST_DIGIT]];

  //зажечь следующий индикатор
  set_bit(PORTD, current_digit);
}


inline void is_key_pressed(void)
{
  uint8_t keys = PIND & 0x03;
  uint8_t pressed = 0;
  if(key_pressed)
    return;
  
  //установка часов
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
  //установка минут
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

//динамическая индикация
ISR (TIMER0_COMPA_vect)
{
  show_clock();
}

// отсчет интервалов считывания показаний
ISR (TIMER1_COMPA_vect)
{
  read_time = 1;
}

//опрос клавиатуры
ISR (TIMER0_COMPB_vect)
{
  is_key_pressed();
}

int main(void)
{
  DDRB = 0xFF; // все на выход
  PORTB = 0x00;

  DDRD =  0b11111100; // два порта на вход для кнопок
  PORTD = 0b00000011; // подтянуть к плюсу входы
  
  TCCR0A =  _BV(WGM01);  // CTC mode
  TCCR0B = _BV(CS02);  //prescaler at 256
  OCR0A = 5;
  OCR0B = 1;
 
  TCCR1B = _BV(WGM12) | _BV(CS12);  //CTC mode; prescaler at 256
  OCR1AH = high(MAX_TIMER);
  OCR1AL = low(MAX_TIMER);
  
  ACSR = _BV(ACD);  // выключаем Analog Comparator 
  
  // разрешение прерывания от таймеров
  TIMSK = _BV(OCIE0A) | _BV(OCIE0B) | _BV(OCIE1A);
  
  ds1307_init();
  ds1307_gettime(time);

  sei();

  for(;;)
  {
    if(read_time)
    {
      ds1307_gettime(time);
      read_time = 0;
    }
    if(key_pressed)
    {
      ds1307_settime(time);
      key_pressed = 0;
    }
  }
}
