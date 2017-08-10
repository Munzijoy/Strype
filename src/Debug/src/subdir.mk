################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Delay.cpp \
../src/HW_IRQ.cpp \
../src/HW_RCC.cpp \
../src/HW_RTC.cpp \
../src/HW_SPI.cpp \
../src/LedWrapper.cpp \
../src/MAX7219.cpp \
../src/main.cpp 

OBJS += \
./src/Delay.o \
./src/HW_IRQ.o \
./src/HW_RCC.o \
./src/HW_RTC.o \
./src/HW_SPI.o \
./src/LedWrapper.o \
./src/MAX7219.o \
./src/main.o 

CPP_DEPS += \
./src/Delay.d \
./src/HW_IRQ.d \
./src/HW_RCC.d \
./src/HW_RTC.d \
./src/HW_SPI.d \
./src/LedWrapper.d \
./src/MAX7219.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Werror -Wall -Wextra -Wpointer-arith -Wshadow -Wfloat-equal  -g3 -DDEBUG -DUSE_FULL_ASSERT -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTRACE -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -fexceptions -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


