/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : BUTTON				*/
/*  Layer	  : HAL 				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	October 8, 2022		*/
/*	Last Edit :	February 24, 2022	*/
/************************************/


#include "../../LIB/LSTD_types.h"
#include "../../LIB/LBIT_math.h"
#include "../../MCAL/DIO/DIO_interfce.h"
#include "button.h"


void ButtoN_Init(u8 Button_Port ,u8 Button_Pin);
{
	DIO_SetPinDirection(Button_Port,Button_Pin,DIO_OUTPUT);
}