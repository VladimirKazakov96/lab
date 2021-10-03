#include "dac_utilities.h"
#include "dac.h"
#include "gpio.h"
#include "main.h"
#include "math.h"
#include "stm32f4xx_it.h"

static void Compose_ref_voltage(uint16_t mv_ampl);

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

uint16_t mv_per_sin[50];
float set_dac_val_time;
uint16_t kf = 0;

uint32_t dbg_m[100];
uint8_t i = 0;

uint8_t period_cntr = 0;

uint16_t Get_kf(){
	return kf;
}



void Set_harmonic_signal(uint16_t mv_ampl, uint16_t freq){
	static uint16_t prev_mv_ampl = 0;
	static uint16_t prev_freq = 0;
	if (mv_ampl != prev_mv_ampl){
		Compose_ref_voltage (mv_ampl);
		prev_mv_ampl = mv_ampl;
	}
	if (freq != prev_freq){
		kf = round(10000.0/freq)-1;
		prev_freq = freq;
	}

	if (Can_gen_dac_vol()){
		Reset_flag_gen_dac_vol();
		if (period_cntr != 49){
			dbg_m[i++] = DWT->CYCCNT/180;
			//Set_dac_volt_1st_ch(mv_per_sin[period_cntr++]);
		}else
			period_cntr = 0;
	}





}

static void Compose_ref_voltage(uint16_t mv_ampl){
	for (uint8_t i=0; i< 50; i++){
		mv_per_sin[i] = round(1500 + mv_ampl*sin(6.28/49*i));
	}
}

