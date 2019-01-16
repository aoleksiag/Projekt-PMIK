#ifndef APPLICATION_USER_CIRCULAR_BUFFER_INC_COS_H_
#define APPLICATION_USER_CIRCULAR_BUFFER_INC_COS_H_
#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include "define.h"
#include "struct.h"
#endif /* APPLICATION_USER_CIRCULAR_BUFFER_INC_COS_H_ */

/**
 * @defgroup  variables
 * @brief
 * @{
 *
 */
/**
 * @defgroup gl variables

 * @{
 */

RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
RTC_HandleTypeDef hrtc;


bool sw[16];                      /**< array hold pressed button */
bool sw_flag[16];                 /**< array hold previous pressed button */

volatile u_int8_t buffer_count;
int8_t number_of_bad_code;

char buffer[code_length];
char buffer_temp[code_length];
char buffer_do_lcd[code_length]; /**< first row in LCD */
char buffer2[16];                /**< second row in LCD */

char code[code_length+1];        /**< vector which hold code to lock*/

char Data_recived_temp;
volatile char Key_char;

bool flag_char;                  /**< someone press button on keypad */
bool timeout_char_flag;
bool uart_data_flag;             /**< someone send uart frame */
bool number_char;                /**< someone press number on keypad */
bool uart_empty_flag;
bool uart_send_log;             /**< send log by uart */
bool uart_new_line_flag;
bool uart_set_time_flag;
bool uart_set_date_flag;
bool uart_set_change_pass_flag;
bool uart_set_pass;
bool uart_new_pass;
bool lock_open_flag;            /**< lock status */

char uart_log_str[LOG_BUFF_SIZE];

volatile u_int8_t uart_string_tosend_count;

u_int8_t k;


