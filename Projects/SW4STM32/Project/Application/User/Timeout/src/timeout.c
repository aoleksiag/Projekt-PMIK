/*
 * timeout.c
 *
 *  Created on: 23.11.2018
 *      Author: Adrian
 */
#include "timeout.h"

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
