/*
Функции для работы с таймером
*/
#ifndef DS1307_H
#define DS1307_H

#define DS1307_ADDR (0x68<<1) //device address

extern void ds1307_init(void);
extern uint8_t ds1307_settime(uint8_t* time);
extern uint8_t ds1307_gettime(uint8_t *time);
 
#endif

