################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Adrian/Desktop/Projekt\ PMIK/Projects/Src/system_stm32f4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f4xx.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/Projects/Src/system_stm32f4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F410Rx -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/CMSIS/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Lcd_driver/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/KeyPad_4x4/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Circular_buffer/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Timeout/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/UART/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Rtc/inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Drivers/CMSIS/system_stm32f4xx.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


