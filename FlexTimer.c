/**
	\file
	\brief
		This is the starter file of FlexTimer.
	\author Nelida Hernández
	\date	22/04/2022

 */

#include "FlexTimer.h"
#include "MK64F12.h"

uint32_t previous_value = 0;
uint32_t current_value = 0;
float frequency= 0;
const float FTMCK = 164062.5; //Needed for the edge caption

void FTM0_IRQHandler()
{
	if(FTM0->STATUS & 0x01)
	{
		previous_value = current_value;
		current_value = FTM0->CONTROLS[0].CnV; /*We read the value of the register, which has difference between rising edges*/

		/*We apply the calculation of the frequency*/
		frequency =  1/((current_value - previous_value)*(1/FTMCK));
		FTM0->STATUS &= 0xFE;
	}
	/**Clearing the overflow interrupt flag*/
	FTM0->SC &= ~ FTM_SC_TOF_MASK;
}


void FlexTimer_Init(void)
{
	/**Clock gating for FlexTimer*/
	SIM->SCGC6 |= SIM_SCGC6_FTM0(1);

	/*We make sure to have the rising edge capture mode*/
	FTM0->COMBINE = 0x00;

	/**Configure FlexTimer in input capture in rising edge and  to generate an interrupt*/
	FTM0->CONTROLS[0].CnSC |=  FTM_CnSC_CHIE(1) | FTM_CnSC_ELSA(1);

	/**Select clock source and prescaler*/
	FTM0->SC = FTM_SC_CLKS (FLEX_TIMER_CLKS_1)| FTM_SC_PS(FLEX_TIMER_PS_128);

	/*Make sure to enable interrupts*/
	FTM0->SC |= FTM_SC_TOIE_MASK;
}
