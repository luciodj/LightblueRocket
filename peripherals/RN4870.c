/*
 * File:   RN4870.c
 * Author: M43896
 *
 * Created on September 16, 2019, 1:08 PM
 */


#include "../mcc_generated_files/mcc.h"
#include <util/delay.h>
#include <stdbool.h>
#include "RN4870.h"

uint8_t buffer[80];

void err_on(void) 
{
    bt_read_reg("|O,01,00\r", buffer);
}

void err_off(void) 
{
    bt_read_reg("|O,01,01\r", buffer);
}

void bt_reset(void) 
{
    PD3_BLE_RST_SetLow();
    _delay_ms(50);
    PD3_BLE_RST_SetHigh();
}

void bt_wakeup(void) 
{
    PD2_BLE_RX_INT_SetLow();
}

void bt_sleep(void) 
{
    PD2_BLE_RX_INT_SetHigh();
    bt_read_reg("O,0\r", buffer);
}

void bt_read_reg(char * cmd, uint8_t * response)
{
    // Get into command mode
    _delay_ms(5);
    USART0_Write('$');
    USART0_Write('$');
    USART0_Write('$');
    _delay_ms(5);

    // CR to clear input if already in CMD mode
    USART0_Write('\r');
    _delay_ms(20);

    // Read out garbage data
    while (USART0_IsRxReady()) {
        USART0_Read();
    }

    // Command to send
    while (*cmd != 0) {
        USART0_Write(*cmd);
        cmd++;
    }

    uint8_t i = 0;
    uint8_t done = false;
    while (!done) {
        // Blocking read of CDC UART
        response[i] = USART0_Read();
        if ((response[i] == '\r') || (response[i] == '\n')) {
            response[i] = 0;
            done = true;
        }
        i++; // No boundary checking on buffer index!!!!! TODO: Fix it (TF: 20191104)
    }
}

