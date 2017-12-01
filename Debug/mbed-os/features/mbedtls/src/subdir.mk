################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mbed-os/features/mbedtls/src/aes.c \
../mbed-os/features/mbedtls/src/aesni.c \
../mbed-os/features/mbedtls/src/arc4.c \
../mbed-os/features/mbedtls/src/asn1parse.c \
../mbed-os/features/mbedtls/src/asn1write.c \
../mbed-os/features/mbedtls/src/base64.c \
../mbed-os/features/mbedtls/src/bignum.c \
../mbed-os/features/mbedtls/src/blowfish.c \
../mbed-os/features/mbedtls/src/camellia.c \
../mbed-os/features/mbedtls/src/ccm.c \
../mbed-os/features/mbedtls/src/certs.c \
../mbed-os/features/mbedtls/src/cipher.c \
../mbed-os/features/mbedtls/src/cipher_wrap.c \
../mbed-os/features/mbedtls/src/cmac.c \
../mbed-os/features/mbedtls/src/ctr_drbg.c \
../mbed-os/features/mbedtls/src/debug.c \
../mbed-os/features/mbedtls/src/des.c \
../mbed-os/features/mbedtls/src/dhm.c \
../mbed-os/features/mbedtls/src/ecdh.c \
../mbed-os/features/mbedtls/src/ecdsa.c \
../mbed-os/features/mbedtls/src/ecjpake.c \
../mbed-os/features/mbedtls/src/ecp.c \
../mbed-os/features/mbedtls/src/ecp_curves.c \
../mbed-os/features/mbedtls/src/entropy.c \
../mbed-os/features/mbedtls/src/entropy_poll.c \
../mbed-os/features/mbedtls/src/error.c \
../mbed-os/features/mbedtls/src/gcm.c \
../mbed-os/features/mbedtls/src/havege.c \
../mbed-os/features/mbedtls/src/hmac_drbg.c \
../mbed-os/features/mbedtls/src/md.c \
../mbed-os/features/mbedtls/src/md2.c \
../mbed-os/features/mbedtls/src/md4.c \
../mbed-os/features/mbedtls/src/md5.c \
../mbed-os/features/mbedtls/src/md_wrap.c \
../mbed-os/features/mbedtls/src/memory_buffer_alloc.c \
../mbed-os/features/mbedtls/src/net_sockets.c \
../mbed-os/features/mbedtls/src/oid.c \
../mbed-os/features/mbedtls/src/padlock.c \
../mbed-os/features/mbedtls/src/pem.c \
../mbed-os/features/mbedtls/src/pk.c \
../mbed-os/features/mbedtls/src/pk_wrap.c \
../mbed-os/features/mbedtls/src/pkcs11.c \
../mbed-os/features/mbedtls/src/pkcs12.c \
../mbed-os/features/mbedtls/src/pkcs5.c \
../mbed-os/features/mbedtls/src/pkparse.c \
../mbed-os/features/mbedtls/src/pkwrite.c \
../mbed-os/features/mbedtls/src/platform.c \
../mbed-os/features/mbedtls/src/ripemd160.c \
../mbed-os/features/mbedtls/src/rsa.c \
../mbed-os/features/mbedtls/src/sha1.c \
../mbed-os/features/mbedtls/src/sha256.c \
../mbed-os/features/mbedtls/src/sha512.c \
../mbed-os/features/mbedtls/src/ssl_cache.c \
../mbed-os/features/mbedtls/src/ssl_ciphersuites.c \
../mbed-os/features/mbedtls/src/ssl_cli.c \
../mbed-os/features/mbedtls/src/ssl_cookie.c \
../mbed-os/features/mbedtls/src/ssl_srv.c \
../mbed-os/features/mbedtls/src/ssl_ticket.c \
../mbed-os/features/mbedtls/src/ssl_tls.c \
../mbed-os/features/mbedtls/src/threading.c \
../mbed-os/features/mbedtls/src/timing.c \
../mbed-os/features/mbedtls/src/version.c \
../mbed-os/features/mbedtls/src/version_features.c \
../mbed-os/features/mbedtls/src/x509.c \
../mbed-os/features/mbedtls/src/x509_create.c \
../mbed-os/features/mbedtls/src/x509_crl.c \
../mbed-os/features/mbedtls/src/x509_crt.c \
../mbed-os/features/mbedtls/src/x509_csr.c \
../mbed-os/features/mbedtls/src/x509write_crt.c \
../mbed-os/features/mbedtls/src/x509write_csr.c \
../mbed-os/features/mbedtls/src/xtea.c 

OBJS += \
./mbed-os/features/mbedtls/src/aes.o \
./mbed-os/features/mbedtls/src/aesni.o \
./mbed-os/features/mbedtls/src/arc4.o \
./mbed-os/features/mbedtls/src/asn1parse.o \
./mbed-os/features/mbedtls/src/asn1write.o \
./mbed-os/features/mbedtls/src/base64.o \
./mbed-os/features/mbedtls/src/bignum.o \
./mbed-os/features/mbedtls/src/blowfish.o \
./mbed-os/features/mbedtls/src/camellia.o \
./mbed-os/features/mbedtls/src/ccm.o \
./mbed-os/features/mbedtls/src/certs.o \
./mbed-os/features/mbedtls/src/cipher.o \
./mbed-os/features/mbedtls/src/cipher_wrap.o \
./mbed-os/features/mbedtls/src/cmac.o \
./mbed-os/features/mbedtls/src/ctr_drbg.o \
./mbed-os/features/mbedtls/src/debug.o \
./mbed-os/features/mbedtls/src/des.o \
./mbed-os/features/mbedtls/src/dhm.o \
./mbed-os/features/mbedtls/src/ecdh.o \
./mbed-os/features/mbedtls/src/ecdsa.o \
./mbed-os/features/mbedtls/src/ecjpake.o \
./mbed-os/features/mbedtls/src/ecp.o \
./mbed-os/features/mbedtls/src/ecp_curves.o \
./mbed-os/features/mbedtls/src/entropy.o \
./mbed-os/features/mbedtls/src/entropy_poll.o \
./mbed-os/features/mbedtls/src/error.o \
./mbed-os/features/mbedtls/src/gcm.o \
./mbed-os/features/mbedtls/src/havege.o \
./mbed-os/features/mbedtls/src/hmac_drbg.o \
./mbed-os/features/mbedtls/src/md.o \
./mbed-os/features/mbedtls/src/md2.o \
./mbed-os/features/mbedtls/src/md4.o \
./mbed-os/features/mbedtls/src/md5.o \
./mbed-os/features/mbedtls/src/md_wrap.o \
./mbed-os/features/mbedtls/src/memory_buffer_alloc.o \
./mbed-os/features/mbedtls/src/net_sockets.o \
./mbed-os/features/mbedtls/src/oid.o \
./mbed-os/features/mbedtls/src/padlock.o \
./mbed-os/features/mbedtls/src/pem.o \
./mbed-os/features/mbedtls/src/pk.o \
./mbed-os/features/mbedtls/src/pk_wrap.o \
./mbed-os/features/mbedtls/src/pkcs11.o \
./mbed-os/features/mbedtls/src/pkcs12.o \
./mbed-os/features/mbedtls/src/pkcs5.o \
./mbed-os/features/mbedtls/src/pkparse.o \
./mbed-os/features/mbedtls/src/pkwrite.o \
./mbed-os/features/mbedtls/src/platform.o \
./mbed-os/features/mbedtls/src/ripemd160.o \
./mbed-os/features/mbedtls/src/rsa.o \
./mbed-os/features/mbedtls/src/sha1.o \
./mbed-os/features/mbedtls/src/sha256.o \
./mbed-os/features/mbedtls/src/sha512.o \
./mbed-os/features/mbedtls/src/ssl_cache.o \
./mbed-os/features/mbedtls/src/ssl_ciphersuites.o \
./mbed-os/features/mbedtls/src/ssl_cli.o \
./mbed-os/features/mbedtls/src/ssl_cookie.o \
./mbed-os/features/mbedtls/src/ssl_srv.o \
./mbed-os/features/mbedtls/src/ssl_ticket.o \
./mbed-os/features/mbedtls/src/ssl_tls.o \
./mbed-os/features/mbedtls/src/threading.o \
./mbed-os/features/mbedtls/src/timing.o \
./mbed-os/features/mbedtls/src/version.o \
./mbed-os/features/mbedtls/src/version_features.o \
./mbed-os/features/mbedtls/src/x509.o \
./mbed-os/features/mbedtls/src/x509_create.o \
./mbed-os/features/mbedtls/src/x509_crl.o \
./mbed-os/features/mbedtls/src/x509_crt.o \
./mbed-os/features/mbedtls/src/x509_csr.o \
./mbed-os/features/mbedtls/src/x509write_crt.o \
./mbed-os/features/mbedtls/src/x509write_csr.o \
./mbed-os/features/mbedtls/src/xtea.o 

C_DEPS += \
./mbed-os/features/mbedtls/src/aes.d \
./mbed-os/features/mbedtls/src/aesni.d \
./mbed-os/features/mbedtls/src/arc4.d \
./mbed-os/features/mbedtls/src/asn1parse.d \
./mbed-os/features/mbedtls/src/asn1write.d \
./mbed-os/features/mbedtls/src/base64.d \
./mbed-os/features/mbedtls/src/bignum.d \
./mbed-os/features/mbedtls/src/blowfish.d \
./mbed-os/features/mbedtls/src/camellia.d \
./mbed-os/features/mbedtls/src/ccm.d \
./mbed-os/features/mbedtls/src/certs.d \
./mbed-os/features/mbedtls/src/cipher.d \
./mbed-os/features/mbedtls/src/cipher_wrap.d \
./mbed-os/features/mbedtls/src/cmac.d \
./mbed-os/features/mbedtls/src/ctr_drbg.d \
./mbed-os/features/mbedtls/src/debug.d \
./mbed-os/features/mbedtls/src/des.d \
./mbed-os/features/mbedtls/src/dhm.d \
./mbed-os/features/mbedtls/src/ecdh.d \
./mbed-os/features/mbedtls/src/ecdsa.d \
./mbed-os/features/mbedtls/src/ecjpake.d \
./mbed-os/features/mbedtls/src/ecp.d \
./mbed-os/features/mbedtls/src/ecp_curves.d \
./mbed-os/features/mbedtls/src/entropy.d \
./mbed-os/features/mbedtls/src/entropy_poll.d \
./mbed-os/features/mbedtls/src/error.d \
./mbed-os/features/mbedtls/src/gcm.d \
./mbed-os/features/mbedtls/src/havege.d \
./mbed-os/features/mbedtls/src/hmac_drbg.d \
./mbed-os/features/mbedtls/src/md.d \
./mbed-os/features/mbedtls/src/md2.d \
./mbed-os/features/mbedtls/src/md4.d \
./mbed-os/features/mbedtls/src/md5.d \
./mbed-os/features/mbedtls/src/md_wrap.d \
./mbed-os/features/mbedtls/src/memory_buffer_alloc.d \
./mbed-os/features/mbedtls/src/net_sockets.d \
./mbed-os/features/mbedtls/src/oid.d \
./mbed-os/features/mbedtls/src/padlock.d \
./mbed-os/features/mbedtls/src/pem.d \
./mbed-os/features/mbedtls/src/pk.d \
./mbed-os/features/mbedtls/src/pk_wrap.d \
./mbed-os/features/mbedtls/src/pkcs11.d \
./mbed-os/features/mbedtls/src/pkcs12.d \
./mbed-os/features/mbedtls/src/pkcs5.d \
./mbed-os/features/mbedtls/src/pkparse.d \
./mbed-os/features/mbedtls/src/pkwrite.d \
./mbed-os/features/mbedtls/src/platform.d \
./mbed-os/features/mbedtls/src/ripemd160.d \
./mbed-os/features/mbedtls/src/rsa.d \
./mbed-os/features/mbedtls/src/sha1.d \
./mbed-os/features/mbedtls/src/sha256.d \
./mbed-os/features/mbedtls/src/sha512.d \
./mbed-os/features/mbedtls/src/ssl_cache.d \
./mbed-os/features/mbedtls/src/ssl_ciphersuites.d \
./mbed-os/features/mbedtls/src/ssl_cli.d \
./mbed-os/features/mbedtls/src/ssl_cookie.d \
./mbed-os/features/mbedtls/src/ssl_srv.d \
./mbed-os/features/mbedtls/src/ssl_ticket.d \
./mbed-os/features/mbedtls/src/ssl_tls.d \
./mbed-os/features/mbedtls/src/threading.d \
./mbed-os/features/mbedtls/src/timing.d \
./mbed-os/features/mbedtls/src/version.d \
./mbed-os/features/mbedtls/src/version_features.d \
./mbed-os/features/mbedtls/src/x509.d \
./mbed-os/features/mbedtls/src/x509_create.d \
./mbed-os/features/mbedtls/src/x509_crl.d \
./mbed-os/features/mbedtls/src/x509_crt.d \
./mbed-os/features/mbedtls/src/x509_csr.d \
./mbed-os/features/mbedtls/src/x509write_crt.d \
./mbed-os/features/mbedtls/src/x509write_csr.d \
./mbed-os/features/mbedtls/src/xtea.d 


# Each subdirectory must supply rules for building sources it contributes
mbed-os/features/mbedtls/src/%.o: ../mbed-os/features/mbedtls/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -ffunction-sections -fdata-sections -fno-builtin -funsigned-char -fno-delete-null-pointer-checks -fomit-frame-pointer -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers  -g3 -DTARGET_STM32F429xx -DDEVICE_SPISLAVE=1 -D__MBED__=1 -DDEVICE_I2CSLAVE=1 -D__FPU_PRESENT=1 -DTRANSACTION_QUEUE_SIZE_SPI=2 -DUSBHOST_OTHER -DDEVICE_PORTINOUT=1 -DTARGET_RTOS_M4_M7 -DDEVICE_RTC=1 -DTOOLCHAIN_object -DDEVICE_SERIAL_ASYNCH=1 -DTARGET_STM32F4 -D__CMSIS_RTOS -DTOOLCHAIN_GCC -DDEVICE_CAN=1 -DARM_MATH_CM4 -DDEVICE_I2C_ASYNCH=1 -DTARGET_LIKE_CORTEX_M4 -DDEVICE_ANALOGOUT=1 -DTARGET_M4 -DTARGET_UVISOR_UNSUPPORTED -DDEVICE_PORTOUT=1 -DMBED_BUILD_TIMESTAMP=1511263925.01 -DDEVICE_SPI_ASYNCH=1 -DDEVICE_PWMOUT=1 -DDEVICE_INTERRUPTIN=1 -DTARGET_CORTEX -DDEVICE_I2C=1 -DTARGET_STM32F429 -DRTC_LSI=1 -D__CORTEX_M4 -DDEVICE_STDIO_MESSAGES=1 -DTARGET_FAMILY_STM32 -DTARGET_DISCO_F429ZI -DDEVICE_PORTIN=1 -DTARGET_RELEASE -DTARGET_STM -DDEVICE_SERIAL_FC=1 -DDEVICE_TRNG=1 -DTARGET_LIKE_MBED -DTARGET_STM32F429ZI -D__MBED_CMSIS_RTOS_CM -DDEVICE_SLEEP=1 -DTOOLCHAIN_GCC_ARM -DDEVICE_SPI=1 -DTARGET_STM32F429xI -DDEVICE_ANALOGIN=1 -DDEVICE_SERIAL=1 -DDEVICE_FLASH=1 -DTARGET_CORTEX_M -I../. -I../img -I../mbed-os/. -I../mbed-os/features -I../mbed-os/features/frameworks -I../mbed-os/features/frameworks/greentea-client -I../mbed-os/features/frameworks/greentea-client/greentea-client -I../mbed-os/features/frameworks/greentea-client/source -I../mbed-os/features/frameworks/unity -I../mbed-os/features/frameworks/unity/source -I../mbed-os/features/frameworks/unity/unity -I../mbed-os/features/frameworks/utest -I../mbed-os/features/frameworks/utest/source -I../mbed-os/features/frameworks/utest/utest -I../mbed-os/features/mbedtls -I../mbed-os/features/mbedtls/importer -I../mbed-os/features/mbedtls/inc -I../mbed-os/features/mbedtls/inc/mbedtls -I../mbed-os/features/mbedtls/src -I../mbed-os/features/mbedtls/platform -I../mbed-os/features/mbedtls/platform/inc -I../mbed-os/features/mbedtls/platform/src -I../mbed-os/features/mbedtls/targets -I../mbed-os/features/mbedtls/targets/TARGET_STM -I../mbed-os/features/mbedtls/targets/TARGET_STM/TARGET_STM32F4 -I../mbed-os/features/nanostack -I../mbed-os/features/storage -I../mbed-os/features/netsocket -I../mbed-os/features/netsocket/cellular -I../mbed-os/features/netsocket/cellular/generic_modem_driver -I../mbed-os/features/netsocket/cellular/utils -I../mbed-os/features/filesystem -I../mbed-os/features/filesystem/bd -I../mbed-os/features/filesystem/fat -I../mbed-os/features/filesystem/fat/ChaN -I../mbed-os/cmsis -I../mbed-os/cmsis/TARGET_CORTEX_M -I../mbed-os/cmsis/TARGET_CORTEX_M/TOOLCHAIN_GCC -I../mbed-os/cmsis/TOOLCHAIN_GCC -I../mbed-os/drivers -I../mbed-os/events -I../mbed-os/events/equeue -I../mbed-os/rtos -I../mbed-os/rtos/TARGET_CORTEX -I../mbed-os/rtos/TARGET_CORTEX/rtx4 -I../mbed-os/rtos/TARGET_CORTEX/rtx5 -I../mbed-os/rtos/TARGET_CORTEX/rtx5/TARGET_RTOS_M4_M7 -I../mbed-os/rtos/TARGET_CORTEX/rtx5/TARGET_RTOS_M4_M7/TOOLCHAIN_GCC -I../mbed-os/hal -I../mbed-os/hal/storage_abstraction -I../mbed-os/platform -I../mbed-os/targets -I../mbed-os/targets/TARGET_STM -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4 -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/TARGET_DISCO_F429ZI -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/device -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F429xI/device/TOOLCHAIN_GCC_ARM -I../mbed-os/targets/TARGET_STM/TARGET_STM32F4/device -I../ -I../rapidjson/include -include../mbed_config.h -std=gnu99 -DMBED_DEBUG -DMBED_TRAP_ERRORS_ENABLED=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


