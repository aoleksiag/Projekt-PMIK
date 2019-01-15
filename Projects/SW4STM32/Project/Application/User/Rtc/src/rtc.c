#include "rtc.h"
/**
 * @defgroup RTC
 * @brief
 * @{
 *
 */
 /**
 * @defgroup RTC_Functions
 * @brief    RTC Functions
 * @{
 */


/**
  * @brief Save date and time in circ_buffer_2d
  * @param log_circ_buff pointer to circ_buffer_2d with contains place to store data
  * @retval None
  */
void save_time(circ_buffer_2d *log_circ_buff){
    char str[2];
    char log_buff_temp[LOG_BUFF_SIZE];
    memset(log_buff_temp,0,sizeof(log_buff_temp));
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
    sprintf(str, "%d", sTime.Hours);
    if(sTime.Hours<10){
        strncat(log_buff_temp, "0", 1);
        strncat(log_buff_temp, str, 1);
    }
    else{
        strncat(log_buff_temp, str, 2);
    }
    strncat(log_buff_temp, ":", 1);

    sprintf(str, "%d", sTime.Minutes);
    if(sTime.Minutes<10){
        strncat(log_buff_temp, "0", 1);
        strncat(log_buff_temp, str, 1);
    }
    else{
        strncat(log_buff_temp, str, 2);
    }
    strncat(log_buff_temp, ';', 1);

    sprintf(str, "%d", sDate.Date);
       if(sDate.Date<10){
           strncat(log_buff_temp, "0", 1);
           strncat(log_buff_temp, str, 1);
       }
       else{
           strncat(log_buff_temp, str, 2);
       }
       strncat(log_buff_temp, ".", 1);

       sprintf(str, "%d", sDate.Month);
       if(sDate.Month<10){
           strncat(log_buff_temp, "0", 1);
           strncat(log_buff_temp, str, 1);
       }
       else{
           strncat(log_buff_temp, str, 2);
       }
       strncat(log_buff_temp, '\0', 1);


    circ_buffer_put_string(log_circ_buff, &log_buff_temp);
}
/**
  * @brief Set time in RTC module
  * @param buffer pointer to place where time is store
  * @retval None
  */
void set_time(char *buffer){
    u_int8_t number;
    char str[2];
    if(buffer[1]==0){
        number=atoi(buffer[2]);
        sTime.Hours=number;
    }else{
        sprintf(str, "%c%c", buffer[1],buffer[2]);
        number=atoi(str);
                sTime.Hours=number;
    }
    if(buffer[4]==0){
            number=atoi(buffer[5]);
            sTime.Minutes=number;
        }else{
            sprintf(str, "%c%c", buffer[4],buffer[5]);
            number=atoi(str);
                    sTime.Minutes=number;
        }
    HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);

}
/**
  * @brief Set data in RTC module
  * @param buffer pointer to place where data is store
  * @retval None
  */
void set_date(char *buffer){
    u_int8_t number;
    char str[2];
    if(buffer[1]==0){
        number=atoi(buffer[2]);
        sDate.Date=number;
    }else{
        sprintf(str, "%c%c", buffer[1],buffer[2]);
        number=atoi(str);
        sDate.Date=number;;
    }
    if(buffer[4]==0){
            number=atoi(buffer[5]);
            sDate.Month=number;
        }else{
            sprintf(str, "%c%c", buffer[4],buffer[5]);
            number=atoi(str);
            sDate.Month=number;
        }
    HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

}
