
#ifndef I2C_H_
#define I2C_H_
#include "main.h"
void init_I2C(void);
void Start_I2C(void);
void Stop_I2C(void);
void Send_I2C(uint8_t data);
uint8_t Read_I2C();
#endif /* I2C_H_ */