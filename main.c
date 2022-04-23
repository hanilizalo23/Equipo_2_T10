/**
	\file
	\brief
		Input compare
	\author Nelida Hernández
	\date	22/04/2022
 */

#include "MK64F12.h"
#include "GPIO.h"
#include "FlexTimer.h"
#include "NVIC.h"
#include "Delay.h"
#include "Bits.h"
#include "UART_driver.h"

int main(void)
{
	//Configuration for pin 1 on port C as input
	gpio_pin_control_register_t	pinControlRegisterPORTC = GPIO_MUX4 | GPIO_PE | GPIO_PS;
	GPIO_clock_gating(GPIO_C);
	GPIO_pin_control_register(GPIO_C, bit_1, &pinControlRegisterPORTC);
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, bit_1);

	//Configuration function for FlexTimer
	FlexTimer_Init();

	//Interruption
	NVIC_enable_interrupt_and_priotity(FTM0_IRQ,PRIORITY_9);
	NVIC_global_enable_interrupts;

	while(1)
	{
		UART_write_freq();
		delay(50000);

//		#ifndef DEBUG_ON
//			printf("Frecuencia: %f\n", frequency);
//		#endif
	}
	return 0;
}
