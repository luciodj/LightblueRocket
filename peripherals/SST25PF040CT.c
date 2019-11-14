/*
 * File:   sst25pf040ct.c
 * Author: M43896
 *
 * Created on September 12, 2019, 2:19 PM
 */
#include "../mcc_generated_files/mcc.h"
#include "SST25PF040CT.h"

uint8_t sst25_read_id(void) 
{
    uint8_t id = 0;
    
    PD0_SPI_CS_SetLow();
    SPI0_ExchangeByte(OPCODE_RDID); // Send OPCODE_RDID first
    SPI0_ExchangeByte(0x00);        // Send dummy data
    SPI0_ExchangeByte(0x00);        // Send dummy data
    SPI0_ExchangeByte(0x00);        // Send dummy data
    id = SPI0_ExchangeByte(0xFF);   // Read device ID (0x6E)
    PD0_SPI_CS_SetHigh();
    return id;
}

void sst25_read_jedec(uint8_t *data) 
{
    PD0_SPI_CS_SetLow();
    SPI0_ExchangeByte(OPCODE_JEDECID);  // Send OPCODE_JEDECID first
    data[0] = SPI0_ExchangeByte(0xFF);  // Read device ID MSB (Device Id: 0x62)
    data[1] = SPI0_ExchangeByte(0xFF);  // Read device ID (Memory Type: 0x06)
    data[2] = SPI0_ExchangeByte(0xFF);  // Read device ID (Memory Capacity: 0x13)
    data[3] = SPI0_ExchangeByte(0xFF);  // Read device ID LSB (Reserved Code: 0x00)
    PD0_SPI_CS_SetHigh();
}