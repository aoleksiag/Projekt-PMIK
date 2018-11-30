/*
 * timeout.c
 *
 *  Created on: 23.11.2018
 *      Author: Adrian
 */
#include "timeout.h"
#include "struct.h"

void timeout_start(TIM_HandleTypeDef *htim){
    htim->Instance->SR &=0;
    HAL_TIM_Base_Start_IT(htim);   //nie chcemy wywo³ywac timeoutow gdy mamy dane ok
}

void timeout_stop(TIM_HandleTypeDef *htim){
    htim->Instance->CNT=0;
    HAL_TIM_Base_Stop_IT(htim);   //nie chcemy wywo³ywac timeoutow gdy mamy dane ok
}

void timeout_reset(TIM_HandleTypeDef *htim){
   // htim->Instance->CNT=htim->Instance->ARR;
    htim->Instance->CNT=0;
    htim->Instance->SR &=0;
}

void timeout_keypad(TIM_HandleTypeDef *htim){
    HAL_TIM_Base_Stop_IT(htim);
    timeout_char_flag=false;
    buffer_clear(&buffer,6);
    buffer_clear(&buffer2,16);
    buffer_count=0;

}


void timeout_uart(TIM_HandleTypeDef *htim,UART_HandleTypeDef *huart,circ_buffer_t *q){
    HAL_TIM_Base_Stop_IT(htim);
    circ_buffer_clear(q);
    uart_send_string(huart,"Timeout try again\r\n");
    uart_empty_flag=true;
}


