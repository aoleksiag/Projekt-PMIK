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
#include "MY_Keypad4x4.h"
#include "main.h"



static char *Keypad_keys[16] =
{
	"1",
	"2",
	"3",
	"A",
	"4",
	"5",
	"6",
	"B",
	"7",
	"8",
	"9",
	"C",
	"*",
	"0",
	"#",
	"D"
};


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

