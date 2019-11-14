/*
 * File:   sst25pf040ct.c
 * Author: M43896
 *
 * Created on September 12, 2019, 2:19 PM
 */
#include "../mcc_generated_files/mcc.h"
#include "MCP9844.h"

#define TEMPERATURE_BYTES (2)
#define MANUFACTURER_ID_BYTES (2)
#define DEVICE_ID_BYTES (2)

void MCP9844_read_temperature(uint8_t * Buffer)
{
    uint8_t Temperature;
    uint16_t Fraction;
    uint8_t Sign;

    i2c_readDataBlock(MCP9844_I2C_ADDRESS, MCP9844_TEMPERATURE, &Buffer[0], TEMPERATURE_BYTES);
    Temperature = (((Buffer[0] & 0x0F) << 4) & 0xF0) | (((Buffer[1] & 0xF0) >> 4) & 0x0F);

    // Fraction multiplied by 10000, so max fraction, which is (0.5 + 0.25 + 0.125 + 0.0625) = 0.9375, which will be 9375
    Fraction =  (Buffer[1] & 0x0F) * 625; 

    // Is temperature negative?
    if (Buffer[0] & 0x10) {
        Sign = '-';
        // convert 2's complement for negative temperatures
        Temperature ^= 0xFF; 
        Temperature++;
    } else {
        Sign = '+';
    }

    Buffer[0] = Sign;
    Buffer[1] = Temperature;
    Buffer[2] = (uint8_t) (Fraction >> 8) & 0xFF;
    Buffer[3] = (uint8_t) (Fraction & 0xFF);

}

void MCP9844_read_mandev(uint8_t * Buffer)
{
    i2c_readDataBlock(MCP9844_I2C_ADDRESS, MCP9844_MANUFACTURER_ID, &Buffer[0], MANUFACTURER_ID_BYTES);
    i2c_readDataBlock(MCP9844_I2C_ADDRESS, MCP9844_DEVICE_ID, &Buffer[2], DEVICE_ID_BYTES);
}

void MCP9844_shutdown(void)
{
    uint8_t Buffer[3];

    Buffer[0] = MCP9844_CONFIG; // MCP9844 config register
    // 16-bit register, MSB is sent first
    Buffer[1] = (1 << 0); // Set bit 8 (SHDN)
    Buffer[2] = 0; // Set all other bits to 0, which is the default setting
    i2c_writeNBytes(MCP9844_I2C_ADDRESS, &Buffer[0], 3);
}
