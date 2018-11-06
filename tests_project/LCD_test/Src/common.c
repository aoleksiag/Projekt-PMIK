/*
 * Autor: £ukasz £aguna
 * E-mail: kontakt@embeddeddev.pl
 * www.EmbeddedDev.pl
 *
 * Obs³uga LCD opartych na sterowniku HD44780
 * tryb 4-bitowy, bez odczytu busy flag
 *
 * MCU: STM32F103
 *
 */

#include "stm32l0xx_hal.h"
#include "common.h"


void delay_ms(uint16_t czas) {
/*

	TIM_SetCounter(TIM2,czas);

	TIM_Cmd(TIM2, ENABLE);
	while (TIM_GetCounter(TIM2));
	TIM_Cmd(TIM2, DISABLE);

}

void delay_us(uint8_t czas) {

	TIM_SetCounter(TIM6,czas);

	TIM_Cmd(TIM6, ENABLE);
	while (TIM_GetCounter(TIM6));
	TIM_Cmd(TIM6, DISABLE);
*/

}

