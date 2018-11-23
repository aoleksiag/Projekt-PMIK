/*
 * circular_buffer.h
 *
 *  Created on: 21.11.2018
 *      Author: Adrian
 */
#include "define.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>

typedef struct {
    volatile char * const buffer;
    u_int8_t head;
    u_int8_t tail;
} circ_buffer_t;

bool circ_buffer_get_char(circ_buffer_t *q, char *data);

bool circ_buffer_put_char(circ_buffer_t *q, char data);

void circ_buffer_clear(circ_buffer_t *q);

void buffer_update(char *buffer,u_int8_t *count,char Key);

void buffer_clear(char *buffer,u_int8_t buffer_len);

bool buffer_check(char *buffer);
