

#include "circular_buffer.h"




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

bool circ_buffer_put_string(circ_buffer_2d *q, char *data)
{
    volatile uint8_t head_temp = q->head + 1;

    if ( head_temp == LOG_BUFF_LENGTH )
        head_temp = 0;

    if ( head_temp == q->tail )
        return 1;


    strcpy(q->log_buff[q->head], data);
    q->head = head_temp;


    return 0;

}



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

bool circ_buffer_get_string(circ_buffer_2d *q, char *data)
{

    if (q->head == q->tail)
        return 1;

    q->tail++;

    if (q->tail == LOG_BUFF_LENGTH)
        q->tail = 0;

    strcpy(data, q->log_buff[q->tail]);
  //  strcpy(data,"dupa");
   // *data = q->log_buff[q->tail];

    return 0;

}
void circ_buffer_clear(circ_buffer_t *q){
    q->tail = 0;
    q->head = 0;
}

void buffer_update(char *buffer,u_int8_t *count,char Key){
    buffer[*count] = Key;

}
void buffer_clear(char *buffer,u_int8_t buffer_len){
    for(u_int8_t i=0; i < buffer_len; i++){
    buffer[i] = ' ';
    }
}

bool buffer_check(char *buffer){
    if(strcmp(buffer,code) == 0){  ///jednorozszc
        return 1;
    }
    else{
        return 0;
    }
}

bool test( char *data)
{
    const char *src= "DUpa";
    strcpy(data,"dupa");


    return 0;

}
