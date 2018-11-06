################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/lcd_test_f4/Src/main.c \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/lcd_test_f4/Src/stm32f4xx_hal_msp.c \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/lcd_test_f4/Src/stm32f4xx_it.c \
../Application/User/tm_stm32_delay.c \
../Application/User/tm_stm32_gpio.c \
../Application/User/tm_stm32_hd44780.c 

OBJS += \
./Application/User/main.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_it.o \
./Application/User/tm_stm32_delay.o \
./Application/User/tm_stm32_gpio.o \
./Application/User/tm_stm32_hd44780.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_it.d \
./Application/User/tm_stm32_delay.d \
./Application/User/tm_stm32_gpio.d \
./Application/User/tm_stm32_hd44780.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/lcd_test_f4/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F410Rx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/CMSIS/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/SW4STM32/lcd_test_f4/Application/User"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_hal_msp.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/lcd_test_f4/Src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F410Rx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/CMSIS/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/SW4STM32/lcd_test_f4/Application/User"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/stm32f4xx_hal_msp.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_it.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/lcd_test_f4/Src/stm32f4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F410Rx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/CMSIS/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/SW4STM32/lcd_test_f4/Application/User"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/stm32f4xx_it.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/%.o: ../Application/User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F410Rx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/Drivers/CMSIS/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/lcd_test_f4/SW4STM32/lcd_test_f4/Application/User"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


