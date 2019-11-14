/*
 * File:   rn4870.c
 * Author: M43896
 *
 * Created on September 16, 2019, 1:08 PM
 */


// #include <xc.h>

#include "../mcc_generated_files/mcc.h"
#include "BMA253.h"

#define ACCEL_DEVICE_ID_ADDRESS (0x00)
#define ACCEL_X_REG_LSB_ADDRESS (0x02)
#define ACCEL_Y_REG_LSB_ADDRESS (0x04)
#define ACCEL_Z_REG_LSB_ADDRESS (0x06)

#define ACCEL_XYZ_REG_BYTES (6)
#define ACCEL_DEVICE_ID_BYTES (1)

void BMA253_read_acceleration(uint8_t * Buffer)
{
    i2c_readDataBlock(BMA253_I2C_ADDRESS, ACCEL_X_REG_LSB_ADDRESS, &Buffer[0], ACCEL_XYZ_REG_BYTES);
}

void BMA253_read_device_id(uint8_t * Buffer)
{
    i2c_readDataBlock(BMA253_I2C_ADDRESS, ACCEL_DEVICE_ID_ADDRESS, &Buffer[0], ACCEL_DEVICE_ID_BYTES);
}

void BMA253_deep_suspend(void)
{
    uint8_t Buffer[3];

    Buffer[0] = 0x11; // PMU_LPW register
    Buffer[1] = (1 << 5); // Set bit 5 (deep suspend)
    i2c_writeNBytes(BMA253_I2C_ADDRESS, &Buffer[0], 2);
}