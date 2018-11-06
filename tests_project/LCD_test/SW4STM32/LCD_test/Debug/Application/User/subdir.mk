################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/common.c \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/config.c \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/main.c \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/stm32l0xx_hal_msp.c \
C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/stm32l0xx_it.c 

OBJS += \
./Application/User/common.o \
./Application/User/config.o \
./Application/User/main.o \
./Application/User/stm32l0xx_hal_msp.o \
./Application/User/stm32l0xx_it.o 

C_DEPS += \
./Application/User/common.d \
./Application/User/config.d \
./Application/User/main.d \
./Application/User/stm32l0xx_hal_msp.d \
./Application/User/stm32l0xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/common.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/common.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L053xx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/common.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/config.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/config.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L053xx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/config.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L053xx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32l0xx_hal_msp.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/stm32l0xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L053xx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/stm32l0xx_hal_msp.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32l0xx_it.o: C:/Users/Adrian/Desktop/Projekt\ PMIK/tests_project/LCD_test/Src/stm32l0xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L053xx -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Adrian/Desktop/Projekt PMIK/tests_project/LCD_test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/stm32l0xx_it.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


