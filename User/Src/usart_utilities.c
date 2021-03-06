#include "usart_utilities.h"

uint8_t* USART_TransmitReceive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout){
	static uint8_t rx_mass[256];
	static uint8_t* cntr_addr_rx_mass = rx_mass;
	static uint8_t smbl_cntr = 0;
	uint8_t* cur_pData;
	if (smbl_cntr < Size){
		cur_pData = pData+smbl_cntr;
		HAL_UART_Transmit(huart, cur_pData, 1, Timeout);
		//HAL_Delay(100);
		HAL_UART_Receive(huart, cntr_addr_rx_mass, 1, Timeout);
		cntr_addr_rx_mass++;
		//HAL_Delay(100);
		smbl_cntr++;
	}else{
		smbl_cntr = 0;
		cntr_addr_rx_mass -= Size;
		for (uint8_t i = 0; i< Size; i++)
			rx_mass[i]=0;
	}

	return rx_mass;
}

void USART_TransmitByPress(UART_HandleTypeDef *huart, uint8_t *data, uint16_t size) {
	GPIO_PinState cur_btn_state = Get_btn_state();
	static uint8_t is_send = 0;
	if (cur_btn_state == GPIO_PIN_SET){
		if (!is_send){
			HAL_UART_Transmit_IT(huart, data, size);
				is_send = 1;

		}
	}else
		is_send = 0;
}
