/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */
#include "My_Keypad4x4.h"
#include <stdbool.h>
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim6;

/* USER CODE BEGIN PV */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM6_Init(void);

/* USER CODE BEGIN PFP */
#define code_lenght 6
Keypad_WiresTypeDef keyPad_struct;
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
bool sw[16];
bool sw_flag[16];
bool key_down[16];
u_int8_t i=0;
u_int8_t k=0;
u_int8_t code_length=6;
char buffer[code_lenght];
char temp_buff0;
/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();

  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim6);
  keyPad_struct.IN0_Port= GPIOC;
  keyPad_struct.IN1_Port= GPIOC;
  keyPad_struct.IN2_Port= GPIOC;
  keyPad_struct.IN3_Port= GPIOC;

  keyPad_struct.OUT0_Port= GPIOC;
  keyPad_struct.OUT1_Port= GPIOC;
  keyPad_struct.OUT2_Port= GPIOC;
  keyPad_struct.OUT3_Port= GPIOC;

  keyPad_struct.IN0pin = PI0_Pin;
  keyPad_struct.IN1pin = PI1_Pin;
  keyPad_struct.IN2pin = PI2_Pin;
  keyPad_struct.IN3pin = PI3_Pin;

  keyPad_struct.OUT0pin = PO0_Pin;
  keyPad_struct.OUT1pin = PO1_Pin;
  keyPad_struct.OUT2pin = PO2_Pin;
  keyPad_struct.OUT3pin = PO3_Pin;

//  Keypad4x4_ChangeColomn(1,&keyPad_struct);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while(1){
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
	 // Keypad4x4_ReadKeypad(&sw,&keyPad_struct);
	  /////////////////////////////////////////
	  if(k>code_lenght){
		  k=1;
		  temp_buff0=buffer[0];
		  memset(buffer,0,sizeof(buffer));
		  buffer[0]=temp_buff0;
	  }
	  for(i=0;i<16;i++){
		  if(sw[i] && sw_flag[i] == 0 ){
			  sw_flag[i]=1;
			  buffer[k]=Keypad4x4_GetChar(i);
			  k++;
		  }
		  else if (sw[i] == 0){
			  sw_flag[i]=0;
		  }

	  }

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* TIM6 init function */
static void MX_TIM6_Init(void)
{

  TIM_MasterConfigTypeDef sMasterConfig;

  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 83;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 999;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, PO0_Pin|PO1_Pin|PO2_Pin|PO3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PI0_Pin PI1_Pin PI2_Pin PI3_Pin */
  GPIO_InitStruct.Pin = PI0_Pin|PI1_Pin|PI2_Pin|PI3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PO0_Pin PO1_Pin PO2_Pin PO3_Pin */
  GPIO_InitStruct.Pin = PO0_Pin|PO1_Pin|PO2_Pin|PO3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void keypad_init(Keypad_WiresTypeDef *keyPad_struct){
 /*
	  keyPad_struct->IN0_Port= GPIOC;
	  keyPad_struct->IN1_Port= GPIOC;
	  keyPad_struct->IN2_Port= GPIOC;
	  keyPad_struct->IN3_Port= GPIOC;

	  keyPad_struct->OUT0_Port= GPIOC;
	  keyPad_struct->OUT1_Port= GPIOC;
	  keyPad_struct->OUT2_Port= GPIOC;
	  keyPad_struct->OUT3_Port= GPIOC;

	  keyPad_struct->IN0pin = PI0_Pin;
	  keyPad_struct->IN1pin = PI1_Pin;
	  keyPad_struct->IN2pin = PI2_Pin;
	  keyPad_struct->IN3pin = PI3_Pin;

	  keyPad_struct->OUT0pin = PO0_Pin;
	  keyPad_struct->OUT1pin = PO1_Pin;
	  keyPad_struct->OUT2pin = PO2_Pin;
	  keyPad_struct->OUT3pin = PO3_Pin;

	   Keypad4x4_Init(&keyPad_struct);
	   */
	HAL_GPIO_WritePin(keyPad_struct->OUT0_Port,keyPad_struct->OUT0pin,1);
	HAL_GPIO_WritePin(keyPad_struct->OUT2_Port,keyPad_struct->OUT2pin,1);

}

/*
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
}*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	Keypad4x4_ReadKeypad(&sw,&keyPad_struct);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
