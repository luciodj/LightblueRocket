/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16LF18456
        Driver Version    :  2.00
*/

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

#include "util.h"
#include "lightblue.h"
#include "rn487x.h"
#include "mcc_generated_files/utils/interrupt_avr8.h"

#define VERSION     0x06

static uint8_t  buffer[80];         // buffer for async messages
static char     serial[80];         // buffer for LightBlue
static uint8_t  sp = 0;             // insertion pointer
static bool     connected = false;  // LightBlue is connected

void message_handler(uint8_t* msg)
{
    //    Async Message:
//    printf("<<< %s >>>\n", msg);
    if (msg[0] == 'D'){
        connected = false;
        puts("]");
    }
    else if (msg[0] == 'S') {
        connected = true;
        puts("[");
    }
}

int main(void)
{
    SYSTEM_Initialize();
    RN487x_AsyncHandlerSet(message_handler, buffer, sizeof(buffer));
    Enable_global_interrupt();
    RN487X_Init();

    // Assign CDC UART
    print_stdout(USART2_Write);

    print_printf("LightBlue demo\n");

    while (1)  {
        if (connected) {
            // on a 1 sec schedule
            if (TMR0IF) {
                TMR0IF = 0; // clear flag
                led1_update();  // deferred LED control

                // send sensor data via transparent uart
                blue_version(VERSION);
                blue_temp();
                blue_acc();
                blue_leds();
                blue_button();
            }
            // parse BLE output
            while (RN487x_DataReady())
                blue_parse(RN487x_Read());
            // buffer terminal input for LightBlue serial command
            while (uart[CDC_UART].DataReady()) {
                    serial[sp] = uart[CDC_UART].Read();
                    if ((serial[sp] == '\n') || (sp == (sizeof(serial)-1))) {
                        serial[sp] = '\0';
                        blue_serial(serial);
                        sp = 0;
                    }
                    else
                        sp++;
                }
            }

        else { // not connected
            // report BLE output to terminal
            while (RN487x_DataReady())
                uart[CDC_UART].Write(RN487x_Read());
            //  mirror cdc to ble
            while (uart[CDC_UART].DataReady())
                uart[BLE_UART].Write(uart[CDC_UART].Read());
        } // disconnected
    } // main lopp
}