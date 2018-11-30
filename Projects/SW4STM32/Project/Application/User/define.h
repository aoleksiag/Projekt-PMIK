#include "stm32f4xx_hal.h"
#include <stdbool.h>

#define code_lenght 6
#define buffer_length 6
#define UART_RX_BUF_SIZE 7
#define LOG_BUFF_SIZE 6
#define LOG_BUFF_LENGTH 5
#define BUF_SIZE 7
#define TEST



RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
RTC_HandleTypeDef hrtc;

volatile bool sw[16];
volatile bool sw_flag[16];

volatile u_int8_t buffer_count;

char buffer[code_lenght];
char buffer_do_lcd[code_lenght];
char buffer2[16];

char code[code_lenght];

volatile char Data_recived_temp;
volatile char Key_char;

bool flag_char;
bool timeout_char_flag;
bool uart_data_flag;
bool number_char;
bool uart_empty_flag;
bool uart_send_log;


