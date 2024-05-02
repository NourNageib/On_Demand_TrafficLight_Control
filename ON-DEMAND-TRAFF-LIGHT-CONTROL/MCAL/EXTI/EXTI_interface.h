/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : EXTI				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	October 8, 2022		*/
/*	Last Edit :	February 24, 2022	*/
/************************************/

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#define EXTI_INT0	6
#define EXTI_INT1	7
#define EXTI_INT2	5

#define EXTI_LOW		0
#define EXTI_IOC		1
#define EXTI_FALLING	2
#define EXTI_RISING	3

void EXTI_Init(u8 InterruptNumber, u8 InterruptMode);

void EXTI_EnableInterrupt(u8 InterruptNumber);

void EXTI_DisableInterrupt(u8 InterruptNumber);

void EXTI_SetCallBackINT0(void (*UserFunctionINT0)(void));

void EXTI_SetCallBackINT1(void (*UserFunctionINT1)(void));

void EXTI_SetCallBackINT2(void (*UserFunctionINT2)(void));

#endif
