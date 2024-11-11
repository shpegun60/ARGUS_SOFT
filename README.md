# Port of Argus lib
https://github.com/Broadcom/AFBR-S50-API <-- original AFBR-S50-API lib
Original documentation site: https://broadcom.github.io/AFBR-S50-API/stm32cubeide.html
To start the program, you need to open a workspace in stm32Cubeide!!!
## Workspace description
### AFBR_S50_Example_F401RE
This is original exapmple on STM32F410RE board for getting data from AFBR-S50 sensor or self calibration.
### AFBR_S50_ExplorerApp_F401RE
This is original exapmple on STM32F410RE board for AFBR-S50 Explorer app proceeding, application to download: https://docs.broadcom.com/docs/12398582
### h743_argus_S50MV85I
Ported version of example app on nucleo-H723 board
If you want to choose number of test, you need go to:  `workspace path\h743_argus_S50MV85I\App\examples\examples.h`
And find in:
`examples.h`
```cpp
/*! Selector for example:
 *  - 1: 01_simple_example.c: Runs measurements in simplest blocking manner.
 *  - 2: 02_advanced_example.c: Starts measurements automatically from timer interrupt.
 *  - 3: 03_high_speed_example.c: Runs measurements with up to 3000 frames per second.
 *  - 4: 04_multi_device_example.c: Demonstrates the usage of multiple devices per MCU.
 *  - 5: 05_simple_example_debug.c: Demonstrates how to obtain debug information. */
#ifndef API_EXAMPLE
#define API_EXAMPLE 2
#endif
```
For XTALK calibration:
 ```cpp
 /*! Selector for XTALK calibration demo:
 *  - 0: no XTALK calibration is executed.
 *  - 1: XTALK calibration is executed before any API code is executed. */
#ifndef RUN_XTALK_CALIBRATION
#define RUN_XTALK_CALIBRATION 0
#endif
```

