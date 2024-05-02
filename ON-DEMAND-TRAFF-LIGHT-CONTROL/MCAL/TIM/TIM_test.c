/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : TIMER				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	February 24, 2022	*/
/************************************/


#define F_CPU  8000000UL
#include "../../LIB/LSTD_types.h"
#include "../../LIB/LBIT_math.h"
#include "../DIO/DIO_interface.h"
#include "TIM_interface.h"
#include "../GIE/GIE_interface.h"
void Blink (void);
int main(void)
{

	DIO_SetPinDirection(DIO_PORTA,0,DIO_OUTPUT);
	TIM_Init(TIM_TIMER0,TIMCLKSELECT_PRESCALAR_256,TIM_NORMAL,TIMHWPIN_DISCONNECTED);
	TIM_SetCallback(TIM_INT_T0_OVF,Blink);
	TIM_EnableInterrupt(TIM_INT_T0_OVF);
	TIM_TimerDelay(TIM_TIMER0,2000);
	GIE_EnableGI();
    TIM_StartTimer(TIM_TIMER0);
	while (1);
	return 0;
}
void Blink (void)
{
	if (DIO_GetPinValue(DIO_PORTA,0))
	{
		DIO_SetPinValue(DIO_PORTA,0,DIO_LOW);
	}

	else
	{
		DIO_SetPinValue(DIO_PORTA,0,DIO_HIGH);
	}

}
