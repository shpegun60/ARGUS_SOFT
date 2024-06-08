################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app_core/app_core.c 

C_DEPS += \
./app_core/app_core.d 

OBJS += \
./app_core/app_core.o 


# Each subdirectory must supply rules for building sources it contributes
app_core/%.o app_core/%.su app_core/%.cyclo: ../app_core/%.c app_core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/utility" -I../Core/Inc -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/App" -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/Platform" -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/app_core/tools" -I"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/app_core" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -IC:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I/../AFBR-S50-API/AFBR-S50/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app_core

clean-app_core:
	-$(RM) ./app_core/app_core.cyclo ./app_core/app_core.d ./app_core/app_core.o ./app_core/app_core.su

.PHONY: clean-app_core

