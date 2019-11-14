/*
 * File:   ATECC608A.c
 * Author: M43893
 *
 * Created on September 16, 2019, 1:08 PM
 */


#include "../mcc_generated_files/mcc.h"
#include <util/delay.h>
#include "../util.h"
#include "ATECC608A.h"

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

#define CMD_BUFFER_SIZE (8)
#define READ_SERIAL_SIZE (35)
#define GENERATE_KEY_SIZE (64 + 3)

void atecc608_read_serial(uint8_t * serial)
{

    // Word Address, Count = 7, Command = READ, Param1, Param2, Start Address = 0x0000, CRC
	uint8_t cmd_buf[CMD_BUFFER_SIZE] = {ECC_WA_CMD, 0x07, 0x02, 0x80, 0x00, 0x00, 0x09, 0xAD}; //Read 32 bytes of Config Zone

    i2c_writeNBytes(ATECC608A_I2C_ADDRESS, &cmd_buf[0], CMD_BUFFER_SIZE);
    _delay_ms(CMD_READ_SERIAL_EXEC_DELAY);
    i2c_readNBytes(ATECC608A_I2C_ADDRESS, &serial[0], READ_SERIAL_SIZE);
}


void atecc608_generate_key(uint8_t * serial)
{
    // Word Address, Count=7, Command=READ, Param1, Param2, Start Address=0x0000, CRC
    uint8_t cmd_buf[CMD_BUFFER_SIZE] = {ECC_WA_CMD, 0x07, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00}; //Read 64 bytes key from GenKey

    uint16_t crc = 0;
    for (uint8_t x = 1; x < 6; x++) {
	    crc = crc16_update(crc, cmd_buf[x], 1);
    }
    cmd_buf[6] = (uint8_t) crc & 0xFF;
    cmd_buf[7] = (uint8_t) (crc >> 8) & 0xFF;

    i2c_writeNBytes(ATECC608A_I2C_ADDRESS, &cmd_buf[0], CMD_BUFFER_SIZE);
    _delay_ms(CMD_GEN_KEY_MAX_EXEC_DELAY);
    i2c_readNBytes(ATECC608A_I2C_ADDRESS, &serial[0], GENERATE_KEY_SIZE);
}
