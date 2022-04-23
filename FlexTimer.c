/**
	\file
	\brief
		This is the starter file of FlexTimer.
	\author Nelida Hernández
	\date	22/04/2022
 */

#include "FlexTimer.h"
#include "MK64F12.h"

#define ONE 1U
#define NOTHING 0U
#define DC 0.8
#define FREQ 20U

void FlexTimer_Init(void)
{
	/**Clock gating for FlexTimer*/
	SIM->SCGC6 |= SIM_SCGC6_FTM0(ONE);

	/**When write protection is enabled (WPDIS = 0), write protected bits cannot be written.
	* When write protection is disabled (WPDIS = 1), write protected bits can be written.*/
	FTM0->MODE |= FTM_MODE_WPDIS_MASK;

	/**Enables the writing over all registers*/
	FTM0->MODE &= ~FTM_MODE_FTMEN_MASK;

	/**Assigning an specific value for modulo register to get 1 MHz of frequency*/
	FTM0->MOD = FREQ;

	/**Selects the Edge-Aligned PWM mode mode*/
	FTM0->CONTROLS[0].CnSC = FTM_CnSC_MSA(NOTHING) | FTM_CnSC_MSB(ONE) | FTM_CnSC_ELSB(ONE) | FTM_CnSC_ELSA(NOTHING);

	/**Assign a duty cycle of 80%*/
	FTM0->CONTROLS[0].CnV = FTM0->MOD*DC;

	/**Configure the times*/
	FTM0->SC |= FTM_SC_CLKS(FLEX_TIMER_CLKS_1)| FTM_SC_PS(FLEX_TIMER_PS_1);
}
