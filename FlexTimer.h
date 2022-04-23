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

#define FLEX_TIMER_PS_1    (0U)
#define FLEX_TIMER_PS_2    (1U)
#define FLEX_TIMER_PS_4    (2U)
#define FLEX_TIMER_PS_8    (3U)
#define FLEX_TIMER_PS_16   (4U)
#define FLEX_TIMER_PS_32   (5U)
#define FLEX_TIMER_PS_64   (6U)
#define FLEX_TIMER_PS_128  (7U)

void FTM0_IRQHandler(); //Interruption for capture frequency
float get_Frequency(void); //Getter for frequency
void FlexTimer_Init(void); //Inicialization of FT


#endif /* FLEXTIMER_H_ */
