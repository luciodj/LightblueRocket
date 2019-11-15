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
#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "port.h"

//get/set PD5_MBUS_RST aliases
#define PD5_MBUS_RST_SetHigh() do { PORTD_OUTSET = 0x20; } while(0)
#define PD5_MBUS_RST_SetLow() do { PORTD_OUTCLR = 0x20; } while(0)
#define PD5_MBUS_RST_Toggle() do { PORTD_OUTTGL = 0x20; } while(0)
#define PD5_MBUS_RST_GetValue() (VPORTD.IN & (0x1 << 5))
#define PD5_MBUS_RST_SetDigitalInput() do { PORTD_DIRCLR = 0x20; } while(0)
#define PD5_MBUS_RST_SetDigitalOutput() do { PORTD_DIRSET = 0x20; } while(0)
#define PD5_MBUS_RST_SetPullUp() do { PORTD_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD5_MBUS_RST_ResetPullUp() do { PORTD_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD5_MBUS_RST_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define PD5_MBUS_RST_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD5_MBUS_RST_DisableInterruptOnChange() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD5_MBUS_RST_EnableInterruptForBothEdges() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD5_MBUS_RST_EnableInterruptForRisingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD5_MBUS_RST_EnableInterruptForFallingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD5_MBUS_RST_DisableDigitalInputBuffer() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD5_MBUS_RST_EnableInterruptForLowLevelSensing() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PF6_RST aliases
#define PF6_RST_SetHigh() do { PORTF_OUTSET = 0x40; } while(0)
#define PF6_RST_SetLow() do { PORTF_OUTCLR = 0x40; } while(0)
#define PF6_RST_Toggle() do { PORTF_OUTTGL = 0x40; } while(0)
#define PF6_RST_GetValue() (VPORTF.IN & (0x1 << 6))
#define PF6_RST_SetDigitalInput() do { PORTF_DIRCLR = 0x40; } while(0)
#define PF6_RST_SetDigitalOutput() do { PORTF_DIRSET = 0x40; } while(0)
#define PF6_RST_SetPullUp() do { PORTF_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PF6_RST_ResetPullUp() do { PORTF_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PF6_RST_SetInverted() do { PORTF_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define PF6_RST_ResetInverted() do { PORTF_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PF6_RST_DisableInterruptOnChange() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PF6_RST_EnableInterruptForBothEdges() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PF6_RST_EnableInterruptForRisingEdge() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PF6_RST_EnableInterruptForFallingEdge() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PF6_RST_DisableDigitalInputBuffer() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PF6_RST_EnableInterruptForLowLevelSensing() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PD4_HOLD aliases
#define PD4_HOLD_SetHigh() do { PORTD_OUTSET = 0x10; } while(0)
#define PD4_HOLD_SetLow() do { PORTD_OUTCLR = 0x10; } while(0)
#define PD4_HOLD_Toggle() do { PORTD_OUTTGL = 0x10; } while(0)
#define PD4_HOLD_GetValue() (VPORTD.IN & (0x1 << 4))
#define PD4_HOLD_SetDigitalInput() do { PORTD_DIRCLR = 0x10; } while(0)
#define PD4_HOLD_SetDigitalOutput() do { PORTD_DIRSET = 0x10; } while(0)
#define PD4_HOLD_SetPullUp() do { PORTD_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD4_HOLD_ResetPullUp() do { PORTD_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD4_HOLD_SetInverted() do { PORTD_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define PD4_HOLD_ResetInverted() do { PORTD_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD4_HOLD_DisableInterruptOnChange() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD4_HOLD_EnableInterruptForBothEdges() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD4_HOLD_EnableInterruptForRisingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD4_HOLD_EnableInterruptForFallingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD4_HOLD_DisableDigitalInputBuffer() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD4_HOLD_EnableInterruptForLowLevelSensing() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PD7_MBUS_AIN aliases
#define PD7_MBUS_AIN_SetHigh() do { PORTD_OUTSET = 0x80; } while(0)
#define PD7_MBUS_AIN_SetLow() do { PORTD_OUTCLR = 0x80; } while(0)
#define PD7_MBUS_AIN_Toggle() do { PORTD_OUTTGL = 0x80; } while(0)
#define PD7_MBUS_AIN_GetValue() (VPORTD.IN & (0x1 << 7))
#define PD7_MBUS_AIN_SetDigitalInput() do { PORTD_DIRCLR = 0x80; } while(0)
#define PD7_MBUS_AIN_SetDigitalOutput() do { PORTD_DIRSET = 0x80; } while(0)
#define PD7_MBUS_AIN_SetPullUp() do { PORTD_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD7_MBUS_AIN_ResetPullUp() do { PORTD_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD7_MBUS_AIN_SetInverted() do { PORTD_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define PD7_MBUS_AIN_ResetInverted() do { PORTD_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD7_MBUS_AIN_DisableInterruptOnChange() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD7_MBUS_AIN_EnableInterruptForBothEdges() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD7_MBUS_AIN_EnableInterruptForRisingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD7_MBUS_AIN_EnableInterruptForFallingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD7_MBUS_AIN_DisableDigitalInputBuffer() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD7_MBUS_AIN_EnableInterruptForLowLevelSensing() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PD6_MBUS_INT aliases
#define PD6_MBUS_INT_SetHigh() do { PORTD_OUTSET = 0x40; } while(0)
#define PD6_MBUS_INT_SetLow() do { PORTD_OUTCLR = 0x40; } while(0)
#define PD6_MBUS_INT_Toggle() do { PORTD_OUTTGL = 0x40; } while(0)
#define PD6_MBUS_INT_GetValue() (VPORTD.IN & (0x1 << 6))
#define PD6_MBUS_INT_SetDigitalInput() do { PORTD_DIRCLR = 0x40; } while(0)
#define PD6_MBUS_INT_SetDigitalOutput() do { PORTD_DIRSET = 0x40; } while(0)
#define PD6_MBUS_INT_SetPullUp() do { PORTD_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD6_MBUS_INT_ResetPullUp() do { PORTD_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD6_MBUS_INT_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define PD6_MBUS_INT_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD6_MBUS_INT_DisableInterruptOnChange() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD6_MBUS_INT_EnableInterruptForBothEdges() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD6_MBUS_INT_EnableInterruptForRisingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD6_MBUS_INT_EnableInterruptForFallingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD6_MBUS_INT_DisableDigitalInputBuffer() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD6_MBUS_INT_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PC0 aliases
#define PC0_SetHigh() do { PORTC_OUTSET = 0x1; } while(0)
#define PC0_SetLow() do { PORTC_OUTCLR = 0x1; } while(0)
#define PC0_Toggle() do { PORTC_OUTTGL = 0x1; } while(0)
#define PC0_GetValue() (VPORTC.IN & (0x1 << 0))
#define PC0_SetDigitalInput() do { PORTC_DIRCLR = 0x1; } while(0)
#define PC0_SetDigitalOutput() do { PORTC_DIRSET = 0x1; } while(0)
#define PC0_SetPullUp() do { PORTC_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PC0_ResetPullUp() do { PORTC_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PC0_SetInverted() do { PORTC_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PC0_ResetInverted() do { PORTC_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PC0_DisableInterruptOnChange() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PC0_EnableInterruptForBothEdges() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PC0_EnableInterruptForRisingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PC0_EnableInterruptForFallingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PC0_DisableDigitalInputBuffer() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PC0_EnableInterruptForLowLevelSensing() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PC2_ACCL_INT1 aliases
#define PC2_ACCL_INT1_SetHigh() do { PORTC_OUTSET = 0x4; } while(0)
#define PC2_ACCL_INT1_SetLow() do { PORTC_OUTCLR = 0x4; } while(0)
#define PC2_ACCL_INT1_Toggle() do { PORTC_OUTTGL = 0x4; } while(0)
#define PC2_ACCL_INT1_GetValue() (VPORTC.IN & (0x1 << 2))
#define PC2_ACCL_INT1_SetDigitalInput() do { PORTC_DIRCLR = 0x4; } while(0)
#define PC2_ACCL_INT1_SetDigitalOutput() do { PORTC_DIRSET = 0x4; } while(0)
#define PC2_ACCL_INT1_SetPullUp() do { PORTC_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PC2_ACCL_INT1_ResetPullUp() do { PORTC_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PC2_ACCL_INT1_SetInverted() do { PORTC_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PC2_ACCL_INT1_ResetInverted() do { PORTC_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PC2_ACCL_INT1_DisableInterruptOnChange() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PC2_ACCL_INT1_EnableInterruptForBothEdges() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PC2_ACCL_INT1_EnableInterruptForRisingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PC2_ACCL_INT1_EnableInterruptForFallingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PC2_ACCL_INT1_DisableDigitalInputBuffer() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PC2_ACCL_INT1_EnableInterruptForLowLevelSensing() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA0 aliases
#define PA0_SetHigh() do { PORTA_OUTSET = 0x1; } while(0)
#define PA0_SetLow() do { PORTA_OUTCLR = 0x1; } while(0)
#define PA0_Toggle() do { PORTA_OUTTGL = 0x1; } while(0)
#define PA0_GetValue() (VPORTA.IN & (0x1 << 0))
#define PA0_SetDigitalInput() do { PORTA_DIRCLR = 0x1; } while(0)
#define PA0_SetDigitalOutput() do { PORTA_DIRSET = 0x1; } while(0)
#define PA0_SetPullUp() do { PORTA_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA0_ResetPullUp() do { PORTA_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA0_SetInverted() do { PORTA_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PA0_ResetInverted() do { PORTA_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA0_DisableInterruptOnChange() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA0_EnableInterruptForBothEdges() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA0_EnableInterruptForRisingEdge() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA0_EnableInterruptForFallingEdge() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA0_DisableDigitalInputBuffer() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA0_EnableInterruptForLowLevelSensing() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PC1 aliases
#define PC1_SetHigh() do { PORTC_OUTSET = 0x2; } while(0)
#define PC1_SetLow() do { PORTC_OUTCLR = 0x2; } while(0)
#define PC1_Toggle() do { PORTC_OUTTGL = 0x2; } while(0)
#define PC1_GetValue() (VPORTC.IN & (0x1 << 1))
#define PC1_SetDigitalInput() do { PORTC_DIRCLR = 0x2; } while(0)
#define PC1_SetDigitalOutput() do { PORTC_DIRSET = 0x2; } while(0)
#define PC1_SetPullUp() do { PORTC_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PC1_ResetPullUp() do { PORTC_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PC1_SetInverted() do { PORTC_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PC1_ResetInverted() do { PORTC_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PC1_DisableInterruptOnChange() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PC1_EnableInterruptForBothEdges() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PC1_EnableInterruptForRisingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PC1_EnableInterruptForFallingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PC1_DisableDigitalInputBuffer() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PC1_EnableInterruptForLowLevelSensing() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA2 aliases
#define PA2_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define PA2_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define PA2_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define PA2_GetValue() (VPORTA.IN & (0x1 << 2))
#define PA2_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define PA2_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define PA2_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA2_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA2_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PA2_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA2_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA2_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA2_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA2_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA2_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA2_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PC3_ACCL_INT2 aliases
#define PC3_ACCL_INT2_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define PC3_ACCL_INT2_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define PC3_ACCL_INT2_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define PC3_ACCL_INT2_GetValue() (VPORTC.IN & (0x1 << 3))
#define PC3_ACCL_INT2_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define PC3_ACCL_INT2_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define PC3_ACCL_INT2_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PC3_ACCL_INT2_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PC3_ACCL_INT2_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PC3_ACCL_INT2_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PC3_ACCL_INT2_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PC3_ACCL_INT2_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PC3_ACCL_INT2_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PC3_ACCL_INT2_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PC3_ACCL_INT2_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PC3_ACCL_INT2_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA1 aliases
#define PA1_SetHigh() do { PORTA_OUTSET = 0x2; } while(0)
#define PA1_SetLow() do { PORTA_OUTCLR = 0x2; } while(0)
#define PA1_Toggle() do { PORTA_OUTTGL = 0x2; } while(0)
#define PA1_GetValue() (VPORTA.IN & (0x1 << 1))
#define PA1_SetDigitalInput() do { PORTA_DIRCLR = 0x2; } while(0)
#define PA1_SetDigitalOutput() do { PORTA_DIRSET = 0x2; } while(0)
#define PA1_SetPullUp() do { PORTA_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA1_ResetPullUp() do { PORTA_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA1_SetInverted() do { PORTA_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PA1_ResetInverted() do { PORTA_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA1_DisableInterruptOnChange() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA1_EnableInterruptForBothEdges() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA1_EnableInterruptForRisingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA1_EnableInterruptForFallingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA1_DisableDigitalInputBuffer() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA1_EnableInterruptForLowLevelSensing() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA4 aliases
#define PA4_SetHigh() do { PORTA_OUTSET = 0x10; } while(0)
#define PA4_SetLow() do { PORTA_OUTCLR = 0x10; } while(0)
#define PA4_Toggle() do { PORTA_OUTTGL = 0x10; } while(0)
#define PA4_GetValue() (VPORTA.IN & (0x1 << 4))
#define PA4_SetDigitalInput() do { PORTA_DIRCLR = 0x10; } while(0)
#define PA4_SetDigitalOutput() do { PORTA_DIRSET = 0x10; } while(0)
#define PA4_SetPullUp() do { PORTA_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA4_ResetPullUp() do { PORTA_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA4_SetInverted() do { PORTA_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define PA4_ResetInverted() do { PORTA_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA4_DisableInterruptOnChange() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA4_EnableInterruptForBothEdges() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA4_EnableInterruptForRisingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA4_EnableInterruptForFallingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA4_DisableDigitalInputBuffer() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA4_EnableInterruptForLowLevelSensing() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA3 aliases
#define PA3_SetHigh() do { PORTA_OUTSET = 0x8; } while(0)
#define PA3_SetLow() do { PORTA_OUTCLR = 0x8; } while(0)
#define PA3_Toggle() do { PORTA_OUTTGL = 0x8; } while(0)
#define PA3_GetValue() (VPORTA.IN & (0x1 << 3))
#define PA3_SetDigitalInput() do { PORTA_DIRCLR = 0x8; } while(0)
#define PA3_SetDigitalOutput() do { PORTA_DIRSET = 0x8; } while(0)
#define PA3_SetPullUp() do { PORTA_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA3_ResetPullUp() do { PORTA_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA3_SetInverted() do { PORTA_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PA3_ResetInverted() do { PORTA_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA3_DisableInterruptOnChange() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA3_EnableInterruptForBothEdges() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA3_EnableInterruptForRisingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA3_EnableInterruptForFallingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA3_DisableDigitalInputBuffer() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA3_EnableInterruptForLowLevelSensing() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA6 aliases
#define PA6_SetHigh() do { PORTA_OUTSET = 0x40; } while(0)
#define PA6_SetLow() do { PORTA_OUTCLR = 0x40; } while(0)
#define PA6_Toggle() do { PORTA_OUTTGL = 0x40; } while(0)
#define PA6_GetValue() (VPORTA.IN & (0x1 << 6))
#define PA6_SetDigitalInput() do { PORTA_DIRCLR = 0x40; } while(0)
#define PA6_SetDigitalOutput() do { PORTA_DIRSET = 0x40; } while(0)
#define PA6_SetPullUp() do { PORTA_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA6_ResetPullUp() do { PORTA_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA6_SetInverted() do { PORTA_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define PA6_ResetInverted() do { PORTA_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA6_DisableInterruptOnChange() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA6_EnableInterruptForBothEdges() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA6_EnableInterruptForRisingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA6_EnableInterruptForFallingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA6_DisableDigitalInputBuffer() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA6_EnableInterruptForLowLevelSensing() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA5 aliases
#define PA5_SetHigh() do { PORTA_OUTSET = 0x20; } while(0)
#define PA5_SetLow() do { PORTA_OUTCLR = 0x20; } while(0)
#define PA5_Toggle() do { PORTA_OUTTGL = 0x20; } while(0)
#define PA5_GetValue() (VPORTA.IN & (0x1 << 5))
#define PA5_SetDigitalInput() do { PORTA_DIRCLR = 0x20; } while(0)
#define PA5_SetDigitalOutput() do { PORTA_DIRSET = 0x20; } while(0)
#define PA5_SetPullUp() do { PORTA_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA5_ResetPullUp() do { PORTA_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA5_SetInverted() do { PORTA_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define PA5_ResetInverted() do { PORTA_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA5_DisableInterruptOnChange() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA5_EnableInterruptForBothEdges() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA5_EnableInterruptForRisingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA5_EnableInterruptForFallingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA5_DisableDigitalInputBuffer() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA5_EnableInterruptForLowLevelSensing() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA7_SPI_CS aliases
#define PA7_SPI_CS_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define PA7_SPI_CS_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define PA7_SPI_CS_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define PA7_SPI_CS_GetValue() (VPORTA.IN & (0x1 << 7))
#define PA7_SPI_CS_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define PA7_SPI_CS_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define PA7_SPI_CS_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA7_SPI_CS_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA7_SPI_CS_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define PA7_SPI_CS_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA7_SPI_CS_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA7_SPI_CS_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA7_SPI_CS_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA7_SPI_CS_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA7_SPI_CS_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA7_SPI_CS_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PF1 aliases
#define PF1_SetHigh() do { PORTF_OUTSET = 0x2; } while(0)
#define PF1_SetLow() do { PORTF_OUTCLR = 0x2; } while(0)
#define PF1_Toggle() do { PORTF_OUTTGL = 0x2; } while(0)
#define PF1_GetValue() (VPORTF.IN & (0x1 << 1))
#define PF1_SetDigitalInput() do { PORTF_DIRCLR = 0x2; } while(0)
#define PF1_SetDigitalOutput() do { PORTF_DIRSET = 0x2; } while(0)
#define PF1_SetPullUp() do { PORTF_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PF1_ResetPullUp() do { PORTF_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PF1_SetInverted() do { PORTF_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PF1_ResetInverted() do { PORTF_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PF1_DisableInterruptOnChange() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PF1_EnableInterruptForBothEdges() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PF1_EnableInterruptForRisingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PF1_EnableInterruptForFallingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PF1_DisableDigitalInputBuffer() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PF1_EnableInterruptForLowLevelSensing() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PF0 aliases
#define PF0_SetHigh() do { PORTF_OUTSET = 0x1; } while(0)
#define PF0_SetLow() do { PORTF_OUTCLR = 0x1; } while(0)
#define PF0_Toggle() do { PORTF_OUTTGL = 0x1; } while(0)
#define PF0_GetValue() (VPORTF.IN & (0x1 << 0))
#define PF0_SetDigitalInput() do { PORTF_DIRCLR = 0x1; } while(0)
#define PF0_SetDigitalOutput() do { PORTF_DIRSET = 0x1; } while(0)
#define PF0_SetPullUp() do { PORTF_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PF0_ResetPullUp() do { PORTF_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PF0_SetInverted() do { PORTF_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PF0_ResetInverted() do { PORTF_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PF0_DisableInterruptOnChange() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PF0_EnableInterruptForBothEdges() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PF0_EnableInterruptForRisingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PF0_EnableInterruptForFallingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PF0_DisableDigitalInputBuffer() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PF0_EnableInterruptForLowLevelSensing() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PF3_SW0_DGI_FW aliases
#define PF3_SW0_DGI_FW_SetHigh() do { PORTF_OUTSET = 0x8; } while(0)
#define PF3_SW0_DGI_FW_SetLow() do { PORTF_OUTCLR = 0x8; } while(0)
#define PF3_SW0_DGI_FW_Toggle() do { PORTF_OUTTGL = 0x8; } while(0)
#define PF3_SW0_DGI_FW_GetValue() (VPORTF.IN & (0x1 << 3))
#define PF3_SW0_DGI_FW_SetDigitalInput() do { PORTF_DIRCLR = 0x8; } while(0)
#define PF3_SW0_DGI_FW_SetDigitalOutput() do { PORTF_DIRSET = 0x8; } while(0)
#define PF3_SW0_DGI_FW_SetPullUp() do { PORTF_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PF3_SW0_DGI_FW_ResetPullUp() do { PORTF_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PF3_SW0_DGI_FW_SetInverted() do { PORTF_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PF3_SW0_DGI_FW_ResetInverted() do { PORTF_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PF3_SW0_DGI_FW_DisableInterruptOnChange() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PF3_SW0_DGI_FW_EnableInterruptForBothEdges() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PF3_SW0_DGI_FW_EnableInterruptForRisingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PF3_SW0_DGI_FW_EnableInterruptForFallingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PF3_SW0_DGI_FW_DisableDigitalInputBuffer() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PF3_SW0_DGI_FW_EnableInterruptForLowLevelSensing() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PF2_EVENT aliases
#define PF2_EVENT_SetHigh() do { PORTF_OUTSET = 0x4; } while(0)
#define PF2_EVENT_SetLow() do { PORTF_OUTCLR = 0x4; } while(0)
#define PF2_EVENT_Toggle() do { PORTF_OUTTGL = 0x4; } while(0)
#define PF2_EVENT_GetValue() (VPORTF.IN & (0x1 << 2))
#define PF2_EVENT_SetDigitalInput() do { PORTF_DIRCLR = 0x4; } while(0)
#define PF2_EVENT_SetDigitalOutput() do { PORTF_DIRSET = 0x4; } while(0)
#define PF2_EVENT_SetPullUp() do { PORTF_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PF2_EVENT_ResetPullUp() do { PORTF_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PF2_EVENT_SetInverted() do { PORTF_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PF2_EVENT_ResetInverted() do { PORTF_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PF2_EVENT_DisableInterruptOnChange() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PF2_EVENT_EnableInterruptForBothEdges() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PF2_EVENT_EnableInterruptForRisingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PF2_EVENT_EnableInterruptForFallingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PF2_EVENT_DisableDigitalInputBuffer() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PF2_EVENT_EnableInterruptForLowLevelSensing() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PF5_ERR_LED aliases
#define PF5_ERR_LED_SetHigh() do { PORTF_OUTSET = 0x20; } while(0)
#define PF5_ERR_LED_SetLow() do { PORTF_OUTCLR = 0x20; } while(0)
#define PF5_ERR_LED_Toggle() do { PORTF_OUTTGL = 0x20; } while(0)
#define PF5_ERR_LED_GetValue() (VPORTF.IN & (0x1 << 5))
#define PF5_ERR_LED_SetDigitalInput() do { PORTF_DIRCLR = 0x20; } while(0)
#define PF5_ERR_LED_SetDigitalOutput() do { PORTF_DIRSET = 0x20; } while(0)
#define PF5_ERR_LED_SetPullUp() do { PORTF_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PF5_ERR_LED_ResetPullUp() do { PORTF_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PF5_ERR_LED_SetInverted() do { PORTF_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define PF5_ERR_LED_ResetInverted() do { PORTF_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PF5_ERR_LED_DisableInterruptOnChange() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PF5_ERR_LED_EnableInterruptForBothEdges() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PF5_ERR_LED_EnableInterruptForRisingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PF5_ERR_LED_EnableInterruptForFallingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PF5_ERR_LED_DisableDigitalInputBuffer() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PF5_ERR_LED_EnableInterruptForLowLevelSensing() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PD3_BLE_RST aliases
#define PD3_BLE_RST_SetHigh() do { PORTD_OUTSET = 0x8; } while(0)
#define PD3_BLE_RST_SetLow() do { PORTD_OUTCLR = 0x8; } while(0)
#define PD3_BLE_RST_Toggle() do { PORTD_OUTTGL = 0x8; } while(0)
#define PD3_BLE_RST_GetValue() (VPORTD.IN & (0x1 << 3))
#define PD3_BLE_RST_SetDigitalInput() do { PORTD_DIRCLR = 0x8; } while(0)
#define PD3_BLE_RST_SetDigitalOutput() do { PORTD_DIRSET = 0x8; } while(0)
#define PD3_BLE_RST_SetPullUp() do { PORTD_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD3_BLE_RST_ResetPullUp() do { PORTD_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD3_BLE_RST_SetInverted() do { PORTD_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PD3_BLE_RST_ResetInverted() do { PORTD_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD3_BLE_RST_DisableInterruptOnChange() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD3_BLE_RST_EnableInterruptForBothEdges() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD3_BLE_RST_EnableInterruptForRisingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD3_BLE_RST_EnableInterruptForFallingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD3_BLE_RST_DisableDigitalInputBuffer() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD3_BLE_RST_EnableInterruptForLowLevelSensing() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PF4_DATA_LED_DGI aliases
#define PF4_DATA_LED_DGI_SetHigh() do { PORTF_OUTSET = 0x10; } while(0)
#define PF4_DATA_LED_DGI_SetLow() do { PORTF_OUTCLR = 0x10; } while(0)
#define PF4_DATA_LED_DGI_Toggle() do { PORTF_OUTTGL = 0x10; } while(0)
#define PF4_DATA_LED_DGI_GetValue() (VPORTF.IN & (0x1 << 4))
#define PF4_DATA_LED_DGI_SetDigitalInput() do { PORTF_DIRCLR = 0x10; } while(0)
#define PF4_DATA_LED_DGI_SetDigitalOutput() do { PORTF_DIRSET = 0x10; } while(0)
#define PF4_DATA_LED_DGI_SetPullUp() do { PORTF_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PF4_DATA_LED_DGI_ResetPullUp() do { PORTF_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PF4_DATA_LED_DGI_SetInverted() do { PORTF_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define PF4_DATA_LED_DGI_ResetInverted() do { PORTF_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PF4_DATA_LED_DGI_DisableInterruptOnChange() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PF4_DATA_LED_DGI_EnableInterruptForBothEdges() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PF4_DATA_LED_DGI_EnableInterruptForRisingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PF4_DATA_LED_DGI_EnableInterruptForFallingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PF4_DATA_LED_DGI_DisableDigitalInputBuffer() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PF4_DATA_LED_DGI_EnableInterruptForLowLevelSensing() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PD2_BLE_RX_INT aliases
#define PD2_BLE_RX_INT_SetHigh() do { PORTD_OUTSET = 0x4; } while(0)
#define PD2_BLE_RX_INT_SetLow() do { PORTD_OUTCLR = 0x4; } while(0)
#define PD2_BLE_RX_INT_Toggle() do { PORTD_OUTTGL = 0x4; } while(0)
#define PD2_BLE_RX_INT_GetValue() (VPORTD.IN & (0x1 << 2))
#define PD2_BLE_RX_INT_SetDigitalInput() do { PORTD_DIRCLR = 0x4; } while(0)
#define PD2_BLE_RX_INT_SetDigitalOutput() do { PORTD_DIRSET = 0x4; } while(0)
#define PD2_BLE_RX_INT_SetPullUp() do { PORTD_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD2_BLE_RX_INT_ResetPullUp() do { PORTD_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD2_BLE_RX_INT_SetInverted() do { PORTD_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PD2_BLE_RX_INT_ResetInverted() do { PORTD_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD2_BLE_RX_INT_DisableInterruptOnChange() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD2_BLE_RX_INT_EnableInterruptForBothEdges() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD2_BLE_RX_INT_EnableInterruptForRisingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD2_BLE_RX_INT_EnableInterruptForFallingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD2_BLE_RX_INT_DisableDigitalInputBuffer() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD2_BLE_RX_INT_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

void PIN_MANAGER_Initialize();
void PORTD_PD5_MBUS_RST_DefaultInterruptHandler(void);
void PORTD_PD5_MBUS_RST_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PF6_RST_DefaultInterruptHandler(void);
void PORTF_PF6_RST_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_PD4_HOLD_DefaultInterruptHandler(void);
void PORTD_PD4_HOLD_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_PD7_MBUS_AIN_DefaultInterruptHandler(void);
void PORTD_PD7_MBUS_AIN_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_PD6_MBUS_INT_DefaultInterruptHandler(void);
void PORTD_PD6_MBUS_INT_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_PC0_DefaultInterruptHandler(void);
void PORTC_PC0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_PC2_ACCL_INT1_DefaultInterruptHandler(void);
void PORTC_PC2_ACCL_INT1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA0_DefaultInterruptHandler(void);
void PORTA_PA0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_PC1_DefaultInterruptHandler(void);
void PORTC_PC1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA2_DefaultInterruptHandler(void);
void PORTA_PA2_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_PC3_ACCL_INT2_DefaultInterruptHandler(void);
void PORTC_PC3_ACCL_INT2_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA1_DefaultInterruptHandler(void);
void PORTA_PA1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA4_DefaultInterruptHandler(void);
void PORTA_PA4_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA3_DefaultInterruptHandler(void);
void PORTA_PA3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA6_DefaultInterruptHandler(void);
void PORTA_PA6_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA5_DefaultInterruptHandler(void);
void PORTA_PA5_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA7_SPI_CS_DefaultInterruptHandler(void);
void PORTA_PA7_SPI_CS_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PF1_DefaultInterruptHandler(void);
void PORTF_PF1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PF0_DefaultInterruptHandler(void);
void PORTF_PF0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PF3_SW0_DGI_FW_DefaultInterruptHandler(void);
void PORTF_PF3_SW0_DGI_FW_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PF2_EVENT_DefaultInterruptHandler(void);
void PORTF_PF2_EVENT_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PF5_ERR_LED_DefaultInterruptHandler(void);
void PORTF_PF5_ERR_LED_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_PD3_BLE_RST_DefaultInterruptHandler(void);
void PORTD_PD3_BLE_RST_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PF4_DATA_LED_DGI_DefaultInterruptHandler(void);
void PORTF_PF4_DATA_LED_DGI_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_PD2_BLE_RX_INT_DefaultInterruptHandler(void);
void PORTD_PD2_BLE_RX_INT_SetInterruptHandler(void (* interruptHandler)(void)) ;
#endif /* PINS_H_INCLUDED */
