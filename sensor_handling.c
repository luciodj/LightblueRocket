/*
 * sensor_handling.c
 *
 */

#include "sensor_handling.h"

uint16_t temp_read(uint8_t *buffer)
{
    i2c_readDataBlock(MCP9844_I2C_ADDRESS, MCP9844_TEMPERATURE, &buffer[0], 2);
    uint16_t uTemp = ((buffer[0] << 8) | buffer[1]) & 0x1fff;
    return uTemp;
}

void acc_read(uint8_t *buffer, uint16_t *out)
{
    i2c_readDataBlock(BMA253_I2C_ADDRESS, 2, &buffer[0], 6);
//    uint16_t *p = (uint16_t*)buffer;
    for(uint8_t i=0; i<3; i++){
        uint16_t temp_word = (buffer[i*2 + 1] << 4) | (buffer[i*2] >> 4);
//        *out++ = ((temp_word >> 8 & 0xff)) | (temp_word << 8);
        *out++ = temp_word;
    }
}

