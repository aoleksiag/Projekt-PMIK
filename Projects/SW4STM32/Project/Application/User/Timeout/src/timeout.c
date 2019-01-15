/*
 * timeout.c
 *
 *  Created on: 23.11.2018
 *      Author: Adrian
 */
#include "timeout.h"

/**
 * @defgroup Timeout
 * @brief
 * @{
 *
 */
 /**
 * @defgroup Timeout_Functions
 * @brief    Timeout Functions
 * @{
 */

/**
  * @brief Start timer and configure apropirate register to timeout opreration
  * @param htim pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
void timeout_start(TIM_HandleTypeDef *htim){
    htim->Instance->SR &=0;
    HAL_TIM_Base_Start_IT(htim);
}
/**
  * @brief Stop timer and configure apropirate register
  * @param htim pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
void timeout_stop(TIM_HandleTypeDef *htim){
    htim->Instance->CNT=0;
    HAL_TIM_Base_Stop_IT(htim);   //nie chcemy wywo³ywac timeoutow gdy mamy dane ok
}
/**
  * @brief reset  timer (ctn register is set to 0)
  * @param htim pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
void timeout_reset(TIM_HandleTypeDef *htim){
   // htim->Instance->CNT=htim->Instance->ARR;
    htim->Instance->CNT=0;
    htim->Instance->SR &=0;
}
/**
  * @brief Timeout operation witch take care about keypad buffer
  * 			   and lcd buffer when timeout occur
  * @param htim pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
void timeout_keypad(TIM_HandleTypeDef *htim){
    HAL_TIM_Base_Stop_IT(htim);
    timeout_char_flag=false;
    buffer_clear(&buffer,6);
    buffer_clear(&buffer2,16);
    buffer_clear(&buffer_do_lcd,6);
    buffer_count=0;

}

/**
  * @brief Timeout operation witch take care about uart buffer
  *             and send message by uart
  * @param htim pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  *	@param huart pointer to UART_HandleTypeDef structure contains
  *	                the configuration information for Uart module.
  *	@param q pointer to circ_buffer_t structure
  * @retval None
  */
void timeout_uart(TIM_HandleTypeDef *htim,UART_HandleTypeDef *huart,circ_buffer_t *q){
    HAL_TIM_Base_Stop_IT(htim);
    circ_buffer_clear(q);
    uart_send_string(huart,"Timeout try again\r\n");
    uart_empty_flag=true;
}


