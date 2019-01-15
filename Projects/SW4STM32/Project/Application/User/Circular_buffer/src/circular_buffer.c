#include "circular_buffer.h"

/**
 * @defgroup buffer
 * @brief
 * @{
 *
 */
 /**
 * @defgroup Buffer_Functions
 * @brief    Library Functions
 * @{
 */

/**
  * @brief Put character in circular buffer
  * @param q pointer to a circ_buffer_t  that contains buffer structure
  * @param data character to put.
  * @retval boolean variable which signals when buffer is full
  */
bool circ_buffer_put_char(circ_buffer_t *q, char data)
{
    volatile uint8_t head_temp = q->head + 1;
    volatile uint8_t head_temp2 = q->head + 2;
    if ( head_temp == BUF_SIZE )
        head_temp = 0;

    if ( head_temp2 == BUF_SIZE )
        head_temp2 = 0;

    if ( head_temp == q->tail )
        return 1;

    q->buffer[head_temp] = data;
    q->head = head_temp;

    if ( head_temp2 == q->tail )
        return 1;

    return 0;
}

/**
  * @brief Put string in circular buffer
  * @param q pointer to a circ_buffer_t  that contains buffer structure
  * @param data string to put.
  * @retval boolean variable which signals when buffer is full
  */
bool circ_buffer_put_string(circ_buffer_2d *q, char *data)
{
    volatile uint8_t head_temp = q->head + 1;

    if ( head_temp == LOG_BUFF_LENGTH )
        head_temp = 0;

    if ( head_temp == q->tail ){
        q->tail += 1;
        if (q->tail == LOG_BUFF_LENGTH){
                q->tail = 0;
        }
    }

    strcpy(q->log_buff[head_temp], data);
    q->head = head_temp;
    return 0;

}

/**
  * @brief Get string from circular buffer
  * @param q pointer to a circ_buffer_t  that contains buffer structure
  * @param data character get from structure.
  * @retval boolean variable which signals when buffer is empty
  */
bool circ_buffer_get_char(circ_buffer_t *q, char *data)
{

    if (q->head == q->tail)
        return 1;

    q->tail++;
    if (q->tail == BUF_SIZE)
        q->tail = 0;

    *data = q->buffer[q->tail];

    return 0;

}
/**
  * @brief Get string from circular buffer
  * @param q pointer to a circ_buffer_t  that contains buffer structure
  * @param data string get from structure.
  * @retval boolean variable which signals when buffer is empty
  */
bool circ_buffer_get_string(circ_buffer_2d *q, char *data)
{
    if (q->head == q->tail)
        return 1;

    q->tail++;
    if (q->tail == LOG_BUFF_LENGTH)
        q->tail = 0;

    strcpy(data, q->log_buff[q->tail]);
    return 0;

}
/**
  * @brief Clear circular buffer
  * @param q pointer to a circ_buffer_t  that contains buffer structure
  * @retval none
  */
void circ_buffer_clear(circ_buffer_t *q){
    q->tail = 0;
    q->head = 0;
}
/**
  * @brief Change content of buffer
  * @param buffer pointer to a buffer variable
  * @param count  shows which elements will be change
  * @param Key    character which will be save in buffer
  * @retval none
  */
void buffer_update(char *buffer,u_int8_t *count,char Key){
    buffer[*count] = Key;
}
/**
  * @brief Clear buffer
  * @param buffer pointer to a buffer variable
  * @param buffer_len  length of buffer
  * @retval none
  */
void buffer_clear(char *buffer,u_int8_t buffer_len){
    for(u_int8_t i=0; i < buffer_len; i++){
    buffer[i] = ' ';
    }
}
/**
  * @brief Check if buffer is the same as code
  * @param buffer pointer to a buffer variable
  * @retval boolean variable which is true when buffer is the same as code
  */
bool buffer_check(char *buffer){
    int8_t i;
    for (i=0; i<buffer_length; i++){
    if(buffer[i] != code[i])
        return 0;
    }
        return 1;

}


