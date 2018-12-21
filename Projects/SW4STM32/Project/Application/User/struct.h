#include "stm32f4xx_hal.h"
#include "define.h"


typedef struct {
    char log_buff[LOG_BUFF_LENGTH][LOG_BUFF_SIZE];
    u_int8_t head;
    u_int8_t tail;
} circ_buffer_2d;

typedef struct {
    volatile char * const buffer;
    u_int8_t head;
    u_int8_t tail;
} circ_buffer_t;

