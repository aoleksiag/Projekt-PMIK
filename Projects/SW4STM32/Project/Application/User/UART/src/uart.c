#include "uart.h"


void uart_send_string(UART_HandleTypeDef *huart,char* s){
    HAL_UART_Transmit_IT(huart, (uint8_t*)s, strlen(s));
}
