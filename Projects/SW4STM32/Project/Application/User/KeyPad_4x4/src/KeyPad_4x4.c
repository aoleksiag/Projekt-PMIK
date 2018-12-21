/*
Library:						4x4 Keypad drive for STM32 MCUs
Written by:					Mohamed Yaqoob
Date written:				03/04/2018
Description:				The MY_Keypad4x4 library consists of the following public functions
										Function(1)- Keypad4x4_Init
										Function(2)- Keypad4x4_ReadKeypad
										Function(3)- Keypad4x4_GetChar
*/

//***** Header files *****//
#include "KeyPad_4x4.h"
#include "main.h"



static char *Keypad_keys[16] =
{
	49, //1
	50, //2
	51, //3
	65, //A
	52, //4
	53, //5
	54, //6
	66, //B
	55, //7
	56, //8
	57, //9
	67, //C
	42, //*
	48, //0
	35, //#
	68  //D
};

void KeyPad_4x4_Init(Keypad_WiresTypeDef *keyPad_struct){
	  keyPad_struct->IN0_Port= PI0_GPIO_Port;
	  keyPad_struct->IN1_Port= PI1_GPIO_Port;
	  keyPad_struct->IN2_Port= PI2_GPIO_Port;
	  keyPad_struct->IN3_Port= PI3_GPIO_Port;

	  keyPad_struct->OUT0_Port= PO0_GPIO_Port;
	  keyPad_struct->OUT1_Port= PO1_GPIO_Port;
	  keyPad_struct->OUT2_Port= PO2_GPIO_Port;
	  keyPad_struct->OUT3_Port= PO3_GPIO_Port;

	  keyPad_struct->IN0pin = PI0_Pin;
	  keyPad_struct->IN1pin = PI1_Pin;
	  keyPad_struct->IN2pin = PI2_Pin;
	  keyPad_struct->IN3pin = PI3_Pin;

	  keyPad_struct->OUT0pin = PO0_Pin;
	  keyPad_struct->OUT1pin = PO1_Pin;
	  keyPad_struct->OUT2pin = PO2_Pin;
	  keyPad_struct->OUT3pin = PO3_Pin;
}

void Keypad4x4_ChangeColomn(uint8_t colNum_0_to_3,Keypad_WiresTypeDef *KeypadStruct)
{
	if(colNum_0_to_3==0)
	{
		//Set selected colomn
		HAL_GPIO_WritePin(KeypadStruct->OUT0_Port,KeypadStruct->OUT0pin,1);

		//Make other colomns floating
		HAL_GPIO_WritePin(KeypadStruct->OUT1_Port,KeypadStruct->OUT1pin,0);
		HAL_GPIO_WritePin(KeypadStruct->OUT2_Port,KeypadStruct->OUT2pin,0);
		HAL_GPIO_WritePin(KeypadStruct->OUT3_Port,KeypadStruct->OUT3pin,0);
	}
	else if(colNum_0_to_3==1)
	{
		//Set selected colomn
		HAL_GPIO_WritePin(KeypadStruct->OUT1_Port,KeypadStruct->OUT1pin,1);

		//Make other colomns floating
		HAL_GPIO_WritePin(KeypadStruct->OUT0_Port,KeypadStruct->OUT0pin,0);
		HAL_GPIO_WritePin(KeypadStruct->OUT2_Port,KeypadStruct->OUT2pin,0);
		HAL_GPIO_WritePin(KeypadStruct->OUT3_Port,KeypadStruct->OUT3pin,0);
	}
	else if(colNum_0_to_3==2)
	{
		//Set selected colomn
		HAL_GPIO_WritePin(KeypadStruct->OUT2_Port,KeypadStruct->OUT2pin,1);

		//Make other colomns floating
		HAL_GPIO_WritePin(KeypadStruct->OUT0_Port,KeypadStruct->OUT0pin,0);
		HAL_GPIO_WritePin(KeypadStruct->OUT1_Port,KeypadStruct->OUT1pin,0);
		HAL_GPIO_WritePin(KeypadStruct->OUT3_Port,KeypadStruct->OUT3pin,0);
	}
	else if(colNum_0_to_3==3)
	{
		//Set selected colomn
		//Set selected colomn
		HAL_GPIO_WritePin(KeypadStruct->OUT3_Port,KeypadStruct->OUT3pin,1);

		//Make other colomns floating
		HAL_GPIO_WritePin(KeypadStruct->OUT1_Port,KeypadStruct->OUT1pin,0);
		HAL_GPIO_WritePin(KeypadStruct->OUT2_Port,KeypadStruct->OUT2pin,0);
		HAL_GPIO_WritePin(KeypadStruct->OUT0_Port,KeypadStruct->OUT0pin,0);
	}
}

//Function(4): Read active keypad button
void Keypad4x4_ReadKeypad(bool keys[16],Keypad_WiresTypeDef *KeypadStruct)
{
	//Step(1): Make Col0 High and check the rows
	Keypad4x4_ChangeColomn(0,KeypadStruct);
	keys[0] = HAL_GPIO_ReadPin(KeypadStruct->IN0_Port, KeypadStruct->IN0pin);
	keys[4] = HAL_GPIO_ReadPin(KeypadStruct->IN1_Port, KeypadStruct->IN1pin);
	keys[8] = HAL_GPIO_ReadPin(KeypadStruct->IN2_Port, KeypadStruct->IN2pin);
	keys[12] = HAL_GPIO_ReadPin(KeypadStruct->IN3_Port, KeypadStruct->IN3pin);

	//Step(2): Make Col1 High and check the rows
	Keypad4x4_ChangeColomn(1,KeypadStruct);
	keys[1] = HAL_GPIO_ReadPin(KeypadStruct->IN0_Port, KeypadStruct->IN0pin);
	keys[5] = HAL_GPIO_ReadPin(KeypadStruct->IN1_Port, KeypadStruct->IN1pin);
	keys[9] = HAL_GPIO_ReadPin(KeypadStruct->IN2_Port, KeypadStruct->IN2pin);
	keys[13] = HAL_GPIO_ReadPin(KeypadStruct->IN3_Port, KeypadStruct->IN3pin);

	//Step(3): Make Col2 High and check the rows
	Keypad4x4_ChangeColomn(2,KeypadStruct);
	keys[2] = HAL_GPIO_ReadPin(KeypadStruct->IN0_Port, KeypadStruct->IN0pin);
	keys[6] = HAL_GPIO_ReadPin(KeypadStruct->IN1_Port, KeypadStruct->IN1pin);
	keys[10] = HAL_GPIO_ReadPin(KeypadStruct->IN2_Port, KeypadStruct->IN2pin);
	keys[14] = HAL_GPIO_ReadPin(KeypadStruct->IN3_Port, KeypadStruct->IN3pin);

	//Step(4): Make Col3 High and check the rows
	Keypad4x4_ChangeColomn(3,KeypadStruct);
	keys[3] = HAL_GPIO_ReadPin(KeypadStruct->IN0_Port, KeypadStruct->IN0pin);
	keys[7] = HAL_GPIO_ReadPin(KeypadStruct->IN1_Port, KeypadStruct->IN1pin);
	keys[11] = HAL_GPIO_ReadPin(KeypadStruct->IN2_Port, KeypadStruct->IN2pin);
	keys[15] = HAL_GPIO_ReadPin(KeypadStruct->IN3_Port, KeypadStruct->IN3pin);
}
char* Keypad4x4_GetChar(uint8_t keypadSw)
{
	return Keypad_keys[keypadSw];

}

void keypad_serv(TIM_HandleTypeDef *htim11,circ_buffer_2d *log_circ_buff){
    flag_char=0;
    char str[15];
    timeout_char_flag=true;
    if(number_of_bad_code == 3){
        strcpy(buffer2,"keypad is block");
        timeout_start(htim11);
    }else{
        if(buffer_count == 0){
            timeout_start(htim11);
        }
        if(lock_open_flag){
                if(Key_char == '*'){
                    strcpy(buffer2,"lock close");
                    lock_close();
                }
        }else{
            timeout_reset(htim11);
            if(buffer_count < buffer_length){
                if(buffer_count==5){
                    timeout_stop(htim11);
                }
                if(number_char){
                    buffer_update(&buffer,&buffer_count,Key_char);
                    buffer_update(&buffer_do_lcd,&buffer_count,'X');
                    buffer_count++;
                    buffer_clear(&buffer2,16);

                }
            }else{
                if(Key_char=='#'){
                    buffer_count=0;
                    if(buffer_check(&buffer)){
                        timeout_start(htim11);
                        strcpy(buffer2,"lock open");
                        buffer_clear(&buffer,buffer_length);
                        buffer_clear(&buffer_do_lcd,buffer_length);
                        number_of_bad_code = 0;
                        lock_open();
                    }else{
                        timeout_start(htim11);
                        sprintf(str,"remained %d try",NUMBER_OF_BAD_CODE-number_of_bad_code);
                        strcpy(buffer2,str);
                        buffer_clear(&buffer,buffer_length);
                        buffer_clear(&buffer_do_lcd,buffer_length);
                        number_of_bad_code++;
                    }
                }
            }
            if (Key_char=='C'){
                buffer_clear(&buffer,buffer_length);
                buffer_clear(&buffer_do_lcd,buffer_length);
                buffer_count=0;
#ifdef TEST
                save_time(log_circ_buff);
#endif
            }
        }
    }
}

