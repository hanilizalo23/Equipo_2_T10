/*
 * UART_driver.c
 *
 *  Created on: 21 mar 2022
 *      Author: Nelida Hernández
 */

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_uart.h"
#include "Bits.h"
#include "UART_driver.h"
#include "FlexTimer.h"
#include <stdio.h>

#define DEMO_UART          UART0
#define DEMO_UART_CLKSRC   UART0_CLK_SRC
#define DEMO_UART_CLK_FREQ CLOCK_GetFreq(UART0_CLK_SRC)
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type) //Own function for my_sizeof, cause we need it

#define ECHO_BUFFER_LENGTH 8

uart_handle_t g_uartHandle;
uint8_t g_tipString[] ="\033[0;34;43m";
uint8_t g_tipString2[]="ARD";
uint8_t g_txBuffer[ECHO_BUFFER_LENGTH] = {0};
uint8_t g_rxBuffer[ECHO_BUFFER_LENGTH] = {0};
volatile bool rxBufferEmpty            = true;
volatile bool txBufferFull             = false;
volatile bool txOnGoing                = false;
volatile bool rxOnGoing                = false;

void UART_init(void)
{
    uart_config_t config;

    UART_GetDefaultConfig(&config);
    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
    config.enableTx     = true;
    config.enableRx     = true;

    UART_Init(DEMO_UART, &config, DEMO_UART_CLK_FREQ);
	CLOCK_EnableClock(kCLOCK_PortB);

	PORT_SetPinMux(PORTB, 16U, kPORT_MuxAlt3);

	PORT_SetPinMux(PORTB, 17U, kPORT_MuxAlt3);

	SIM->SOPT5 = ((SIM->SOPT5 & (~(SIM_SOPT5_UART0TXSRC_MASK))) | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX));
}

void UART_write_freq(void)
{
	float frequency = (uint8_t) get_Frequency();

	UART_WriteBlocking(DEMO_UART, g_tipString, my_sizeof(g_tipString) - 1);
	UART_WriteBlocking(DEMO_UART, "\033[2J", my_sizeof("\033[2J") - 1);
	UART_WriteBlocking(DEMO_UART, "\033[10;10H", my_sizeof("\033[10;10H") - 1);
	UART_WriteBlocking(DEMO_UART, "La frecuencia medida es: ", my_sizeof("La frecuencia medida es: ") - 1);
	UART_WriteBlocking(UART0, &frequency, my_sizeof(frequency));
}

void UART_UserCallback(UART_Type *base, uart_handle_t *handle, status_t status, void *userData)
{
        userData = userData;

        if (kStatus_UART_TxIdle == status)
        {
            txBufferFull = false;
            txOnGoing    = false;
        }

        if (kStatus_UART_RxIdle == status)
        {
            rxBufferEmpty = false;
            rxOnGoing     = false;
        }
}
