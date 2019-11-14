
/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef MCP9844_H
#define	MCP9844_H


// MCP9844 register defines
#define MCP9844_CAPABILITY      0
#define MCP9844_CONFIG          1
#define MCP9844_TUPPER          2
#define MCP9844_TLOWER          3
#define MCP9844_TCRITICAL       4
#define MCP9844_TEMPERATURE     5
#define MCP9844_MANUFACTURER_ID 6
#define MCP9844_DEVICE_ID       7
#define MCP9844_RESERVED        8
#define MCP9844_RESOLUTION      9

// I2C address
#define MCP9844_I2C_ADDRESS     0x18

//*****************************************************************************
// Function prototypes
//*****************************************************************************

void MCP9844_read_temperature(uint8_t * Buffer);
void MCP9844_read_mandev(uint8_t * Buffer);
void MCP9844_shutdown(void);

#endif	/* MCP9844_H */

