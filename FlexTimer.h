/**
	\file
	\brief
		This is the starter file of FlexTimer.
	\author Nelida Hernández
	\date	22/04/2022
 */

#ifndef FLEXTIMER_H_
#define FLEXTIMER_H_


#include "MK64F12.h"

#define FLEX_TIMER_CLKS_0  (0U)
#define FLEX_TIMER_CLKS_1  (1U)
#define FLEX_TIMER_CLKS_2  (2U)
#define FLEX_TIMER_CLKS_3  (3U)

void FlexTimer_update_channel_value(float channel_value); //Update of the value
void FlexTimer_Init(void); //Initialization of FT


#endif /* FLEXTIMER_H_ */
