#include "stm32f4xx_hal.h"
#include <stdbool.h>

#define code_lenght 6
#define buffer_length 6
#define UART_RX_BUF_SIZE 7
#define LOG_BUFF_SIZE 12
#define BUF_SIZE 7
#define TEST






//////////////////////////////private variables/////////////////////////////////
RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
RTC_HandleTypeDef hrtc;



///////////////////////////////////////////////////////////////////////////////////
