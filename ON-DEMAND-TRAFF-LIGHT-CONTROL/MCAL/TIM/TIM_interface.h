/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : TIMER				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	February 24, 2022	*/
/************************************/

#ifndef _TIM_INTERFACE_H_
#define _TIM_INTERFACE_H_

#define TIM_TIMER0	0
#define TIM_TIMER1	1
#define TIM_TIMER2	2

#define TIMCLKSELECT_NO_CLOCK		    0 
#define TIMCLKSELECT_NO_PRESCALING	    1
#define TIMCLKSELECT_PRESCALAR_8		2
#define TIMCLKSELECT_PRESCALAR_64	    3
#define TIMCLKSELECT_PRESCALAR_256  	4
#define TIMCLKSELECT_PRESCALAR_1024	    5
#define TIMCLKSELECT_T0_FALLING		    6
#define TIMCLKSELECT_T0_RISING		    7

#define TIM_NORMAL			0
#define TIM_CTC				1
#define TIM_FASTPWM			2
#define TIM_PHASECORRECTPWM	3

#define TIMHWPIN_DISCONNECTED		0
#define TIMHWPIN_TOGGLE			1
#define TIMHWPIN_CLEAR			2
#define TIMHWPIN_SET				3
#define TIMHWPIN_NONINVERTING_PWM	2
#define TIMHWPIN_INVERTING_PWM	3

#define TIM_INT_T0_OVF		0
#define TIM_INT_T0_OCM		1
#define TIM_INT_T1_OVF		2
#define TIM_INT_T1_OCMB		3
#define TIM_INT_T1_OCMA		4
#define TIM_INT_T1_ICU		5
#define TIM_INT_T2_OVF		6
#define TIM_INT_T2_OCM		7

#ifndef F_CPU
#define F_CPU	1000000
#warning F_CPU not define, assuming 1MHz clock.
#endif

#define TIM_IO_CLOCK	F_CPU

void TIM_Init(u8 TimerNumber , u8 ClockSelect, u8 Mode, u8 HWPinMode);

void TIM_ForceOutputCompare(void);

void TIM_EnableInterrupt(u8 InterruptSource);

void TIM_DisableInterrupt(u8 InterruptSource);

void TIM_SetCallback(u8 InterruptSource, void (*UserFunction)(void));

void TIM_TimerDelay(u8 TimerNumber, u32 Delay);

void TIM_StartTimer(u8 TimerNumber);

void TIM_StopTimer(u8 TimerNumber);

void TIM_SetOCR(u8 TimerNumber, u16 OCRValue);

#endif