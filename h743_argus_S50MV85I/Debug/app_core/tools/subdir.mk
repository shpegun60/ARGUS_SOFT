################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../app_core/tools/InRangeDetector.cpp \
../app_core/tools/PID.cpp \
../app_core/tools/Stm32ADCregular.cpp \
../app_core/tools/Timerms.cpp \
../app_core/tools/TimingManager.cpp 

OBJS += \
./app_core/tools/InRangeDetector.o \
./app_core/tools/PID.o \
./app_core/tools/Stm32ADCregular.o \
./app_core/tools/Timerms.o \
./app_core/tools/TimingManager.o 

CPP_DEPS += \
./app_core/tools/InRangeDetector.d \
./app_core/tools/PID.d \
./app_core/tools/Stm32ADCregular.d \
./app_core/tools/Timerms.d \
./app_core/tools/TimingManager.d 


# Each subdirectory must supply rules for building sources it contributes
app_core/tools/%.o app_core/tools/%.su app_core/tools/%.cyclo: ../app_core/tools/%.cpp app_core/tools/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/utility" -I../Core/Inc -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/../AFBR-S50-API/AFBR-S50/Include" -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/App" -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/Platform" -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/app_core/tools" -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/app_core" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app_core-2f-tools

clean-app_core-2f-tools:
	-$(RM) ./app_core/tools/InRangeDetector.cyclo ./app_core/tools/InRangeDetector.d ./app_core/tools/InRangeDetector.o ./app_core/tools/InRangeDetector.su ./app_core/tools/PID.cyclo ./app_core/tools/PID.d ./app_core/tools/PID.o ./app_core/tools/PID.su ./app_core/tools/Stm32ADCregular.cyclo ./app_core/tools/Stm32ADCregular.d ./app_core/tools/Stm32ADCregular.o ./app_core/tools/Stm32ADCregular.su ./app_core/tools/Timerms.cyclo ./app_core/tools/Timerms.d ./app_core/tools/Timerms.o ./app_core/tools/Timerms.su ./app_core/tools/TimingManager.cyclo ./app_core/tools/TimingManager.d ./app_core/tools/TimingManager.o ./app_core/tools/TimingManager.su

.PHONY: clean-app_core-2f-tools

