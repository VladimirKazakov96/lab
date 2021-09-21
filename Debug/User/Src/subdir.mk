################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/adc.c \
../User/Src/adc_utilities.c \
../User/Src/dac.c \
../User/Src/dac_utilities.c \
../User/Src/gpio.c \
../User/Src/main.c \
../User/Src/system_config.c \
../User/Src/usart.c \
../User/Src/usart_utilities.c 

OBJS += \
./User/Src/adc.o \
./User/Src/adc_utilities.o \
./User/Src/dac.o \
./User/Src/dac_utilities.o \
./User/Src/gpio.o \
./User/Src/main.o \
./User/Src/system_config.o \
./User/Src/usart.o \
./User/Src/usart_utilities.o 

C_DEPS += \
./User/Src/adc.d \
./User/Src/adc_utilities.d \
./User/Src/dac.d \
./User/Src/dac_utilities.d \
./User/Src/gpio.d \
./User/Src/main.d \
./User/Src/system_config.d \
./User/Src/usart.d \
./User/Src/usart_utilities.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o: ../User/Src/%.c User/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/STMCubeIDE_Progs/lab/User/Inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

