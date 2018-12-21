#include "uart.h"


void uart_send_string(UART_HandleTypeDef *huart,char* s){
    HAL_UART_Transmit_IT(huart, (uint8_t*)s, strlen(s));
}

void uart_get_char(TIM_HandleTypeDef *htim11,circ_buffer_2d *uart_rx_circBuff){
    bool error_return;

       if(uart_rx_circBuff->head==uart_rx_circBuff->tail){
           timeout_start(htim11);
       }
       error_return=circ_buffer_put_char(uart_rx_circBuff, Data_recived_temp);
       if(error_return == 1){
           uart_data_flag=true;
           timeout_stop(htim11);
       }else{
           timeout_reset(htim11);
       }

       if(Data_recived_temp =='$'){
           if(uart_empty_flag == true){
               uart_data_flag=true;
               uart_send_log=true;
               timeout_stop(htim11);
               circ_buffer_clear(uart_rx_circBuff);
           }
       }
       if(Data_recived_temp =='T'){
           if(uart_empty_flag == true){
               uart_set_time_flag=true;
           }
       }
       if(Data_recived_temp =='D'){
           if(uart_empty_flag == true){
               uart_set_date_flag=true;
           }
       }
       if(Data_recived_temp =='c'){
           if(uart_empty_flag == true){
               uart_set_change_pass_flag=true;
           }
       }
}

void uart_serv(UART_HandleTypeDef *huart1,circ_buffer_2d *uart_rx_circBuff){
    uart_data_flag=false;
    if(uart_set_change_pass_flag == true){
            uart_set_change_pass_flag = false;
            for (u_int8_t i=0; i<buffer_length+1; i++){
                circ_buffer_get_char(uart_rx_circBuff, &buffer_temp[i]);
            }
            uart_empty_flag=true;
            if(strcmp(buffer_temp,"chpass")==0){
                uart_set_pass=true;
                uart_send_string(huart1,"send previous password\r\n");
            }

        }
    else if(uart_set_time_flag == true){
        uart_set_time_flag = false;
        for (u_int8_t i=0; i<buffer_length+1; i++){
            circ_buffer_get_char(uart_rx_circBuff, &buffer_temp[i]);
        }
        uart_empty_flag=true;
        set_time(&buffer_temp);
    }
    else if(uart_set_date_flag == true){
           uart_set_date_flag = false;
           for (u_int8_t i=0; i<buffer_length+1; i++){
               circ_buffer_get_char(uart_rx_circBuff, &buffer_temp[i]);
           }
           uart_empty_flag=true;
           set_date(&buffer_temp);
       }
    else if(uart_send_log == true){
        uart_send_log_flag=true;
        uart_send_log=false;
    }
    else{

        for (u_int8_t i=0; i<buffer_length+1; i++){
            circ_buffer_get_char(uart_rx_circBuff, &buffer[i]);
        }
        uart_empty_flag=true;
        if(uart_new_pass == true){
            uart_new_pass=false;
            strcpy(code,buffer);
            uart_send_string(huart1,"password changed\r\n");
        }
        else if(uart_set_pass == true){
            uart_set_pass = false;
            if(buffer_check(&buffer)){
                uart_send_string(huart1,"send new password\r\n");
                uart_new_pass = true;
            }
            else{
                uart_send_string(huart1,"bad_code\r\n");
            }
        }
        else{
        if(buffer_check(&buffer)){
            uart_send_string(huart1,"apropirate_code\r\n");
            lock_open();
        }
        else{
            uart_send_string(huart1,"bad_code\r\n");
        }
        }
    }
}
