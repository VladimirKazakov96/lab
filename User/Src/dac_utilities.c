#include "dac_utilities.h"
#include "dac.h"
#include "gpio.h"
#include "main.h"

void Set_dac_volt_1st_ch(uint16_t mv){
	uint32_t dac_value;

	DAC_HandleTypeDef* ptr_hdac = Get_ptr_hdac();
	dac_value = 4095*mv/3275+15;
	HAL_DAC_SetValue(ptr_hdac,DAC_CHANNEL_1,DAC_ALIGN_12B_R,dac_value);

}
static uint8_t push_btn_cntr = 0;



void Increase_dac_volt_by_btn(){

	GPIO_PinState cur_btn_state;
	GPIO_PinState prev_btn_state;
	prev_btn_state = Get_value_btn_state();
	cur_btn_state = Get_btn_state();
	if (push_btn_cntr == 0 )
		Set_dac_volt_1st_ch(0);
	if (cur_btn_state == GPIO_PIN_SET && prev_btn_state == GPIO_PIN_RESET){
		push_btn_cntr++;
		if (push_btn_cntr < 5)
			Set_dac_volt_1st_ch (push_btn_cntr*500);
		else if (push_btn_cntr < 12)
			Set_dac_volt_1st_ch (2000 + 100*push_btn_cntr);
		else if (push_btn_cntr < 20)
			Set_dac_volt_1st_ch (3100 + ((push_btn_cntr-11)*25));
		else{
			Set_dac_volt_1st_ch(0);
			push_btn_cntr = 0;
		}

	}
}

