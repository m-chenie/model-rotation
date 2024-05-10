#include "bno055.h"
#include "usart.h"
#include "i2c.h"

void BNO055_Init_DNOF(I2C_HandleTypeDef* hi2c_device)
{
	// initalize BNO055 in dnof mode (fusion mode)
	uint8_t dnof[2] = {OPR_MODE_ADDR, 0x0C};
	uint8_t status;
	status = HAL_I2C_Master_Transmit(hi2c_device, BNO055_I2C_ADDR_LO<<1, dnof, sizeof(dnof), 10);
	HAL_Delay(10);

	uint8_t curr_mode[1];
	HAL_I2C_Mem_Read(hi2c_device, BNO055_I2C_ADDR_LO<<1, OPR_MODE_ADDR, I2C_MEMADD_SIZE_8BIT, curr_mode, 1, 20);
}

uint8_t GetEulerData(I2C_HandleTypeDef* hi2c_device, uint8_t* str){
	uint8_t status;
	status = HAL_I2C_Mem_Read(hi2c_device, BNO055_I2C_ADDR_LO<<1, BNO055_EUL_HEADING_LSB, I2C_MEMADD_SIZE_8BIT, str, IMU_NUMBER_OF_BYTES ,100);
	return status;
}
