/*************************************************************************//**
 * @file
 * @brief       This file is part of the STM32F401RE platform layer.
 * @details     This file provides UART driver functionality.
 *
 * @copyright
 *
 * Copyright (c) 2021, Broadcom Inc
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/


#include "uart.h"
#include "irq.h"

#include <assert.h>
#include <my_printf.h>
#include <string.h>
#include <stdarg.h>

UART_HandleTypeDef* huart;

/*! The buffer for the uart print */
static uint8_t buffer_[1024];


/*!***************************************************************************
 * @brief   Initialize the Universal Asynchronous Receiver/Transmitter
 *          (UART or LPSCI) bus and DMA module
 * @param   -
 * @return  Returns the \link #status_t status\endlink (#STATUS_OK on success).
 *****************************************************************************/
status_t UART_Init(UART_HandleTypeDef* const m_huart)
{
	huart = m_huart;
    return STATUS_OK;
}

#if !NO_DIRECT_UART_PRINT
#define UART_Print print
#endif


/*!***************************************************************************
 * @brief   printf-like function to send print messages via UART.
 *
 * @details Defined in "driver/uart.c" source file.
 *
 *          Open an UART connection with 8N1, no handshake to
 *          receive the data on a computer.
 *
 *          The baud rate is specified in the project configuration via
 *          UART_BAUDRATE define. Usually its either 115200 or 2000000 bps.
 *
 * @param   fmt_s The usual printf parameters.
 *
 * @return  Returns the \link #status_t status\endlink (#STATUS_OK on success).
 *****************************************************************************/
status_t UART_Print(const char *fmt_s, ...)
{
    va_list ap;
    va_start(ap, fmt_s);
    int len = vsnprintf_((char *) buffer_, sizeof(buffer_), fmt_s, ap);
    va_end(ap);

    if (len < 0) return ERROR_FAIL;

    status_t status = STATUS_BUSY;
    do {
        status = UART_SendBuffer(buffer_, len);
    } while (status == STATUS_BUSY);

    return status;
}

#if !NO_DIRECT_UART_PRINT
#undef UART_Print
#endif

/*!***************************************************************************
 * @brief   Writes several bytes to the UART connection.
 * @param   txBuff Data array to write to the uart connection
 * @param   txSize The size of the data array
 * @param   f Callback function after tx is done, set 0 if not needed;
 * @param   state Optional user state that will be passed to callback
 *                  function; set 0 if not needed.
 * @return  Returns the \link #status_t status\endlink:
 *           - #STATUS_OK (0) on success.
 *           - #STATUS_BUSY on Tx line busy
 *           - #ERROR_NOT_INITIALIZED
 *           - #ERROR_INVALID_ARGUMENT
 *****************************************************************************/
status_t UART_SendBuffer(uint8_t const *txBuff, size_t txSize)
{
    /* Verify arguments. */
    if (!txBuff || txSize == 0) {
        return ERROR_INVALID_ARGUMENT;
    }


    /* Set Tx Busy Status. */
    HAL_StatusTypeDef hal_error = HAL_UART_Transmit(huart, (uint8_t*) txBuff, txSize, 1000);

    if (hal_error != HAL_OK) {
        //return ERROR_FAIL;
        return -1000 - hal_error;
    }

    return STATUS_OK;
}



