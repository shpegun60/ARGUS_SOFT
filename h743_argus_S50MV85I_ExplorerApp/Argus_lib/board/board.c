/*************************************************************************//**
 * @file
 * @brief       This file is part of the STM32F401RE platform layer.
 * @details     This file provides generic board abstraction.
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

#include "main.h"


#include "board.h"
#include "board_config.h"
#include "s2pi.h"
#include "uart.h"
#include "timer.h"

#include "utility/debug.h" // declaration of print() and error_log()
#include "api/argus_api.h"

status_t Board_Init(void)
{
	/* Initialize timer required by the API. */
	Timer_Init();

	/* Initialize UART for print functionality. */
	status_t status = UART_Init();
	if (status < STATUS_OK) {
		error_log("UART driver initialization failed, error code: %d", status);
		return status;
	}

	/* Initialize the S2PI hardware required by the API. */
	status = S2PI_Init(SPI_DEFAULT_SLAVE, SPI_BAUDRATE);
	if (status < STATUS_OK) {
		error_log("S2PI driver initialization failed, error code: %d", status);
		return status;
	}
	//
	//    /* Initialize the Flash driver module. */
	//    status = Flash_Init();
	//    if (status < STATUS_OK)
	//    {
	//        error_log("Flash driver initialization failed, error code: %d", status);
	//        return status;
	//    }
	//

	return STATUS_OK;
}

void Board_Reset(void)
{
	NVIC_SystemReset();
}


void Argus_GetCrosstalkVectorTable_Callback(argus_cal_xtalk_table_t * xtalk,
                                            argus_mode_t const mode)
{
	memset(xtalk, 0, sizeof(argus_cal_xtalk_table_t));

	// Set crosstalk vectors in Q11.4 format.
	// Note on dual-frequency frame index: 0 = A-Frame; 1 = B-Frame
//	xtalk->FrameA[0][0].dS = -21143.04;	xtalk->FrameA[0][0].dC = -15787.04;
//	xtalk->FrameA[0][1].dS = -24057.92;	xtalk->FrameA[0][1].dC = -13886.08;
//	xtalk->FrameA[0][2].dS = -29158.08;	xtalk->FrameA[0][2].dC = -9473.92;
//	xtalk->FrameA[0][3].dS = -28344.96;	xtalk->FrameA[0][3].dC = -9822.08;
//	xtalk->FrameA[1][0].dS = -24447.04;	xtalk->FrameA[1][0].dC = -14451.04;
//	xtalk->FrameA[1][1].dS = -27952.96;	xtalk->FrameA[1][1].dC = -12822.08;
//	xtalk->FrameA[1][2].dS = -31723.04;	xtalk->FrameA[1][2].dC = -8751.04;
//	xtalk->FrameA[1][3].dS = -30780;	xtalk->FrameA[1][3].dC = -9300.96;
//	xtalk->FrameA[2][0].dS = -28081.92;	xtalk->FrameA[2][0].dC = -13212;
//	xtalk->FrameA[2][1].dS = -29807.04;	xtalk->FrameA[2][1].dC = -12318.08;
//	xtalk->FrameA[2][2].dS = -32432.96;	xtalk->FrameA[2][2].dC = -9028.96;
//	xtalk->FrameA[2][3].dS = -32000;	xtalk->FrameA[2][3].dC = -8689.92;
//	xtalk->FrameA[3][0].dS = -29104;	xtalk->FrameA[3][0].dC = -13215.04;
//	xtalk->FrameA[3][1].dS = -31056;	xtalk->FrameA[3][1].dC = -12091.04;
//	xtalk->FrameA[3][2].dS = 32096;	xtalk->FrameA[3][2].dC = -9436;
//	xtalk->FrameA[3][3].dS = 31184.96;	xtalk->FrameA[3][3].dC = -8552.96;
//	xtalk->FrameA[4][0].dS = -28726.08;	xtalk->FrameA[4][0].dC = -15659.04;
//	xtalk->FrameA[4][1].dS = -31460;	xtalk->FrameA[4][1].dC = -14150.08;
//	xtalk->FrameA[4][2].dS = 30132.96;	xtalk->FrameA[4][2].dC = -8583.04;
//	xtalk->FrameA[4][3].dS = 31513.92;	xtalk->FrameA[4][3].dC = -8518.08;
//	xtalk->FrameA[5][0].dS = -29824.96;	xtalk->FrameA[5][0].dC = -14788.96;
//	xtalk->FrameA[5][1].dS = 31388;	xtalk->FrameA[5][1].dC = -10232.96;
//	xtalk->FrameA[5][2].dS = 27824;	xtalk->FrameA[5][2].dC = -5167.04;
//	xtalk->FrameA[5][3].dS = 31864.96;	xtalk->FrameA[5][3].dC = -9728;
//	xtalk->FrameA[6][0].dS = 31744;	xtalk->FrameA[6][0].dC = -10974.08;
//	xtalk->FrameA[6][1].dS = 30241.92;	xtalk->FrameA[6][1].dC = -10408.96;
//	xtalk->FrameA[6][2].dS = 29135.04;	xtalk->FrameA[6][2].dC = -7308.96;
//	xtalk->FrameA[6][3].dS = 30984.96;	xtalk->FrameA[6][3].dC = -8561.92;
//	xtalk->FrameA[7][0].dS = 31934.08;	xtalk->FrameA[7][0].dC = -9240.96;
//	xtalk->FrameA[7][1].dS = 30683.04;	xtalk->FrameA[7][1].dC = -9651.04;
//	xtalk->FrameA[7][2].dS = 29764;	xtalk->FrameA[7][2].dC = -7276.96;
//	xtalk->FrameA[7][3].dS = 30404;	xtalk->FrameA[7][3].dC = -7520;
//	xtalk->FrameB[0][0].dS = 23816;	xtalk->FrameB[0][0].dC = -7720.96;
//	xtalk->FrameB[0][1].dS = 20886.08;	xtalk->FrameB[0][1].dC = -4439.04;
//	xtalk->FrameB[0][2].dS = 18540.96;	xtalk->FrameB[0][2].dC = -335.04;
//	xtalk->FrameB[0][3].dS = 18612;	xtalk->FrameB[0][3].dC = -4.96;
//	xtalk->FrameB[1][0].dS = 21752.96;	xtalk->FrameB[1][0].dC = -6881.92;
//	xtalk->FrameB[1][1].dS = 19295.04;	xtalk->FrameB[1][1].dC = -5072;
//	xtalk->FrameB[1][2].dS = 17542.08;	xtalk->FrameB[1][2].dC = -444;
//	xtalk->FrameB[1][3].dS = 18158.08;	xtalk->FrameB[1][3].dC = -944;
//	xtalk->FrameB[2][0].dS = 19604;	xtalk->FrameB[2][0].dC = -6232.96;
//	xtalk->FrameB[2][1].dS = 18212;	xtalk->FrameB[2][1].dC = -4920.96;
//	xtalk->FrameB[2][2].dS = 17630.08;	xtalk->FrameB[2][2].dC = -1337.92;
//	xtalk->FrameB[2][3].dS = 17620;	xtalk->FrameB[2][3].dC = -691.04;
//	xtalk->FrameB[3][0].dS = 18841.92;	xtalk->FrameB[3][0].dC = -6376;
//	xtalk->FrameB[3][1].dS = 17238.08;	xtalk->FrameB[3][1].dC = -4840;
//	xtalk->FrameB[3][2].dS = 16902.08;	xtalk->FrameB[3][2].dC = -1880.96;
//	xtalk->FrameB[3][3].dS = 16643.04;	xtalk->FrameB[3][3].dC = -1435.04;
//	xtalk->FrameB[4][0].dS = 18888;	xtalk->FrameB[4][0].dC = -9144.96;
//	xtalk->FrameB[4][1].dS = 17801.92;	xtalk->FrameB[4][1].dC = -9126.08;
//	xtalk->FrameB[4][2].dS = 17096;	xtalk->FrameB[4][2].dC = -4830.08;
//	xtalk->FrameB[4][3].dS = 16855.04;	xtalk->FrameB[4][3].dC = -1486.08;
//	xtalk->FrameB[5][0].dS = 18363.04;	xtalk->FrameB[5][0].dC = -8340.96;
//	xtalk->FrameB[5][1].dS = 16279.04;	xtalk->FrameB[5][1].dC = -4528;
//	xtalk->FrameB[5][2].dS = 15224.96;	xtalk->FrameB[5][2].dC = 248.96;
//	xtalk->FrameB[5][3].dS = 17377.92;	xtalk->FrameB[5][3].dC = -3923.04;
//	xtalk->FrameB[6][0].dS = 16004;	xtalk->FrameB[6][0].dC = -4439.04;
//	xtalk->FrameB[6][1].dS = 14865.92;	xtalk->FrameB[6][1].dC = -3304.96;
//	xtalk->FrameB[6][2].dS = 14816.96;	xtalk->FrameB[6][2].dC = -110.08;
//	xtalk->FrameB[6][3].dS = 16167.04;	xtalk->FrameB[6][3].dC = -1575.04;
//	xtalk->FrameB[7][0].dS = 16632;	xtalk->FrameB[7][0].dC = -2940.96;
//	xtalk->FrameB[7][1].dS = 15223.04;	xtalk->FrameB[7][1].dC = -2816;
//	xtalk->FrameB[7][2].dS = 15192;	xtalk->FrameB[7][2].dC = -347.04;
//	xtalk->FrameB[7][3].dS = 15680;	xtalk->FrameB[7][3].dC = -612;
}
