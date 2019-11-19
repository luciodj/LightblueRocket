/*
 * bsp.c
 *
 *
 */

#include "bsp.h"

bool SW0_get(void)
{
    return PF3_SW0_DGI_FW_GetValue();
}

void led1_set(uint8_t v)    // RED - ERR
{
    if (v)  PF5_ERR_LED_SetLow();   // ON
    else    PF5_ERR_LED_SetHigh();  // OFF
}

uint8_t led1_get(void)      // RED - ERR
{
    return PF5_ERR_LED_GetValue() ? 0 : 1;
}

void led0_set(uint8_t v)    // GREEN - DATA
{
    if (v)  PF4_DATA_LED_DGI_SetLow();   // ON
    else    PF4_DATA_LED_DGI_SetHigh();  // OFF
}

uint8_t led0_get(void)      // GREEN - DATA
{
    return PF4_DATA_LED_DGI_GetValue() ? 0 : 1;
}
