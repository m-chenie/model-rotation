#include <stdint.h>
#include "usart.h"
#include "i2c.h"

#define BNO055_I2C_ADDR_LO 0x28
#define BNO055_EUL_HEADING_LSB  0x1A
#define OPR_MODE_ADDR      0x3D
#define	IMU_NUMBER_OF_BYTES 6

void BNO055_Init_DNOF(I2C_HandleTypeDef* hi2c_device);
uint8_t GetEulerData(I2C_HandleTypeDef* hi2c_device, uint8_t* str);
