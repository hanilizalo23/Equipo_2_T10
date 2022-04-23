/**
	\file
	\brief
		This is the starter file of FlexTimer.
	\author Nelida Hernández
	\date	22/04/2022

 */

#include "FlexTimer.h"
#include "MK64F12.h"

void FTM0_IRQHandler()
{
	if(FTM0->STATUS & 0x01)
	{

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
