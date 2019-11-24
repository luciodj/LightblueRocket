/**
  AVR-BLE LightBlue demo

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the default (Out of Box) demo firmware for AVR-BLE board.

  Description:
    It implements a simple serial protocol using the Transparent UART of the
    RN4870 module to report sensor data to the LightBlue mobile App.

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

#include "lightblue.h"
#include "rn487x.h"

#define VERSION     0x02

static char  buffer[80];         // buffer for async messages
static char     serial[80];         // buffer for LightBlue
static uint8_t  sp = 0;             // insertion pointer
static bool     connected = false;  // LightBlue is connected

void message_handler(char* msg)
{
    //    Status Messages Handler
    printf("<<< %s >>>\n", msg);
    if (strstr(msg, "DISCONNECT")){
        connected = false;
        puts("]");
    }
    else if (strstr(msg, "STREAM_OPEN")) {
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
    printf("AVR-BLE LightBlue v%x.%x demo\n", VERSION & 0xf0, VERSION & 0x0f);

    while (1)  {
        if (connected) {
            // on a 1 sec schedule
            if (TCA0.SINGLE.INTFLAGS & 1) {
                TCA0.SINGLE.INTFLAGS = 1; // clear flag

                // send sensor data via transparent UART
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
            // bridge BLE output to terminal
            while (RN487x_DataReady())
                uart[CDC_UART].Write(RN487x_Read());
            //  mirror CDC to BLE
            while (uart[CDC_UART].DataReady())
                uart[BLE_UART].Write(uart[CDC_UART].Read());
        } // disconnected
    } // main loop
}
