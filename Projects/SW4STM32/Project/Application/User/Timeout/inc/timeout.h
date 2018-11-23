#include "main.h"
#include "stm32f4xx_hal.h"

void timeout_start(TIM_HandleTypeDef *htim);

void timeout_stop(TIM_HandleTypeDef *htim);

void timeout_reset(TIM_HandleTypeDef *htim);
