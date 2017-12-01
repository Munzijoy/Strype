################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mbed-os/drivers/AnalogIn.cpp \
../mbed-os/drivers/BusIn.cpp \
../mbed-os/drivers/BusInOut.cpp \
../mbed-os/drivers/BusOut.cpp \
../mbed-os/drivers/CAN.cpp \
../mbed-os/drivers/Ethernet.cpp \
../mbed-os/drivers/FlashIAP.cpp \
../mbed-os/drivers/I2C.cpp \
../mbed-os/drivers/I2CSlave.cpp \
../mbed-os/drivers/InterruptIn.cpp \
../mbed-os/drivers/InterruptManager.cpp \
../mbed-os/drivers/RawSerial.cpp \
../mbed-os/drivers/SPI.cpp \
../mbed-os/drivers/SPISlave.cpp \
../mbed-os/drivers/Serial.cpp \
../mbed-os/drivers/SerialBase.cpp \
../mbed-os/drivers/Ticker.cpp \
../mbed-os/drivers/Timeout.cpp \
../mbed-os/drivers/Timer.cpp \
../mbed-os/drivers/TimerEvent.cpp \
../mbed-os/drivers/UARTSerial.cpp 

OBJS += \
./mbed-os/drivers/AnalogIn.o \
./mbed-os/drivers/BusIn.o \
./mbed-os/drivers/BusInOut.o \
./mbed-os/drivers/BusOut.o \
./mbed-os/drivers/CAN.o \
./mbed-os/drivers/Ethernet.o \
./mbed-os/drivers/FlashIAP.o \
./mbed-os/drivers/I2C.o \
./mbed-os/drivers/I2CSlave.o \
./mbed-os/drivers/InterruptIn.o \
./mbed-os/drivers/InterruptManager.o \
./mbed-os/drivers/RawSerial.o \
./mbed-os/drivers/SPI.o \
./mbed-os/drivers/SPISlave.o \
./mbed-os/drivers/Serial.o \
./mbed-os/drivers/SerialBase.o \
./mbed-os/drivers/Ticker.o \
./mbed-os/drivers/Timeout.o \
./mbed-os/drivers/Timer.o \
./mbed-os/drivers/TimerEvent.o \
./mbed-os/drivers/UARTSerial.o 

CPP_DEPS += \
./mbed-os/drivers/AnalogIn.d \
./mbed-os/drivers/BusIn.d \
./mbed-os/drivers/BusInOut.d \
./mbed-os/drivers/BusOut.d \
./mbed-os/drivers/CAN.d \
./mbed-os/drivers/Ethernet.d \
./mbed-os/drivers/FlashIAP.d \
./mbed-os/drivers/I2C.d \
./mbed-os/drivers/I2CSlave.d \
./mbed-os/drivers/InterruptIn.d \
./mbed-os/drivers/InterruptManager.d \
./mbed-os/drivers/RawSerial.d \
./mbed-os/drivers/SPI.d \
./mbed-os/drivers/SPISlave.d \
./mbed-os/drivers/Serial.d \
./mbed-os/drivers/SerialBase.d \
./mbed-os/drivers/Ticker.d \
./mbed-os/drivers/Timeout.d \
./mbed-os/drivers/Timer.d \
./mbed-os/drivers/TimerEvent.d \
./mbed-os/drivers/UARTSerial.d 


# Each subdirectory must supply rules for building sources it contributes
mbed-os/drivers/%.o: ../mbed-os/drivers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -ffunction-sections -fdata-sections -fno-builtin -funsigned-char -fno-delete-null-pointer-checks -fomit-frame-pointer -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers  -g3 -DTARGET_STM32F429xx -DDEVICE_SPISLAVE=1 -D__MBED__=1 -D__FPU_PRESENT=1 -DTRANSACTION_QUEUE_SIZE_SPI=2 -DUSBHOST_OTHER -DDEVICE_PORTINOUT=1 -DTARGET_RTOS_M4_M7 -DDEVICE_RTC=1 -DTOOLCHAIN_object -DDEVICE_SERIAL_ASYNCH=1 -DTARGET_STM32F4 -D__CMSIS_RTOS -DTOOLCHAIN_GCC -DARM_MATH_CM4 -DTARGET_LIKE_CORTEX_M4 -DTARGET_M4 -DTARGET_UVISOR_UNSUPPORTED -DDEVICE_PORTOUT=1 -DMBED_BUILD_TIMESTAMP=1511263925.01 -DDEVICE_SPI_ASYNCH=1 -DDEVICE_INTERRUPTIN=1 -DTARGET_CORTEX -DTARGET_STM32F429 -DRTC_LSI=1 -D__CORTEX_M4 -DDEVICE_STDIO_MESSAGES=1 -DTARGET_FAMILY_STM32 -DTARGET_DISCO_F429ZI -DDEVICE_PORTIN=1 -DTARGET_RELEASE -DTARGET_STM -DDEVICE_SERIAL_FC=1 -DDEVICE_TRNG=1 -DTARGET_LIKE_MBED -DTARGET_STM32F429ZI -D__MBED_CMSIS_RTOS_CM -DDEVICE_SLEEP=1 -DTOOLCHAIN_GCC_ARM -DDEVICE_SPI=1 -DTARGET_STM32F429xI -DDEVICE_SERIAL=1 -DTARGET_CORTEX_M -DOVERRIDE=virtual -I../. -I../img -I../mbed-os/. -I../mbed-os/features -I../mbed-os/features/frameworks -I../mbed-os/features/frameworks/greentea-client -I../mbed-os/features/frameworks/greentea-client/greentea-client -I../mbed-os/features/frameworks/greentea-client/source -I../mbed-os/features/frameworks/unity -I../mbed-os/features/frameworks/unity/source -I../mbed-os/features/frameworks/unity/unity -I../mbed-os/features/frameworks/utest -I../mbed-os/features/frameworks/utest/source -I../mbed-os/features/frameworks/utest/utest -I../mbed-os/features/mbedtls -I../mbed-os/features/mbedtls/importer -I../mbed-os/features/mbedtls/inc -I../mbed-os/features/mbedtls/inc/mbedtls -I../mbed-os/features/mbedtls/src -I../mbed-os/features/mbedtls/platform -I../mbed-os/features/mbedtls/platform/inc -I../mbed-os/features/mbedtls/platform/src -I../mbed-os/features/mbedtls/targets -I../mbed-os/features/mbedtls/targets/TARGET_STM -I../mbed-os/features/mbedtls/targets/TARGET_STM/TARGET_STM32F4 -I../mbed-os/features/nanostack -I../mbed-os/features/storage -I../mbed-os/features/netsocket -I../mbed-os/features/netsocket/cellular -I../mbed-os/features/netsocket/cellular/generic_modem_driver -I../mbed-os/features/netsocket/cellular/utils -I../mbed-os/features/filesystem -I../mbed-os/features/filesystem/bd -I../mbed-os/features/filesystem/fat -I../mbed-os/features/filesystem/fat/ChaN -I../mbed-os/cmsis -I../mbed-os/cmsis/TARGET_CORTEX_M -I../mbed-os/cmsis/TARGET_CORTEX_M/TOOLCHAIN_GCC -I../mbed-os/cmsis/TOOLCHAIN_GCC -I../mbed-os/drivers -I../mbed-os/events -I../mbed-os/events/equeue -I../mbed-os/rtos -I../mbed-os/rtos/TARGET_CORTEX -I../mbed-os/rtos/TARGET_CORTEX/rtx4 -I../mbed-os/rtos/TARGET_CORTEX/rtx5 -I../mbed-os/rtos/TARGET_CORTEX/rtx5/TARGET_RTOS_M4_M7 -I../mbed-os/rtos/TARGET_CORTEX/rtx5/TARGET_RTOS_M4_M7/TOOLCHAIN_GCC -I../mbed-os/hal -I../mbed-os/hal/storage_abstraction -I../mbed-os/platform -I../mbed-os/targets -I../mbed-os/targets/TARGET_STM -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4 -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/TARGET_DISCO_F429ZI -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/device -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/device/TOOLCHAIN_GCC_ARM -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/device -I../rapidjson/include -I/ -I../esp8266-driver -I../esp8266-driver/ESP8266 -I../Application -I../Application/online-apis -include../mbed_config.h -std=gnu++14 -fabi-version=0 -fno-rtti -Wvla -DMBED_DEBUG -DMBED_TRAP_ERRORS_ENABLED=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


