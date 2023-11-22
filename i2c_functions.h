// i2c_functions.h
#ifndef I2C_FUNCTIONS_H
#define I2C_FUNCTIONS_H

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_Ack(void);
void I2C_Nak(void);
void I2C_Wait(void);
void I2C_Send(unsigned char data);
unsigned char I2C_Read(void);

#endif

// i2c_functions.h
#ifndef I2C_FUNCTIONS_H
#define I2C_FUNCTIONS_H

void I2C_Wait(void);

#endif
