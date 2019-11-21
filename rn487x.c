/**
  Section: Included Files
 */
#include <stdio.h>

#include "mcc_generated_files/config/clock_config.h"
#include <util/delay.h>

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/drivers/uart.h"
#include "rn487x.h"

/**
  Section: Global Variables
 */
// Command TX buffer
uint8_t cmdBuf[64];

// Tells command prompt is enabled or not
//bool isCmdPromptEnabled = true;

// Assign BLE_UART (USART0) functions -- will be templated by MCC
#define rn487xUartTx        uart[BLE_UART].Write
#define rn487xUartRx        uart[BLE_UART].Read
#define rn487xIsTxDone      uart[BLE_UART].TransmitDone
#define rn487xIsRxReady     uart[BLE_UART].DataReady
#define rn487xDelayMs       _delay_ms
#define rn487xRstSetHigh()  PD3_BLE_RST_SetHigh()
#define rn487xRstSetLow()   PD3_BLE_RST_SetLow()
#define rn487xRxIndSetLow() PD2_BLE_RX_INT_SetLow()

// mode pins is shared between SW0 (input) and RN mode (only during module reset)
// by configuring it as input we let it pulled up (run mode))
#define rn487xModeSet()     PF3_SW0_DGI_FW_SetDigitalInput()

#define ESCAPE_ASYNC_START  '%'
#define ESCAPE_ASYNC_END    '%'

//    rn487xModeSet = interfaceCb->modeSet;

static char   *buffer;
static uint8_t bsize;
static char   *phead;
static asyncHandlerCb_t *asyncHandlerCb;


bool RN487x_AsyncHandlerSet(asyncHandlerCb_t *cb, char* b, uint8_t len)
{
    if ((cb != NULL) && (b != NULL) && (len > 1)) {
        asyncHandlerCb = cb;
        buffer = b;
        bsize = len-1;
        return true;
    }
    else {
        return false;
    }
}

static uint8_t peek = 0;
static bool    ready = false;

/* interceptor of async messages
*/
static bool RN487x_Get(void)
{
    static bool async_buffering = false;

    // blocking loop waiting for one character from the RN module
    uint8_t c = rn487xUartRx();
    if (async_buffering) {
        if (c == ESCAPE_ASYNC_END) {
            async_buffering = false;
            *phead = '\0';
            if (asyncHandlerCb != NULL) {
                (*asyncHandlerCb)(buffer);
            }
        }
        else if (phead < buffer+bsize) {
            *phead++ = c;               // append it
        }
    }
    else {
        if (c == ESCAPE_ASYNC_START) {
            async_buffering = true;
            phead = buffer;             // reset pointer to start of buffer
        }
        else {
            ready = true;
            peek = c;                   // return character
        }
    }
    return ready;
}

bool RN487x_DataReady(void)
{
    if (ready)                      // if peek available return immediately
        return true;

    if (rn487xIsRxReady()) {        // if data arriving
        return RN487x_Get();        // filter it
    }
    return false;
}

uint8_t RN487x_Read(void)
{
    while(!RN487x_DataReady());
    ready = false;                  // consume buffer
    return peek;
}

/**
  Section: RN487x APIs
 */
bool RN487X_Init(void)
{

    // Set to application mode
    rn487xModeSet();

    // Enter reset
    rn487xRstSetLow();
    // Keep the reset pin high
    rn487xDelayMs(RN487X_RESET_HIGH_DELAY_TIME);
    // Exit reset
    rn487xRstSetHigh();

    // Wakeup
    rn487xRxIndSetLow();
    // Wait while RN487X is booting up
    rn487xDelayMs(RN487X_STARTUP_DELAY);

    // flush RN487x
    while (rn487xIsRxReady())
    {
        rn487xUartRx();
    }


    return true;
}

void RN487X_SendCmd(uint8_t *cmd, uint8_t cmdLen)
{
    uint8_t index = 0;

    while (index < cmdLen)
    {
        if (rn487xIsTxDone())
        {
            rn487xUartTx(cmd[index]);
            index++;
        }
    }
}

void RN487X_SendData(const char *data, uint8_t dataLen)
{
    uint8_t index = 0;

    while (index < dataLen)
    {
        if (rn487xIsTxDone())
        {
            rn487xUartTx(data[index]);
            index++;
        }
    }
}

uint8_t RN487X_GetCmd(char *getCmd, uint8_t getCmdLen, char *getCmdResp)
{
    uint8_t index = 0;

    RN487X_SendCmd((uint8_t *) getCmd, getCmdLen);

    do
    {
        getCmdResp[index++] = RN487x_Read();
    }
    while (getCmdResp[index - 1] != '\n');

    return index;
}

bool RN487X_ReadMsg(const uint8_t *expectedMsg, uint8_t msgLen)
{
    uint8_t index;
    uint8_t resp;

    for (index = 0; index < msgLen; index++)
    {
//        putchar('.');
        resp = RN487x_Read();
        if (resp != expectedMsg[index])
        {
//            putchar(resp);
            return false;
        }
    }

    return true;
}

bool RN487X_ReadDefaultResponse(void)
{
    uint8_t resp[3];
    bool status = false;

    resp[0] = RN487x_Read();
    resp[1] = RN487x_Read();
    resp[2] = RN487x_Read();

    switch (resp[0])
    {
    case 'A':
    {
        if ((resp[1] == 'O') && (resp[2] == 'K'))
            status = true;

        break;
    }
    case 'E':
    {
        if ((resp[1] == 'r') && (resp[2] == 'r'))
            status = false;

        break;
    }
    default:
    {
        return status;
    }
    }

    /* Read carriage return and line feed comes with response */
    RN487x_Read();
    RN487x_Read();

    //Read CMD>
//    if (isCmdPromptEnabled)
    {
        RN487x_Read(); // C
        RN487x_Read(); // M
        RN487x_Read(); // D
        RN487x_Read(); // >
        RN487x_Read(); // _
    }

    return status;
}

void RN487X_WaitForMsg(const char *expectedMsg, uint8_t msgLen)
{
    uint8_t index = 0;
    uint8_t resp;

    do
    {
        resp = RN487x_Read();

        if (resp == expectedMsg[index])
        {
            index++;
        }
        else
        {
            index = 0;
            if (resp == expectedMsg[index])
            {
                index++;
            }
        }
    }
    while (index < msgLen);
}


bool RN487X_EnterCmdMode(void)
{
    const uint8_t cmdPrompt[] = {'C', 'M', 'D', '>', ' '};

    cmdBuf[0] = '$';
    cmdBuf[1] = '$';
    cmdBuf[2] = '$';

    RN487X_SendCmd(cmdBuf, 3);

    return RN487X_ReadMsg(cmdPrompt, sizeof (cmdPrompt));
}

bool RN487X_EnterDataMode(void)
{
    const uint8_t cmdPrompt[] = {'E', 'N', 'D', '\r', '\n'};

    cmdBuf[0] = '-';
    cmdBuf[1] = '-';
    cmdBuf[2] = '-';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';

    RN487X_SendCmd(cmdBuf, 5);

    return RN487X_ReadMsg(cmdPrompt, sizeof (cmdPrompt));
}

/* \brief SetIO pin value on/off (on == true)
 */
bool RN487X_SetIO(bool b)
{ // |O,01,00
    cmdBuf[0] = '|';    // I/O
    cmdBuf[1] = 'O';    // Output
    cmdBuf[2] = ',';
    cmdBuf[3] = '0';
    cmdBuf[4] = '1';
    cmdBuf[5] = ',';
    cmdBuf[6] = '0';
    cmdBuf[7] = (b) ? '1':'0';
    cmdBuf[8] = '\r';
    cmdBuf[9] = '\n';

    RN487X_SendCmd(cmdBuf, 10);
    return RN487X_ReadDefaultResponse();
}

bool RN487X_RebootCmd(void)
{
    const uint8_t reboot[] = {'R', 'e', 'b', 'o', 'o', 't', 'i', 'n', 'g', '\r', '\n'};

    cmdBuf[0] = 'R';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[4] = '\r';
    cmdBuf[5] = '\n';

    RN487X_SendCmd(cmdBuf, 5);

    return RN487X_ReadMsg(reboot, sizeof (reboot));
}

bool RN487X_Disconnect(void)
{
    cmdBuf[0] = 'K';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';

    RN487X_SendCmd(cmdBuf, 5);

    return RN487X_ReadDefaultResponse();
}

bool RN487X_GetMsg(uint8_t *data)
{
    if (RN487x_DataReady())
    {
        *data = RN487x_Read();
        return true;
    }

    return false;
}

