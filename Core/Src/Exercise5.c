/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "sofware_timer.h"
#define RED		0
#define YELLOW	1
#define GREEN	2

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void display7SEG(int num);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	int led1_status = RED;
	HAL_GPIO_WritePin(RED1_LED_GPIO_Port, RED1_LED_Pin, 1);
	HAL_GPIO_WritePin(YELLOW1_LED_GPIO_Port, YELLOW1_LED_Pin, 0);
	HAL_GPIO_WritePin(GREEN1_LED_GPIO_Port, GREEN1_LED_Pin, 0);
	setTimer(500);

	int count_down = 5;
	timer_flag2 = 1;
	setTimer2(100);

	int led2_status = GREEN;
	HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, 0);
	HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, 0);
	HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, 1);
	setTimer1(300);
  while (1)
  {
	  if (timer_flag == 1){
		  if (led1_status == RED){
			HAL_GPIO_WritePin(RED1_LED_GPIO_Port, RED1_LED_Pin, 0);
			HAL_GPIO_WritePin(YELLOW1_LED_GPIO_Port, YELLOW1_LED_Pin, 0);
			HAL_GPIO_WritePin(GREEN1_LED_GPIO_Port, GREEN1_LED_Pin, 1);
			led1_status = GREEN;
			setTimer(300);
		  }
		  else if (led1_status == YELLOW){
			HAL_GPIO_WritePin(RED1_LED_GPIO_Port, RED1_LED_Pin, 1);
			HAL_GPIO_WritePin(YELLOW1_LED_GPIO_Port, YELLOW1_LED_Pin, 0);
			HAL_GPIO_WritePin(GREEN1_LED_GPIO_Port, GREEN1_LED_Pin, 0);
			led1_status = RED;
			setTimer(500);
		  }
		  else if (led1_status == GREEN){
			HAL_GPIO_WritePin(RED1_LED_GPIO_Port, RED1_LED_Pin, 0);
			HAL_GPIO_WritePin(YELLOW1_LED_GPIO_Port, YELLOW1_LED_Pin, 1);
			HAL_GPIO_WritePin(GREEN1_LED_GPIO_Port, GREEN1_LED_Pin, 0);
			led1_status = YELLOW;
			setTimer(200);
		  }
	  }
	  if (timer_flag2 == 1){
		  count_down--;
		  if (count_down <= 0){
			  switch (led1_status){
			  case RED:
				  count_down = 5;
				  break;
			  case GREEN:
				  count_down = 3;
				  break;
			  case YELLOW:
				  count_down = 2;
				  break;
			  }
		  }
		  display7SEG(count_down);
		  setTimer2(100);
	  }
	  if (timer_flag1 == 1){
		  if (led2_status == RED){
			HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, 0);
			HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, 0);
			HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, 1);
			led2_status = GREEN;
			setTimer1(300);
		  }
		  else if (led2_status == YELLOW){
			HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, 1);
			HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, 0);
			HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, 0);
			led2_status = RED;
			setTimer1(500);
		  }
		  else if (led2_status == GREEN){
			HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, 0);
			HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, 1);
			HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, 0);
			led2_status = YELLOW;
			setTimer1(200);
		  }
	  }
	  timerRun();
	  HAL_Delay(10);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void display7SEG(int num){
	switch (num){
		case 0:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 6:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 7:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
			break;
		case 8:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 9:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_Pin|RED1_LED_Pin|YELLOW1_LED_Pin|GREEN1_LED_Pin
                          |RED2_LED_Pin|YELLOW2_LED_Pin|GREEN2_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_Pin RED1_LED_Pin YELLOW1_LED_Pin GREEN1_LED_Pin
                           RED2_LED_Pin YELLOW2_LED_Pin GREEN2_LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin|RED1_LED_Pin|YELLOW1_LED_Pin|GREEN1_LED_Pin
                          |RED2_LED_Pin|YELLOW2_LED_Pin|GREEN2_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin D_Pin
                           E_Pin F_Pin G_Pin */
  GPIO_InitStruct.Pin = A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
