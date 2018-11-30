################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/Lcd_driver/src/tm_stm32_delay.c \
../Application/User/Lcd_driver/src/tm_stm32_gpio.c \
../Application/User/Lcd_driver/src/tm_stm32_hd44780.c 

OBJS += \
./Application/User/Lcd_driver/src/tm_stm32_delay.o \
./Application/User/Lcd_driver/src/tm_stm32_gpio.o \
./Application/User/Lcd_driver/src/tm_stm32_hd44780.o 

C_DEPS += \
./Application/User/Lcd_driver/src/tm_stm32_delay.d \
./Application/User/Lcd_driver/src/tm_stm32_gpio.d \
./Application/User/Lcd_driver/src/tm_stm32_hd44780.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Lcd_driver/src/%.o: ../Application/User/Lcd_driver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F410Rx -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/Inc" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/Drivers/CMSIS/Include" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/SW4STM32/Project/Application/User/Lcd_driver/inc" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/SW4STM32/Project/Application/User/KeyPad_4x4/inc" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/SW4STM32/Project/Application/User/Circular_buffer/inc" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/SW4STM32/Project/Application/User/Timeout/inc" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/SW4STM32/Project/Application/User/UART/inc" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/SW4STM32/Project/Application/User" -I"C:/Users/Adrian/Desktop/Projekt-PMIK-master/Projects/SW4STM32/Project/Application/User/Rtc/inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


