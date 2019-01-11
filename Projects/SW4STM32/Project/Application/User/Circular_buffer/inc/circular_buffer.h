/**
* @file circular_buffer.h
* @brief this header file will contain all required function
* definitions to circular_buffer.c
*
* @author Adrian Oleksiak
*
* @date 08/01/2019
*/

#include "global_variable.h"
#include "stm32f4xx_hal.h"



bool circ_buffer_get_char(circ_buffer_t *q, char *data);

bool circ_buffer_get_string(circ_buffer_2d *q, char *data);

bool circ_buffer_put_char(circ_buffer_t *q, char data);

bool circ_buffer_put_string(circ_buffer_2d *q, char *data);

void circ_buffer_clear(circ_buffer_t *q);

void buffer_update(char *buffer,u_int8_t *count,char Key);

void buffer_clear(char *buffer,u_int8_t buffer_len);

bool buffer_check(char *buffer);
