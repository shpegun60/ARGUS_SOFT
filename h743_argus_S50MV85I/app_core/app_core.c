/*
 * app_core.cpp
 *
 *  Created on: Jun 6, 2024
 *      Author: admin
 */

#include "app_core.h"
#include "main.h"

#include "examples/examples.h"
#include "platform/argus_print.h" // declaration of print()
#include "board.h"


/*!***************************************************************************
 * @brief   Application entry point.
 *
 * @details The main function of the program, called after startup code
 *          This function should never be exited.
 *
 * @return  Never returns anything...
 *****************************************************************************/

void HandleError(status_t status, bool stop, char const * msg)
{
    /* Check for status < 0 and print message and halt the program execution. */
    if (status < STATUS_OK)
    {
        print("ERROR (%d): %s\n", status, msg);
        if (stop)
        {
            print(" --> Stopped execution due to a critical issue!\n"
                  "     Check the hardware end reset the board!\n");
            while (1) __asm("nop"); // stop!
        }
    }
}

void app_main(void)
{
    /* Initialize the platform hardware including the required peripherals
     * for the API. */
    status_t status = Board_Init();

//    while(1) {
//    	 print(" --> Stopped execution due to a critical issue!\n"
//    	                  "     Check the hardware end reset the board!\n");
//    	HAL_Delay(1000);
//    }


    HandleError(status, true, "Board initialization failed!");

    /* Pass control to the example code. */
    ExampleMain();

    /* The examples should never return... */
    for (;;);
}
