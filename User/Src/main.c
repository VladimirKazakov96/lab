/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"
#include "adc.h"
#include "system_config.h"
#include "adc_utilities.h"
#include "dac.h"
#include "dac_utilities.h"
#include "usart.h"
#include "usart_utilities.h"
#include "delay_micros.h"
#include "tim.h"

int main(void){

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  //MX_DAC_Init();
  DWT_Init();
  //MX_TIM6_Init();
  //TIM_HandleTypeDef* ptr_htim6 = Get_ptr_htim6();
  //HAL_TIM_Base_Start_IT(ptr_htim6);
  //HAL_DAC_Start(Get_ptr_hdac(), DAC_CHANNEL_1);
  MX_TIM4_Init();

  while (1){
	  Measure_PWM();
  }
}
