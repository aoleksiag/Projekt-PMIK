#include "stm32f4xx_hal.h"
#include <stdbool.h>

#define code_length 6
#define buffer_length 6
#define UART_RX_BUF_SIZE 7
#define LOG_BUFF_SIZE 12
#define LOG_BUFF_LENGTH 5
#define BUF_SIZE 7
#define TEST
#define NUMBER_OF_BAD_CODE 2



RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
RTC_HandleTypeDef hrtc;

bool sw[16];
bool sw_flag[16];

volatile u_int8_t buffer_count;
int8_t number_of_bad_code;

char buffer[code_length];
char buffer_temp[code_length];
char buffer_do_lcd[code_length];
char buffer2[16];

char code[code_length];

char Data_recived_temp;
volatile char Key_char;

bool flag_char;
bool timeout_char_flag;
bool uart_data_flag;
bool number_char;
bool uart_empty_flag;
bool uart_send_log;
bool uart_new_line_flag;
bool uart_send_log_flag;
bool uart_set_time_flag;
bool uart_set_date_flag;
bool uart_set_change_pass_flag;
bool uart_set_pass;
bool uart_new_pass;
bool lock_open_flag;
char uart_log_str[LOG_BUFF_SIZE];

volatile u_int8_t uart_string_tosend_count;


u_int8_t k;
