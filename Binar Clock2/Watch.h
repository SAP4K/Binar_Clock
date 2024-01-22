
#ifndef WATCH_H_
#define WATCH_H_
#include "UART_TTL.h"
void init_watch(void);
void PWM_function(uint32_t PWM);
void LED_OFF();
void First_run(bool *status_init, uint32_t *counter_time,uint8_t* counter);
void get_current_time();
#endif /* WATCH_H_ */