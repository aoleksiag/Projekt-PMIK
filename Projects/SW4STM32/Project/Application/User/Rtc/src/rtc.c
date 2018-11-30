#include "rtc.h"


void save_time(circ_buffer_2d *log_circ_buff){
    char str[2];
    char log_buff_temp[LOG_BUFF_SIZE];
    int8_t c=15;
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
    strncat(log_buff_temp, '\0', 1);

    circ_buffer_put_string(log_circ_buff, &log_buff_temp);
}
