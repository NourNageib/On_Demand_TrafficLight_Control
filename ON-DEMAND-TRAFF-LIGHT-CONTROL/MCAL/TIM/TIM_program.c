/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : TIMER				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	February 24, 2022	*/
/************************************/

#include "../../LIB/LSTD_types.h"
#include "../../LIB/LBIT_math.h"

#include "TIM_interface.h"
#include "TIM_private.h"

u8 TIM_Timer0CLK;
u8 TIM_Timer1CLK;
u8 TIM_Timer2CLK;

u16 TIM_Timer0OVFCount = 0;
u16 TIM_Timer1OVFCount = 0;
u16 TIM_Timer2OVFCount = 0;
u8  TIM_Timer0Preload = 0;
u16 TIM_Timer1Preload = 0;
u8  TIM_Timer2Preload = 0;

void (*TIM_UserFunctionT0OVF)(void) = 0;
void (*TIM_UserFunctionT0OCM)(void) = 0;
void (*TIM_UserFunctionT1OVF)(void) = 0;
void (*TIM_UserFunctionT1OCMB)(void) = 0;
void (*TIM_UserFunctionT1OCMA)(void) = 0;
void (*TIM_UserFunctionT1ICU)(void) = 0;
void (*TIM_UserFunctionT2OVF)(void) = 0;
void (*TIM_UserFunctionT2OCM)(void) = 0;

void TIM_Init(u8 TimerNumber , u8 ClockSelect, u8 Mode, u8 HWPinMode)
{
	
		if(TimerNumber ==TIM_TIMER0)
		{
			switch(Mode)
			{
				case TIM_NORMAL:
				{
					CLEAR_BIT(TCCR0, WGM01);
					CLEAR_BIT(TCCR0, WGM00);
					break;
				}
				case TIM_CTC:
				{
					SET_BIT(TCCR0, WGM01);
					CLEAR_BIT(TCCR0, WGM00);
					break;
				}
				case TIM_FASTPWM:
				{
					SET_BIT(TCCR0, WGM01);
					SET_BIT(TCCR0, WGM00);
					break;
				}
				case TIM_PHASECORRECTPWM:
				{
					CLEAR_BIT(TCCR0, WGM01);
					SET_BIT(TCCR0, WGM00);
					break;
				}
				default:
				{
					// Error
					break;
				}
			}
			TCCR0 &= 0b11001111;
			TCCR0 |= ((HWPinMode & 0b00000011) << 4);
			TIM_Timer0CLK = ClockSelect;

		}
		
		else if(TimerNumber == TIM_TIMER1)
		{
			
		}
		else if(TimerNumber == TIM_TIMER2)
		{
			
		}
		
		
		

}

void TIM_ForceOutputCompare(void)
{
	SET_BIT(TCCR0, FOC0);
}

void TIM_EnableInterrupt(u8 InterruptSource)
{

	SET_BIT(TIMSK, InterruptSource);
}

void TIM_DisableInterrupt(u8 InterruptSource)
{
	CLEAR_BIT(TIMSK, InterruptSource);
}

void TIM_SetCallback(u8 InterruptSource, void (*UserFunction)(void))
{
		if(InterruptSource == TIM_INT_T0_OVF)
		{
			TIM_UserFunctionT0OVF = UserFunction;

		}
		else if(InterruptSource == TIM_INT_T0_OCM)
		{
		    TIM_UserFunctionT0OCM = UserFunction;

		}
		else
		{
			//  an Error

		}
	}


void TIM_StartTimer(u8 TimerNumber)
{
		if(TimerNumber == TIM_TIMER0)
		{
			TCCR0 &= 0b11111000;
			TCCR0 |= (TIM_Timer0CLK & 0b00000111);

		}
		
		else 
		{
			//Report an Error

		}
	
}

void TIM_StopTimer(u8 TimerNumber)
{
	switch(TimerNumber)
	{
		case TIM_TIMER0:
		{
			TCCR0 &= 0b11111000;
			break;
		}
		case TIM_TIMER1:
		{
			
			break;
		}
	
		default:
		{
			
			break;//report an error
		}
	}
}

void TIM_SetOCR(u8 TimerNumber, u16 OCRValue)
{
	 if(TimerNumber == TIM_TIMER0)
		{
			OCR0 = (u8)OCRValue;

		}
		else if(TimerNumber == TIM_TIMER1)
		{
			
		}
		else if(TimerNumber == TIM_TIMER2)
		{
			
		}
		else
		{
           //report an error
		}
	}


void TIM_TimerDelay(u8 TimerNumber, u32 Delay)
{
	f32 TickTime, OVFTime;
	u16 Prescalar;
	
	switch(TimerNumber)
	{
		case TIM_TIMER0:
		{
			switch(TIM_Timer0CLK)
			{
				case TIMCLKSELECT_NO_PRESCALING: 
				{
					Prescalar = 1;
					break;
				}
				case TIMCLKSELECT_PRESCALAR_8:	
				{
					Prescalar = 8;
					break;
				}
				case TIMCLKSELECT_PRESCALAR_64:
				{
					Prescalar = 64; 
					break;
				}
				case TIMCLKSELECT_PRESCALAR_256:
				{
					Prescalar = 256; 
					break;
				}
				case TIMCLKSELECT_PRESCALAR_1024: 
				{
					Prescalar = 1024;
					break;
				}
			}
			TickTime = (f32)Prescalar / TIM_IO_CLOCK;
			OVFTime  =TickTime * 256;
			TIM_Timer0OVFCount = (u16)((Delay / 1000) / OVFTime);
			TIM_Timer0Preload = 256 - ((Delay / 1000) % (u32)OVFTime);
			TCNT0 = TIM_Timer0Preload;
			break;
		}
		default:
		{
			//Report an Error
			break;
		}
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static volatile u8 OVFCounter = 0;
	if(OVFCounter < TIM_Timer0OVFCount)
	{
		OVFCounter++;
	}
	else
	{
		TCNT0 = TIM_Timer0Preload;
		OVFCounter = 0;
		(*TIM_UserFunctionT0OVF)();
	}
}
