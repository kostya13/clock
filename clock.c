// -*- coding: windows-1251 -*-

// Март 2014г. Константин Ильяшенко <kx13@ya.ru>

// Макросы:
// F_CPU - частота процессора
// MCU - тип микроконтроллера
// определены в Makefile

#include <avr/interrupt.h>
#include <inttypes.h>

#include "ds1307.h"

#define TIMERA_FREQ 300UL // Требуемая частота таймера (Герц)
#define TIMERA_PRESCALER 256 // Установить значение делителя таймера в TCCR0A (Bits 2:0)
// максимальное значение таймера в режиме CTC
const uint8_t MAX_TIMERA = (F_CPU / TIMERA_PRESCALER) / TIMERA_FREQ;

#define TIMERB_FREQ 1UL // Требуемая частота таймера (Герц)
#define TIMERB_PRESCALER 256 // Установить значение делителя таймера в TCCR1B (Bits 2:0)
// максимальное значение таймера в режиме CTC
const uint16_t MAX_TIMERB = (F_CPU / TIMERB_PRESCALER) / TIMERB_FREQ;

#define low(x)  ((x) & 0xFF)
#define high(x) (((x) >> 8) & 0xFF)

#define set_bit(port,bit)   port |= _BV(bit)
#define reset_bit(port,bit) port &= ~(_BV(bit))

const  int8_t led_digits[] = {64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

uint8_t time[4];


volatile uint8_t get_time = 1;
volatile uint8_t set_time = 0;

static inline void show_clock(void)
{
  const uint8_t  FIRST_DIGIT = 2;
  const uint8_t  LAST_DIGIT =  5;

  static  uint8_t current_digit = FIRST_DIGIT;

//погасить текущий
  reset_bit(PORTD, current_digit);

  current_digit++;
  if(current_digit > LAST_DIGIT)
    current_digit = FIRST_DIGIT;

  PORTB = led_digits[time[current_digit - FIRST_DIGIT]];

//зажечь следующий индикатор
  set_bit(PORTD, current_digit);
}

static inline void is_key_pressed(void)
{
// соответсвие разрядов индикатора позиции в массиве времени
  const uint8_t H1 = 0; //Hour - часы
  const uint8_t H2 = 1;
  const uint8_t M1 = 2; //Minute - минуты
  const uint8_t M2 = 3;

  const uint8_t KEY_DELAY = 100;
  const uint8_t  ALL_KEYS = 3;
  const uint8_t  HOUR_KEY = 1;
  const uint8_t  MINUTE_KEY = 2;
  static uint8_t delay = 0;

  if(set_time)
    return;

  uint8_t keys = PIND & ALL_KEYS;
  
  if(keys < ALL_KEYS && delay < KEY_DELAY)
    delay++;
  else  
    delay = 0;
 
  if(delay < KEY_DELAY)
    return;

//установка часов
  if (!(keys & HOUR_KEY) )
  {
    time[H2]++;
    if ((time[H2]>9 && time[H1]<2) || (time[H2]>3 && time[H1]==2 )  )
    {
      time[H2] = 0;
      time[H1]++;
    }
    if (time[H1]>2)
      time[H1]=0;
  }
  //установка минут
  else if ( !(keys & MINUTE_KEY))
  {
    time[M2]++;
    if (time[M2]>9)
    {
      time[M2]=0;
      time[M1]++;
    }

    if (time[M1]>5)
      time[M2]=0;
  }
//      ds1307_settime(time);

  set_time =  1;    
}

ISR (TIMER0_COMPA_vect)
{
  show_clock();
}

ISR (TIMER0_COMPB_vect)
{
  is_key_pressed();
}

// отсчет интервалов считывания показаний
ISR (TIMER1_COMPA_vect)
{
  get_time = 1;
  //      ds1307_gettime(time);

}

int main(void)
{
  DDRB = 0xFF; // все на выход
  PORTB = 0x00;

  DDRD =  0b11111100; // два порта на вход для кнопок
  PORTD = 0b00000011; // подтянуть к плюсу входы
  
  TCCR0A =  _BV(WGM01);  // CTC mode
  TCCR0B = _BV(CS02);  //prescaler at 256
  OCR0A = MAX_TIMERA;
  OCR0B = 1;
 
  TCCR1B = _BV(WGM12) | _BV(CS12);  //CTC mode; prescaler at 256
  OCR1AH = high(MAX_TIMERB);
  OCR1AL = low(MAX_TIMERB);
  
  ACSR = _BV(ACD);  // выключаем Analog Comparator 
  
  // разрешение прерывания от таймеров
  TIMSK = _BV(OCIE0A) | _BV(OCIE0B) | _BV(OCIE1A);
  
  ds1307_init();

  sei();

  for(;;)
  {
    if(get_time)
    {
      ds1307_gettime(time);
      get_time = 0;
    }

    if(set_time)
    {
      ds1307_settime(time);
      set_time = 0;
    }
  }
}
