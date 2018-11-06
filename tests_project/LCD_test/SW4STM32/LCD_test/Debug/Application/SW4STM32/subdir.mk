################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/SW4STM32/startup_stm32l053xx.s 

OBJS += \
./Application/SW4STM32/startup_stm32l053xx.o 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32l053xx.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/SW4STM32/startup_stm32l053xx.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


