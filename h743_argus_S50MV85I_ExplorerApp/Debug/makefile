################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include app_core/tools/subdir.mk
-include app_core/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Argus_lib/utility/subdir.mk
-include Argus_lib/test/subdir.mk
-include Argus_lib/board/subdir.mk
-include Argus_lib/Xtalk-CLI/subdir.mk
-include Argus_lib/ExplorerApp/tasks/subdir.mk
-include Argus_lib/ExplorerApp/sci/subdir.mk
-include Argus_lib/ExplorerApp/core/subdir.mk
-include Argus_lib/ExplorerApp/api/subdir.mk
-include Argus_lib/ExplorerApp/subdir.mk
-include Argus_lib/ExampleApp/examples/subdir.mk
-include Argus_lib/ExampleApp/debug/subdir.mk
-include Argus_lib/ExampleApp/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := h743_argus_S50MV85I_ExplorerApp
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
h743_argus_S50MV85I_ExplorerApp.elf \

MAP_FILES += \
h743_argus_S50MV85I_ExplorerApp.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
h743_argus_S50MV85I_ExplorerApp.list \


# All Target
all: main-build

# Main-build Target
main-build: h743_argus_S50MV85I_ExplorerApp.elf secondary-outputs

# Tool invocations
h743_argus_S50MV85I_ExplorerApp.elf h743_argus_S50MV85I_ExplorerApp.map: $(OBJS) $(USER_OBJS) C:\Users\admin\Documents\Work\STM32\ARGUS_SOFT\h743_argus_S50MV85I_ExplorerApp\STM32H723ZGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "h743_argus_S50MV85I_ExplorerApp.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\admin\Documents\Work\STM32\ARGUS_SOFT\h743_argus_S50MV85I_ExplorerApp\STM32H723ZGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="h743_argus_S50MV85I_ExplorerApp.map" -Wl,--gc-sections -static -L"C:/Users/admin/Documents/Work/STM32/ARGUS_SOFT/h743_argus_S50MV85I_ExplorerApp/../AFBR-S50-API/AFBR-S50/Lib" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

h743_argus_S50MV85I_ExplorerApp.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "h743_argus_S50MV85I_ExplorerApp.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout h743_argus_S50MV85I_ExplorerApp.elf h743_argus_S50MV85I_ExplorerApp.list h743_argus_S50MV85I_ExplorerApp.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
