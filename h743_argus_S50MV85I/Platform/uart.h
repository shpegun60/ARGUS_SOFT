/*************************************************************************//**
 * @file
 * @brief       This file is part of the AFBR-S50 API.
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
 *
 *****************************************************************************/

#ifndef UART_H
#define UART_H

/*!***************************************************************************
 * @defgroup    UART UART:Universal Asynchronous Receiver/Transmitter
 * @ingroup     driver
 * @brief       UART Hardware Layer Module
 * @details     Provides a layer for the UART driver functions.
 *              It uses UART interface with DMA
 *
 *              Example:
 * @code
 *                  UART_Printf("askldfjlsadf");
 * @endcode
 * @code
 *                  UART_SendBuffer(txBuff, sizeof(txBuff));
 * @endcode
 * @addtogroup  UART
 * @{
 *****************************************************************************/
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "api/argus_status.h"
#include "main.h"

/*!***************************************************************************
 * @brief   Initialize the Universal Asynchronous Receiver/Transmitter
 *          (UART or LPSCI) bus and DMA module
 * @param   -
 * @return  Returns the \link #status_t status\endlink (#STATUS_OK on success).
 *****************************************************************************/
status_t UART_Init(UART_HandleTypeDef* const m_huart);


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
status_t UART_SendBuffer(uint8_t const *txBuff, size_t txSize);


/*! @} */
#endif /* UART_H */
