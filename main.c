/**
	\file
	\brief
		Output as PWM
	\author Mauricio Peralta Osorio
	\date	22/04/2022
 */

#include <stdio.h>
#include "MK64F12.h"
#include "GPIO.h"
#include "FlexTimer.h"
#include "NVIC.h"
#include "stdint.h"
#include "Bits.h"
#include "Delay.h"

#define clock_frequency 21000000

#define DELAY_CONST 650 //Delay for push buttons

#define INCREASE15 1.15
#define DECREASE5  0.95
#define ONE        1U

int main(void)
{
	//For 1 MHz
	float mod_register_value = 20;
	double frequency = 1000000;

	//Configuration for GPIOs and CLKs
	gpio_pin_control_register_t g_pcr_gpio_ftm = GPIO_MUX4;
	gpio_pin_control_register_t	pcr_pin_a_4 = GPIO_MUX1|GPIO_PE|GPIO_PS;
	gpio_pin_control_register_t	pcr_pin_a_6 = GPIO_MUX1|GPIO_PE|GPIO_PS;

	GPIO_clock_gating(GPIO_A);
	GPIO_clock_gating(GPIO_C);

	GPIO_pin_control_register(GPIO_C, bit_1, &g_pcr_gpio_ftm);
	GPIO_pin_control_register(GPIO_A, bit_4, &pcr_pin_a_4);
	GPIO_pin_control_register(GPIO_C, bit_6, &pcr_pin_a_6);

	GPIO_data_direction_pin(GPIO_C,GPIO_INPUT, bit_6);
	GPIO_data_direction_pin(GPIO_A,GPIO_INPUT, bit_4);

	//Configuration function for FlexTimer
	FlexTimer_Init();

	while(1) {

	}
	return 0;
}
