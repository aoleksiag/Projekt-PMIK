################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/LCD_HD44780/lcd.c 

OBJS += \
./Application/LCD_HD44780/lcd.o 

C_DEPS += \
./Application/LCD_HD44780/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Application/LCD_HD44780/lcd.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/LCD_HD44780/lcd.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L053xx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


