/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : GIE 				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	October 8, 2022		*/
/*	Last Edit :	February 24, 2022	*/
/************************************/

#include "../../1- LIB/LBIT_math.h"
#include "../../1- LIB/LSTD_types.h"

#include "GIE_interface.h"
#include "GIE_private.h"

void GIE_EnableGI(void)
{
	SET_BIT(SREG, IBIT);
}

void GIE_DisableGI(void)
{
	CLEAR_BIT(SREG, IBIT);
}