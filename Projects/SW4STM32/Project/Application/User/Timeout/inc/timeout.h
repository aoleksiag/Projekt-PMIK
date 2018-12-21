//#include "define.h"
#include "stm32f4xx_hal.h"
#include "global_variable.h"

void timeout_start(TIM_HandleTypeDef *htim);

void timeout_stop(TIM_HandleTypeDef *htim);

void timeout_reset(TIM_HandleTypeDef *htim);

void timeout_keypad(TIM_HandleTypeDef *htim);

//void timeout_uart(TIM_HandleTypeDef *htim,UART_HandleTypeDef *huart,circ_buffer_t *q);
