################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Adrian/Desktop/Projekt\ PMIK/Projects/Src/main.c \
C:/Users/Adrian/Desktop/Projekt\ PMIK/Projects/Src/stm32f4xx_hal_msp.c \
C:/Users/Adrian/Desktop/Projekt\ PMIK/Projects/Src/stm32f4xx_it.c 

OBJS += \
./Application/User/main.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_it.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/Projects/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F410Rx -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/CMSIS/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Lcd_driver/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/KeyPad_4x4/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Circular_buffer/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Timeout/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/UART/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Rtc/inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_hal_msp.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/Projects/Src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F410Rx -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/CMSIS/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Lcd_driver/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/KeyPad_4x4/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Circular_buffer/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Timeout/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/UART/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Rtc/inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/stm32f4xx_hal_msp.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_it.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/Projects/Src/stm32f4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F410Rx -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/Drivers/CMSIS/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Lcd_driver/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/KeyPad_4x4/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Circular_buffer/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Timeout/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/UART/inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User" -I"C:/Users/Adrian/Desktop/Projekt PMIK/Projects/SW4STM32/Project/Application/User/Rtc/inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/stm32f4xx_it.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


