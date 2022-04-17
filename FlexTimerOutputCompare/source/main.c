/**
	\file
	\brief
		This project shows how to configure FlexTimer in output compare mode.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	7/09/2014
	\todo
	    Add configuration structures.
 */


#include "MK64F12.h" /* include peripheral declarations */
#include "GPIO.h"
#include "FlexTimer.h"
#include "NVIC.h"

//#include "GlobalFunctions.h"

/**
 * Output compare frequency = (bus clock)/(Prescaler(mod+1)).
 * Note that is the same frequency of the overflow flow.
 */

int main(void)
{
	 SIM->CLKDIV1 = 0x01240000U;
	/** Configuration for pin 1 on port c.
	 * Output compare is on option 4 in the pin control register*/
    SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTA|GPIO_CLOCK_GATING_PORTC;
	PORTC->PCR[1]   = PORT_PCR_MUX(0x4);

	/**Initialization of FlexTimer in output compare mode*/
	FlexTimer_Init();


	for(;;) {


	}

	return 0;
}
