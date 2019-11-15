/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "../include/pin_manager.h"
static void (*PORTD_PD5_MBUS_RST_InterruptHandler)(void);
static void (*PORTF_PF6_RST_InterruptHandler)(void);
static void (*PORTD_PD4_HOLD_InterruptHandler)(void);
static void (*PORTD_PD7_MBUS_AIN_InterruptHandler)(void);
static void (*PORTD_PD6_MBUS_INT_InterruptHandler)(void);
static void (*PORTC_PC0_InterruptHandler)(void);
static void (*PORTC_PC2_ACCL_INT1_InterruptHandler)(void);
static void (*PORTA_PA0_InterruptHandler)(void);
static void (*PORTC_PC1_InterruptHandler)(void);
static void (*PORTA_PA2_InterruptHandler)(void);
static void (*PORTC_PC3_ACCL_INT2_InterruptHandler)(void);
static void (*PORTA_PA1_InterruptHandler)(void);
static void (*PORTA_PA4_InterruptHandler)(void);
static void (*PORTA_PA3_InterruptHandler)(void);
static void (*PORTA_PA6_InterruptHandler)(void);
static void (*PORTA_PA5_InterruptHandler)(void);
static void (*PORTA_PA7_SPI_CS_InterruptHandler)(void);
static void (*PORTF_PF1_InterruptHandler)(void);
static void (*PORTF_PF0_InterruptHandler)(void);
static void (*PORTF_PF3_SW0_DGI_FW_InterruptHandler)(void);
static void (*PORTF_PF2_EVENT_InterruptHandler)(void);
static void (*PORTF_PF5_ERR_LED_InterruptHandler)(void);
static void (*PORTD_PD3_BLE_RST_InterruptHandler)(void);
static void (*PORTF_PF4_DATA_LED_DGI_InterruptHandler)(void);
static void (*PORTD_PD2_BLE_RX_INT_InterruptHandler)(void);

void PORT_Initialize(void);

void PIN_MANAGER_Initialize()
{
    PORT_Initialize();

    /* DIR Registers Initialization */
    PORTA.DIR = 0xD5;
    PORTB.DIR = 0x00;
    PORTC.DIR = 0x01;
    PORTD.DIR = 0x38;
    PORTE.DIR = 0x00;
    PORTF.DIR = 0x31;

    /* OUT Registers Initialization */
    PORTA.OUT = 0x80;
    PORTB.OUT = 0x00;
    PORTC.OUT = 0x00;
    PORTD.OUT = 0x1B;
    PORTE.OUT = 0x00;
    PORTF.OUT = 0x30;

    /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x00;
    PORTA.PIN1CTRL = 0x00;
    PORTA.PIN2CTRL = 0x00;
    PORTA.PIN3CTRL = 0x00;
    PORTA.PIN4CTRL = 0x00;
    PORTA.PIN5CTRL = 0x00;
    PORTA.PIN6CTRL = 0x00;
    PORTA.PIN7CTRL = 0x00;
    PORTB.PIN0CTRL = 0x00;
    PORTB.PIN1CTRL = 0x00;
    PORTB.PIN2CTRL = 0x00;
    PORTB.PIN3CTRL = 0x00;
    PORTB.PIN4CTRL = 0x00;
    PORTB.PIN5CTRL = 0x00;
    PORTB.PIN6CTRL = 0x00;
    PORTB.PIN7CTRL = 0x00;
    PORTC.PIN0CTRL = 0x00;
    PORTC.PIN1CTRL = 0x00;
    PORTC.PIN2CTRL = 0x00;
    PORTC.PIN3CTRL = 0x00;
    PORTC.PIN4CTRL = 0x00;
    PORTC.PIN5CTRL = 0x00;
    PORTC.PIN6CTRL = 0x00;
    PORTC.PIN7CTRL = 0x00;
    PORTD.PIN0CTRL = 0x00;
    PORTD.PIN1CTRL = 0x00;
    PORTD.PIN2CTRL = 0x00;
    PORTD.PIN3CTRL = 0x00;
    PORTD.PIN4CTRL = 0x00;
    PORTD.PIN5CTRL = 0x00;
    PORTD.PIN6CTRL = 0x00;
    PORTD.PIN7CTRL = 0x00;
    PORTE.PIN0CTRL = 0x00;
    PORTE.PIN1CTRL = 0x00;
    PORTE.PIN2CTRL = 0x00;
    PORTE.PIN3CTRL = 0x00;
    PORTE.PIN4CTRL = 0x00;
    PORTE.PIN5CTRL = 0x00;
    PORTE.PIN6CTRL = 0x00;
    PORTE.PIN7CTRL = 0x00;
    PORTF.PIN0CTRL = 0x00;
    PORTF.PIN1CTRL = 0x00;
    PORTF.PIN2CTRL = 0x00;
    PORTF.PIN3CTRL = 0x00;
    PORTF.PIN4CTRL = 0x00;
    PORTF.PIN5CTRL = 0x00;
    PORTF.PIN6CTRL = 0x08;
    PORTF.PIN7CTRL = 0x00;

    /* PORTMUX Initialization */
    PORTMUX.CCLROUTEA = 0x00;
    PORTMUX.EVSYSROUTEA = 0x00;
    PORTMUX.TCAROUTEA = 0x00;
    PORTMUX.TCBROUTEA = 0x00;
    PORTMUX.TWISPIROUTEA = 0x00;
    PORTMUX.USARTROUTEA = 0x00;

    // register default ISC callback functions at runtime; use these methods to register a custom function
    PORTD_PD5_MBUS_RST_SetInterruptHandler(PORTD_PD5_MBUS_RST_DefaultInterruptHandler);
    PORTF_PF6_RST_SetInterruptHandler(PORTF_PF6_RST_DefaultInterruptHandler);
    PORTD_PD4_HOLD_SetInterruptHandler(PORTD_PD4_HOLD_DefaultInterruptHandler);
    PORTD_PD7_MBUS_AIN_SetInterruptHandler(PORTD_PD7_MBUS_AIN_DefaultInterruptHandler);
    PORTD_PD6_MBUS_INT_SetInterruptHandler(PORTD_PD6_MBUS_INT_DefaultInterruptHandler);
    PORTC_PC0_SetInterruptHandler(PORTC_PC0_DefaultInterruptHandler);
    PORTC_PC2_ACCL_INT1_SetInterruptHandler(PORTC_PC2_ACCL_INT1_DefaultInterruptHandler);
    PORTA_PA0_SetInterruptHandler(PORTA_PA0_DefaultInterruptHandler);
    PORTC_PC1_SetInterruptHandler(PORTC_PC1_DefaultInterruptHandler);
    PORTA_PA2_SetInterruptHandler(PORTA_PA2_DefaultInterruptHandler);
    PORTC_PC3_ACCL_INT2_SetInterruptHandler(PORTC_PC3_ACCL_INT2_DefaultInterruptHandler);
    PORTA_PA1_SetInterruptHandler(PORTA_PA1_DefaultInterruptHandler);
    PORTA_PA4_SetInterruptHandler(PORTA_PA4_DefaultInterruptHandler);
    PORTA_PA3_SetInterruptHandler(PORTA_PA3_DefaultInterruptHandler);
    PORTA_PA6_SetInterruptHandler(PORTA_PA6_DefaultInterruptHandler);
    PORTA_PA5_SetInterruptHandler(PORTA_PA5_DefaultInterruptHandler);
    PORTA_PA7_SPI_CS_SetInterruptHandler(PORTA_PA7_SPI_CS_DefaultInterruptHandler);
    PORTF_PF1_SetInterruptHandler(PORTF_PF1_DefaultInterruptHandler);
    PORTF_PF0_SetInterruptHandler(PORTF_PF0_DefaultInterruptHandler);
    PORTF_PF3_SW0_DGI_FW_SetInterruptHandler(PORTF_PF3_SW0_DGI_FW_DefaultInterruptHandler);
    PORTF_PF2_EVENT_SetInterruptHandler(PORTF_PF2_EVENT_DefaultInterruptHandler);
    PORTF_PF5_ERR_LED_SetInterruptHandler(PORTF_PF5_ERR_LED_DefaultInterruptHandler);
    PORTD_PD3_BLE_RST_SetInterruptHandler(PORTD_PD3_BLE_RST_DefaultInterruptHandler);
    PORTF_PF4_DATA_LED_DGI_SetInterruptHandler(PORTF_PF4_DATA_LED_DGI_DefaultInterruptHandler);
    PORTD_PD2_BLE_RX_INT_SetInterruptHandler(PORTD_PD2_BLE_RX_INT_DefaultInterruptHandler);
}

void PORT_Initialize(void)
{
    /* On AVR devices all peripherals are enable from power on reset, this
     * disables all peripherals to save power. Driver shall enable
     * peripheral if used */

    /* Set all pins to low power mode */
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTE + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTF + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTA + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTB + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTC + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTD + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
}

/**
  Allows selecting an interrupt handler for PORTD_PD5_MBUS_RST at application runtime
*/
void PORTD_PD5_MBUS_RST_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD5_MBUS_RST_InterruptHandler = interruptHandler;
}

void PORTD_PD5_MBUS_RST_DefaultInterruptHandler(void)
{
    // add your PORTD_PD5_MBUS_RST interrupt custom code
    // or set custom function using PORTD_PD5_MBUS_RST_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF6_RST at application runtime
*/
void PORTF_PF6_RST_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF6_RST_InterruptHandler = interruptHandler;
}

void PORTF_PF6_RST_DefaultInterruptHandler(void)
{
    // add your PORTF_PF6_RST interrupt custom code
    // or set custom function using PORTF_PF6_RST_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD4_HOLD at application runtime
*/
void PORTD_PD4_HOLD_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD4_HOLD_InterruptHandler = interruptHandler;
}

void PORTD_PD4_HOLD_DefaultInterruptHandler(void)
{
    // add your PORTD_PD4_HOLD interrupt custom code
    // or set custom function using PORTD_PD4_HOLD_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD7_MBUS_AIN at application runtime
*/
void PORTD_PD7_MBUS_AIN_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD7_MBUS_AIN_InterruptHandler = interruptHandler;
}

void PORTD_PD7_MBUS_AIN_DefaultInterruptHandler(void)
{
    // add your PORTD_PD7_MBUS_AIN interrupt custom code
    // or set custom function using PORTD_PD7_MBUS_AIN_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD6_MBUS_INT at application runtime
*/
void PORTD_PD6_MBUS_INT_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD6_MBUS_INT_InterruptHandler = interruptHandler;
}

void PORTD_PD6_MBUS_INT_DefaultInterruptHandler(void)
{
    // add your PORTD_PD6_MBUS_INT interrupt custom code
    // or set custom function using PORTD_PD6_MBUS_INT_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC0 at application runtime
*/
void PORTC_PC0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC0_InterruptHandler = interruptHandler;
}

void PORTC_PC0_DefaultInterruptHandler(void)
{
    // add your PORTC_PC0 interrupt custom code
    // or set custom function using PORTC_PC0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC2_ACCL_INT1 at application runtime
*/
void PORTC_PC2_ACCL_INT1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC2_ACCL_INT1_InterruptHandler = interruptHandler;
}

void PORTC_PC2_ACCL_INT1_DefaultInterruptHandler(void)
{
    // add your PORTC_PC2_ACCL_INT1 interrupt custom code
    // or set custom function using PORTC_PC2_ACCL_INT1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA0 at application runtime
*/
void PORTA_PA0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA0_InterruptHandler = interruptHandler;
}

void PORTA_PA0_DefaultInterruptHandler(void)
{
    // add your PORTA_PA0 interrupt custom code
    // or set custom function using PORTA_PA0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC1 at application runtime
*/
void PORTC_PC1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC1_InterruptHandler = interruptHandler;
}

void PORTC_PC1_DefaultInterruptHandler(void)
{
    // add your PORTC_PC1 interrupt custom code
    // or set custom function using PORTC_PC1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA2 at application runtime
*/
void PORTA_PA2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA2_InterruptHandler = interruptHandler;
}

void PORTA_PA2_DefaultInterruptHandler(void)
{
    // add your PORTA_PA2 interrupt custom code
    // or set custom function using PORTA_PA2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC3_ACCL_INT2 at application runtime
*/
void PORTC_PC3_ACCL_INT2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC3_ACCL_INT2_InterruptHandler = interruptHandler;
}

void PORTC_PC3_ACCL_INT2_DefaultInterruptHandler(void)
{
    // add your PORTC_PC3_ACCL_INT2 interrupt custom code
    // or set custom function using PORTC_PC3_ACCL_INT2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA1 at application runtime
*/
void PORTA_PA1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA1_InterruptHandler = interruptHandler;
}

void PORTA_PA1_DefaultInterruptHandler(void)
{
    // add your PORTA_PA1 interrupt custom code
    // or set custom function using PORTA_PA1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA4 at application runtime
*/
void PORTA_PA4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA4_InterruptHandler = interruptHandler;
}

void PORTA_PA4_DefaultInterruptHandler(void)
{
    // add your PORTA_PA4 interrupt custom code
    // or set custom function using PORTA_PA4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA3 at application runtime
*/
void PORTA_PA3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA3_InterruptHandler = interruptHandler;
}

void PORTA_PA3_DefaultInterruptHandler(void)
{
    // add your PORTA_PA3 interrupt custom code
    // or set custom function using PORTA_PA3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA6 at application runtime
*/
void PORTA_PA6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA6_InterruptHandler = interruptHandler;
}

void PORTA_PA6_DefaultInterruptHandler(void)
{
    // add your PORTA_PA6 interrupt custom code
    // or set custom function using PORTA_PA6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA5 at application runtime
*/
void PORTA_PA5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA5_InterruptHandler = interruptHandler;
}

void PORTA_PA5_DefaultInterruptHandler(void)
{
    // add your PORTA_PA5 interrupt custom code
    // or set custom function using PORTA_PA5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA7_SPI_CS at application runtime
*/
void PORTA_PA7_SPI_CS_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA7_SPI_CS_InterruptHandler = interruptHandler;
}

void PORTA_PA7_SPI_CS_DefaultInterruptHandler(void)
{
    // add your PORTA_PA7_SPI_CS interrupt custom code
    // or set custom function using PORTA_PA7_SPI_CS_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF1 at application runtime
*/
void PORTF_PF1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF1_InterruptHandler = interruptHandler;
}

void PORTF_PF1_DefaultInterruptHandler(void)
{
    // add your PORTF_PF1 interrupt custom code
    // or set custom function using PORTF_PF1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF0 at application runtime
*/
void PORTF_PF0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF0_InterruptHandler = interruptHandler;
}

void PORTF_PF0_DefaultInterruptHandler(void)
{
    // add your PORTF_PF0 interrupt custom code
    // or set custom function using PORTF_PF0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF3_SW0_DGI_FW at application runtime
*/
void PORTF_PF3_SW0_DGI_FW_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF3_SW0_DGI_FW_InterruptHandler = interruptHandler;
}

void PORTF_PF3_SW0_DGI_FW_DefaultInterruptHandler(void)
{
    // add your PORTF_PF3_SW0_DGI_FW interrupt custom code
    // or set custom function using PORTF_PF3_SW0_DGI_FW_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF2_EVENT at application runtime
*/
void PORTF_PF2_EVENT_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF2_EVENT_InterruptHandler = interruptHandler;
}

void PORTF_PF2_EVENT_DefaultInterruptHandler(void)
{
    // add your PORTF_PF2_EVENT interrupt custom code
    // or set custom function using PORTF_PF2_EVENT_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF5_ERR_LED at application runtime
*/
void PORTF_PF5_ERR_LED_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF5_ERR_LED_InterruptHandler = interruptHandler;
}

void PORTF_PF5_ERR_LED_DefaultInterruptHandler(void)
{
    // add your PORTF_PF5_ERR_LED interrupt custom code
    // or set custom function using PORTF_PF5_ERR_LED_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD3_BLE_RST at application runtime
*/
void PORTD_PD3_BLE_RST_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD3_BLE_RST_InterruptHandler = interruptHandler;
}

void PORTD_PD3_BLE_RST_DefaultInterruptHandler(void)
{
    // add your PORTD_PD3_BLE_RST interrupt custom code
    // or set custom function using PORTD_PD3_BLE_RST_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF4_DATA_LED_DGI at application runtime
*/
void PORTF_PF4_DATA_LED_DGI_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF4_DATA_LED_DGI_InterruptHandler = interruptHandler;
}

void PORTF_PF4_DATA_LED_DGI_DefaultInterruptHandler(void)
{
    // add your PORTF_PF4_DATA_LED_DGI interrupt custom code
    // or set custom function using PORTF_PF4_DATA_LED_DGI_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD2_BLE_RX_INT at application runtime
*/
void PORTD_PD2_BLE_RX_INT_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD2_BLE_RX_INT_InterruptHandler = interruptHandler;
}

void PORTD_PD2_BLE_RX_INT_DefaultInterruptHandler(void)
{
    // add your PORTD_PD2_BLE_RX_INT interrupt custom code
    // or set custom function using PORTD_PD2_BLE_RX_INT_SetInterruptHandler()
}
