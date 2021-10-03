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

uint32_t adc_val;

GPIO_PinState btn_state;

GPIO_PinState Get_value_btn_state(){
	return btn_state;
}

void Set_value_btn_state (GPIO_PinState b_s){
	btn_state = b_s;
}

uint8_t tx[]="Hello from STM32";
uint8_t rx[17];

int main(void){

  HAL_Init();
  SystemClock_Config();
  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  //MX_ADC1_Init();
  MX_DAC_Init();
  //MX_USART1_UART_Init();
  DWT_Init();
  MX_TIM6_Init();
  TIM_HandleTypeDef* ptr_htim6 = Get_ptr_htim6();
  //HAL_TIM_Base_Start(ptr_htim6);
  HAL_TIM_Base_Start_IT(ptr_htim6);

  //HAL_DAC_Start(ptr_hdac, DAC_CHANNEL_1);
  //UART_HandleTypeDef* ptr_huart1 = Get_ptr_huart1();

  while (1){
/*	  Set_value_btn_state(Get_btn_state());
	  adc_val = Measure_voltage();
	  Increase_dac_volt_by_btn();
	  ptr_rx = USART_TransmitReceive(ptr_huart1, tx, sizeof(tx), 1);
	  USART_TransmitByPress(ptr_huart1, tx, sizeof(tx));

	  HAL_UART_Receive_IT(ptr_huart1, rx, sizeof(rx));

	  if (Get_clear_mas_state()){
		  for (uint8_t i=0; i<17; i++)
			  rx[i]=0;
		  Set_clear_mas_flag(0);
	  }
*/
	  Set_harmonic_signal(1500, 10);


  }
}
