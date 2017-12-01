################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mbed-os/targets/TARGET_STM/TARGET_STM32F4/device/subdir.mk
-include mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/device/TOOLCHAIN_GCC_ARM/subdir.mk
-include mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/device/subdir.mk
-include mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/TARGET_DISCO_F429ZI/subdir.mk
-include mbed-os/targets/TARGET_STM/TARGET_STM32F4/subdir.mk
-include mbed-os/targets/TARGET_STM/subdir.mk
-include mbed-os/rtos/TARGET_CORTEX/rtx5/TARGET_RTOS_M4_M7/TOOLCHAIN_GCC/subdir.mk
-include mbed-os/rtos/TARGET_CORTEX/rtx5/subdir.mk
-include mbed-os/rtos/TARGET_CORTEX/rtx4/subdir.mk
-include mbed-os/rtos/TARGET_CORTEX/subdir.mk
-include mbed-os/rtos/subdir.mk
-include mbed-os/platform/subdir.mk
-include mbed-os/hal/subdir.mk
-include mbed-os/features/netsocket/cellular/generic_modem_driver/subdir.mk
-include mbed-os/features/netsocket/subdir.mk
-include mbed-os/events/equeue/subdir.mk
-include mbed-os/events/subdir.mk
-include mbed-os/drivers/subdir.mk
-include esp8266-driver/ESP8266/subdir.mk
-include esp8266-driver/subdir.mk
-include Application/online-apis/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
Strype_v2.bin \

SECONDARY_SIZE += \
Strype_v2.siz \


# All Target
all: Strype_v2.elf secondary-outputs

# Tool invocations
Strype_v2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -ffunction-sections -fdata-sections -fno-builtin -funsigned-char -fno-delete-null-pointer-checks -fomit-frame-pointer -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers  -g3 -T "D:\persoenliches\Strype_v2\mbed-os\targets\TARGET_STM\TARGET_STM32F4\TARGET_STM32F429xI\device\TOOLCHAIN_GCC_ARM\STM32F429xI.ld" -Xlinker --gc-sections -Xlinker --wrap=main -Xlinker --wrap=_malloc_r -Xlinker --wrap=_free_r -Xlinker --wrap=_realloc_r -Xlinker --wrap=_memalign_r -Xlinker --wrap=_calloc_r -Xlinker --wrap=exit -Xlinker --wrap=atexit -Wl,-Map,"Strype_v2.map" -DMBED_DEBUG -DMBED_TRAP_ERRORS_ENABLED=1 -Wl,-n -Wl,--start-group -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys -Wl,--end-group -o "Strype_v2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Strype_v2.bin: Strype_v2.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O binary "Strype_v2.elf"  "Strype_v2.bin"
	@echo 'Finished building: $@'
	@echo ' '

Strype_v2.siz: Strype_v2.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "Strype_v2.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) Strype_v2.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
