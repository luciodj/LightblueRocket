/*
 * bsp.h
 *
 */

#ifndef BSP_H
#define	BSP_H

#include "mcc_generated_files/mcc.h"

bool SW0_get(void);

void led1_set(uint8_t v);    // RED - ERR
uint8_t led1_get(void);      // RED - ERR

void led0_set(uint8_t v);    // GREEN - DATA
uint8_t led0_get(void);      // GREEN - DATA

#endif	/* BSP_H */

