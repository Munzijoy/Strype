################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../rapidjson/example/simplereader/simplereader.cpp 

OBJS += \
./rapidjson/example/simplereader/simplereader.o 

CPP_DEPS += \
./rapidjson/example/simplereader/simplereader.d 


# Each subdirectory must supply rules for building sources it contributes
rapidjson/example/simplereader/%.o: ../rapidjson/example/simplereader/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -ffunction-sections -fdata-sections -fno-builtin -funsigned-char -fno-delete-null-pointer-checks -fomit-frame-pointer -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers  -g3 -DTARGET_STM32F429xx -DDEVICE_SPISLAVE=1 -D__MBED__=1 -DDEVICE_I2CSLAVE=1 -D__FPU_PRESENT=1 -DTRANSACTION_QUEUE_SIZE_SPI=2 -DUSBHOST_OTHER -DDEVICE_PORTINOUT=1 -DTARGET_RTOS_M4_M7 -DDEVICE_RTC=1 -DTOOLCHAIN_object -DDEVICE_SERIAL_ASYNCH=1 -DTARGET_STM32F4 -D__CMSIS_RTOS -DTOOLCHAIN_GCC -DDEVICE_CAN=1 -DARM_MATH_CM4 -DDEVICE_I2C_ASYNCH=1 -DTARGET_LIKE_CORTEX_M4 -DDEVICE_ANALOGOUT=1 -DTARGET_M4 -DTARGET_UVISOR_UNSUPPORTED -DDEVICE_PORTOUT=1 -DMBED_BUILD_TIMESTAMP=1511263925.01 -DDEVICE_SPI_ASYNCH=1 -DDEVICE_PWMOUT=1 -DDEVICE_INTERRUPTIN=1 -DTARGET_CORTEX -DDEVICE_I2C=1 -DTARGET_STM32F429 -DRTC_LSI=1 -D__CORTEX_M4 -DDEVICE_STDIO_MESSAGES=1 -DTARGET_FAMILY_STM32 -DTARGET_DISCO_F429ZI -DDEVICE_PORTIN=1 -DTARGET_RELEASE -DTARGET_STM -DDEVICE_SERIAL_FC=1 -DDEVICE_TRNG=1 -DTARGET_LIKE_MBED -DTARGET_STM32F429ZI -D__MBED_CMSIS_RTOS_CM -DDEVICE_SLEEP=1 -DTOOLCHAIN_GCC_ARM -DDEVICE_SPI=1 -DTARGET_STM32F429xI -DDEVICE_ANALOGIN=1 -DDEVICE_SERIAL=1 -DDEVICE_FLASH=1 -DTARGET_CORTEX_M -I"D:/persoenliches/Strype_v2/." -I"D:/persoenliches/Strype_v2/img" -I"D:/persoenliches/Strype_v2/mbed-os/." -I"D:/persoenliches/Strype_v2/mbed-os/features" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks/greentea-client" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks/greentea-client/greentea-client" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks/greentea-client/source" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks/unity" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks/unity/source" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks/unity/unity" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks/utest" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks/utest/source" -I"D:/persoenliches/Strype_v2/mbed-os/features/frameworks/utest/utest" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/importer" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/inc" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/inc/mbedtls" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/src" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/platform" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/platform/inc" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/platform/src" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/targets" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/targets/TARGET_STM" -I"D:/persoenliches/Strype_v2/mbed-os/features/mbedtls/targets/TARGET_STM/TARGET_STM32F4" -I"D:/persoenliches/Strype_v2/mbed-os/features/nanostack" -I"D:/persoenliches/Strype_v2/mbed-os/features/storage" -I"D:/persoenliches/Strype_v2/mbed-os/features/netsocket" -I"D:/persoenliches/Strype_v2/mbed-os/features/netsocket/cellular" -I"D:/persoenliches/Strype_v2/mbed-os/features/netsocket/cellular/generic_modem_driver" -I"D:/persoenliches/Strype_v2/mbed-os/features/netsocket/cellular/utils" -I"D:/persoenliches/Strype_v2/mbed-os/features/filesystem" -I"D:/persoenliches/Strype_v2/mbed-os/features/filesystem/bd" -I"D:/persoenliches/Strype_v2/mbed-os/features/filesystem/fat" -I"D:/persoenliches/Strype_v2/mbed-os/features/filesystem/fat/ChaN" -I"D:/persoenliches/Strype_v2/mbed-os/cmsis" -I"D:/persoenliches/Strype_v2/mbed-os/cmsis/TARGET_CORTEX_M" -I"D:/persoenliches/Strype_v2/mbed-os/cmsis/TARGET_CORTEX_M/TOOLCHAIN_GCC" -I"D:/persoenliches/Strype_v2/mbed-os/cmsis/TOOLCHAIN_GCC" -I"D:/persoenliches/Strype_v2/mbed-os/drivers" -I"D:/persoenliches/Strype_v2/mbed-os/events" -I"D:/persoenliches/Strype_v2/mbed-os/events/equeue" -I"D:/persoenliches/Strype_v2/mbed-os/rtos" -I"D:/persoenliches/Strype_v2/mbed-os/rtos/TARGET_CORTEX" -I"D:/persoenliches/Strype_v2/mbed-os/rtos/TARGET_CORTEX/rtx4" -I"D:/persoenliches/Strype_v2/mbed-os/rtos/TARGET_CORTEX/rtx5" -I"D:/persoenliches/Strype_v2/mbed-os/rtos/TARGET_CORTEX/rtx5/TARGET_RTOS_M4_M7" -I"D:/persoenliches/Strype_v2/mbed-os/rtos/TARGET_CORTEX/rtx5/TARGET_RTOS_M4_M7/TOOLCHAIN_GCC" -I"D:/persoenliches/Strype_v2/mbed-os/hal" -I"D:/persoenliches/Strype_v2/mbed-os/hal/storage_abstraction" -I"D:/persoenliches/Strype_v2/mbed-os/platform" -I"D:/persoenliches/Strype_v2/mbed-os/targets" -I"D:/persoenliches/Strype_v2/mbed-os/targets/TARGET_STM" -I"D:/persoenliches/Strype_v2/mbed-os/targets/TARGET_STM/TARGET_STM32F4" -I"D:/persoenliches/Strype_v2/mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI" -I"D:/persoenliches/Strype_v2/mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/TARGET_DISCO_F429ZI" -I"D:/persoenliches/Strype_v2/mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/device" -I"D:/persoenliches/Strype_v2/mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/device/TOOLCHAIN_GCC_ARM" -I"D:/persoenliches/Strype_v2/mbed-os/targets/TARGET_STM/TARGET_STM32F4/device" -I"D:/persoenliches/Strype_v2/" -include"D:/persoenliches/Strype_v2/mbed_config.h" -std=gnu++98 -fabi-version=0 -fno-exceptions -fno-rtti -Wvla -DMBED_DEBUG -DMBED_TRAP_ERRORS_ENABLED=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

