#include "define.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include "circular_buffer.h"


/*typedef struct {
    volatile char * const buffer;
    u_int8_t head;
    u_int8_t tail;
} circ_buffer_data;

char log_buff[LOG_BUFF_SIZE];
volatile circ_buffer_data log_circ_buff = { log_buff, 0, 0 };*/

void save_time(void);
