/*
 * sensor_handling.h
 *
*/

#ifndef SENSOR_HANDLING_H_
#define SENSOR_HANDLING_H_

#include "mcc_generated_files/mcc.h"
#include "peripherals/MCP9844.h"
#include "peripherals/BMA253.h"

uint16_t temp_read(uint8_t * buffer);
void acc_read(uint8_t* buffer, uint16_t* xyz);

#endif /* SENSOR_HANDLING_H_ */