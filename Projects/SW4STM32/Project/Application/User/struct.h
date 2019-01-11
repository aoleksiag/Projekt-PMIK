#include "stm32f4xx_hal.h"
#include "define.h"

/**
  * @brief Data structure implemented as circular buffer
  *
  * Data in this structure is 2d, so it can hold log value.
  *
  */
typedef struct {
    char log_buff[LOG_BUFF_LENGTH][LOG_BUFF_SIZE];  /**< log container */
    u_int8_t head;                                  /**< variable hold place where is the oldest data */
    u_int8_t tail;                                  /**< variable hold place where is the newest data */
} circ_buffer_2d;
/**
  * @brief Data structure implemented as circular buffer
  *
  * Data in this structure is 1d. It was implemented to deal with uart data.
  *
  */
typedef struct {
    volatile char * const buffer; /**< char container */
    u_int8_t head;                /**< variable hold place where is the oldest data */
    u_int8_t tail;                /**< variable hold place where is the newest data */
} circ_buffer_t;

