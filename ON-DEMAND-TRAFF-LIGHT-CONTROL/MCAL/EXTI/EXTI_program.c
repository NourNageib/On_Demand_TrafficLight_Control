/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : EXTI				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	October 8, 2022		*/
/*	Last Edit :	February 24, 2022	*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"

void (*EXTI_UserFunctionINT0)(void) = 0;
void (*EXTI_UserFunctionINT1)(void) = 0;
void (*EXTI_UserFunctionINT2)(void) = 0;

void EXTI_Init(u8 Interruptumber, u8 InterruptMode)
{
	switch(InterruptMode)
	{
		case EXTI_LOW:
		{
			switch(Interruptumber)
			{
				case EXTI_INT0:
				{
					CLEAR_BIT(MCUCR, ISC00);
					CLEAR_BIT(MCUCR, ISC01);
					break;
				}
				case EXTI_INT1:
				{
					CLEAR_BIT(MCUCR, ISC10);
					CLEAR_BIT(MCUCR, ISC11);
					break;
				}
				default: 
				{
					break; //Error
				}
			}
			break;
		}
		case EXT_IOC:
		{
			switch(Interruptumber)
			{
				case EXTI_INT0:
				{
					SET_BIT(MCUCR, ISC00);
					CLEAR_BIT(MCUCR, ISC01);
					break;
				}
				case EXTI_INT1:
				{
					SET_BIT(MCUCR, ISC10);
					CLEAR_BIT(MCUCR, ISC11);
					break;
				}
				default: break; //Error
			}
			break;
		}
		case EXTI_FALLING:
		{
			switch(Interruptumber)
			{
				case EXTI_INT0:
				{
					SET_BIT(MCUCR, ISC01);
					CLEAR_BIT(MCUCR, ISC00);
					break;
				}
				case EXTI_INT1:
				{
					SET_BIT(MCUCR, ISC11);
					CLEAR_BIT(MCUCR, ISC10);
					break;
				}
				case EXTI_INT2:
				{
					CLEAR_BIT(MCUCSR, ISC2);
					break;
				}
				default:
				{
					break; //Error
				}
			}
			break;
		}
		case EXTI_RISING:
		{
			switch(Interruptumber)
			{
				case EXTI_INT0:
				{
					SET_BIT(MCUCR, ISC00);
					SET_BIT(MCUCR, ISC01);
					break;
				}
				case EXTI_INT1:
				{
					SET_BIT(MCUCR, ISC10);
					SET_BIT(MCUCR, ISC11);
					break;
				}
				case EXTI_INT2:
				{
					SET_BIT(MCUCSR, ISC2);
					break;
				}
				default: 
				{
					break; //Error
				}
			}
			break;
		}
		default: break; //Error
	}
}

void EXTI_EnableInterrupt(u8 Interruptumber)
{
	SET_BIT(GICR, Interruptumber);
}

void EXTI_DisableInterrupt(u8 Interruptumber)
{
	CLEAR_BIT(GICR, Interruptumber);
}

void EXTI_SetCallBackINT0(void (*UserFunctionINT0)(void))
{
	EXTI_UserFunctionINT0 = UserFunctionINT0;
}

void EXTI_SetCallBackINT1(void (*UserFunctionINT1)(void))
{
	EXTI_UserFunctionINT1 = UserFunctionINT1;
}

void EXTI_SetCallBackINT2(void (*UserFunctionINT2)(void))
{
	EXTI_UserFunctionINT2 = UserFunctionINT2;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	(*EXTI_UserFunctionINT0)();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	(*EXTI_UserFunctionINT1)();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	(*EXTI_UserFunctionINT2)();
}
