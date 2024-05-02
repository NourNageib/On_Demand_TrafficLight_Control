/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : DIO					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	October 8, 2022		*/
/*	Last Edit :	February 24, 2022	*/
/************************************/

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "DIO_private.h"
#include "DIO_interface.h"

int main(void)
{
	while (1)
	{
		DIO_SetPinDirection(DIO_PORTA,0,DIO_OUTPUT);
	}
	return 0;
	
}
