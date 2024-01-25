
#ifndef WATCH_H_
#define WATCH_H_
#include "UART_TTL.h"
void init_watch(uint8_t minutes_units,uint8_t minutes_tenths,uint8_t hours_units,uint8_t hours_tenths);
void LED_OFF();
void get_current_time();
void set_minutes(uint8_t minutes_units,uint8_t minutes_tenths);
void set_hours(uint8_t hours_units,uint8_t hours_tenths);
void set_minutes2(uint8_t minutes_units,uint8_t minutes_tenths);
void set_hours2(uint8_t hours_units,uint8_t hours_tenths);
void Start();
void run_minutes();
void run_hours();
#endif /* WATCH_H_ */