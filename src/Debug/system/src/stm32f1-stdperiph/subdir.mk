################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/stm32f1-stdperiph/misc.c \
../system/src/stm32f1-stdperiph/stm32f10x_bkp.c \
../system/src/stm32f1-stdperiph/stm32f10x_flash.c \
../system/src/stm32f1-stdperiph/stm32f10x_gpio.c \
../system/src/stm32f1-stdperiph/stm32f10x_pwr.c \
../system/src/stm32f1-stdperiph/stm32f10x_rcc.c \
../system/src/stm32f1-stdperiph/stm32f10x_rtc.c \
../system/src/stm32f1-stdperiph/stm32f10x_spi.c \
../system/src/stm32f1-stdperiph/stm32f10x_usart.c \
../system/src/stm32f1-stdperiph/stm32f10x_wwdg.c 

OBJS += \
./system/src/stm32f1-stdperiph/misc.o \
./system/src/stm32f1-stdperiph/stm32f10x_bkp.o \
./system/src/stm32f1-stdperiph/stm32f10x_flash.o \
./system/src/stm32f1-stdperiph/stm32f10x_gpio.o \
./system/src/stm32f1-stdperiph/stm32f10x_pwr.o \
./system/src/stm32f1-stdperiph/stm32f10x_rcc.o \
./system/src/stm32f1-stdperiph/stm32f10x_rtc.o \
./system/src/stm32f1-stdperiph/stm32f10x_spi.o \
./system/src/stm32f1-stdperiph/stm32f10x_usart.o \
./system/src/stm32f1-stdperiph/stm32f10x_wwdg.o 

C_DEPS += \
./system/src/stm32f1-stdperiph/misc.d \
./system/src/stm32f1-stdperiph/stm32f10x_bkp.d \
./system/src/stm32f1-stdperiph/stm32f10x_flash.d \
./system/src/stm32f1-stdperiph/stm32f10x_gpio.d \
./system/src/stm32f1-stdperiph/stm32f10x_pwr.d \
./system/src/stm32f1-stdperiph/stm32f10x_rcc.d \
./system/src/stm32f1-stdperiph/stm32f10x_rtc.d \
./system/src/stm32f1-stdperiph/stm32f10x_spi.d \
./system/src/stm32f1-stdperiph/stm32f10x_usart.d \
./system/src/stm32f1-stdperiph/stm32f10x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/stm32f1-stdperiph/%.o: ../system/src/stm32f1-stdperiph/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Werror -Wall -Wextra -Wpointer-arith -Wshadow -Wfloat-equal  -g3 -DDEBUG -DUSE_FULL_ASSERT -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTRACE -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


