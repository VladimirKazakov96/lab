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

uint32_t adc_val;

GPIO_PinState btn_state;

GPIO_PinState Get_value_btn_state(){
	return btn_state;
}

void Set_value_btn_state (GPIO_PinState b_s){
	btn_state = b_s;
}

uint8_t tx[]="Hello from STM32";
uint8_t* ptr_rx;
int main(void){

  HAL_Init();
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  //MX_ADC1_Init();
  //MX_DAC_Init();
  MX_USART1_UART_Init();

  //HAL_DAC_Start(ptr_hdac, DAC_CHANNEL_1);
  UART_HandleTypeDef* ptr_huart1 = Get_ptr_huart1();

  while (1)
  {
	 // Set_value_btn_state(Get_btn_state());
	 // adc_val = Measure_voltage();
	 // Increase_dac_volt_by_btn();
	  ptr_rx = USART_TransmitReceive(ptr_huart1, tx, sizeof(tx), 1);

  }
}
