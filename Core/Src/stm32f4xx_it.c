/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f4xx_it.h"
#include "gpio.h"
#include "dac_utilities.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim6;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{

  while (1)
  {
  }

}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{

}


//uint8_t clear_mas = 0;

//uint8_t Get_clear_mas_state(){
//	return clear_mas;
//}
//void Set_clear_mas_flag(uint8_t state){
//	clear_mas = state;
//}

void SysTick_Handler(void)
{
  static uint16_t ms_cntr = 0;
  //static uint16_t ms_cntr2 = 0;
  HAL_IncTick();
  if (ms_cntr++ == 1000){
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
	  ms_cntr = 0;
  }
  //if (ms_cntr2++ == 5000){
//	  clear_mas = 1;
//	  ms_cntr2 = 0;
 // }
}

void USART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart1);
}

uint8_t can_gen_dac_vol = 0;

uint8_t Can_gen_dac_vol(){
	return can_gen_dac_vol;
}

void Reset_flag_gen_dac_vol(){
	can_gen_dac_vol = 0;
}

//uint32_t tick_m[100];
uint32_t us2_cntr = 0; //2мк счетчик


void TIM6_DAC_IRQHandler(void)
{

  if (Get_kf() == us2_cntr){
	  can_gen_dac_vol = 1;
	  us2_cntr = 0;
  }else
	  us2_cntr++;

  HAL_TIM_IRQHandler(&htim6);

}


/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
