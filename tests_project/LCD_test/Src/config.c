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
#include "config.h"

void TIMERS_Config(void){
/*

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	// delay_ms
	TIM_TimeBaseInitTypeDef TIM_TimeBaseMili_InitStructure;
	TIM_TimeBaseMili_InitStructure.TIM_Prescaler = 64000 - 1;
	TIM_TimeBaseMili_InitStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseMili_InitStructure);

	//delay_us
	TIM_TimeBaseInitTypeDef TIM_TimeBaseMicro_InitStructure;
	TIM_TimeBaseMicro_InitStructure.TIM_Prescaler = 35 - 1;
	TIM_TimeBaseMicro_InitStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseMicro_InitStructure);
*/

}
