#include "gpio.h"
#include "delay_micros.h"

void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GREEN_LED_Port, GREEN_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : GREEN_LED_Pin */
  GPIO_InitStruct.Pin = GREEN_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GREEN_LED_Port, &GPIO_InitStruct);
  /*Configure GPIO pin : BTN_Pin */
  GPIO_InitStruct.Pin = BTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BTN_Port, &GPIO_InitStruct);

  /*Configure GPIO pin: */
  GPIO_InitStruct.Pin = PWM_MEASURE_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PWM_MEASURE_PORT, &GPIO_InitStruct);
  HAL_GPIO_Init(PWM_MEASURE_PORT, &GPIO_InitStruct);

}

void DAC_GPIO_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GREEN_LED_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);

}

void DAC_GPIO_DeInit(){
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOA_CLK_DISABLE();
	HAL_GPIO_DeInit(GPIOA, &GPIO_InitStruct);
}



GPIO_PinState Get_btn_state(){
	static uint32_t btn_on_tick = 0;
	static uint8_t is_btn_pushed = 0;
	GPIO_PinState btn_state = GPIO_PIN_RESET;
	if (HAL_GPIO_ReadPin(BTN_Port, BTN_Pin) == GPIO_PIN_SET)
		if (!is_btn_pushed){
			btn_on_tick = HAL_GetTick();
			is_btn_pushed = 1;
		}
	if (is_btn_pushed)
		if ((HAL_GetTick() > btn_on_tick + 10)){
			if (HAL_GPIO_ReadPin(BTN_Port, BTN_Pin) == GPIO_PIN_SET)
				btn_state = GPIO_PIN_SET;
			else
				is_btn_pushed = 0;
		}

	return btn_state;
}

double duty = 0;
uint32_t duration_high = 0;
uint32_t duration_period = 0;
GPIO_PinState prev_state = GPIO_PIN_RESET;
void Measure_PWM(){
	GPIO_PinState cur_state;
	cur_state = HAL_GPIO_ReadPin(PWM_MEASURE_PORT, PWM_MEASURE_PIN);

	if (prev_state != cur_state){
		if (cur_state == GPIO_PIN_SET){
			if (Get_micros() != 0){
				duration_period = Get_micros();
				duty = duration_period/duration_high;
				Reset_DWT_Cntr();
			}
			Start_DWT();
		}else{
			duration_high = Get_micros();
		}
		prev_state = cur_state;
	}

}



























