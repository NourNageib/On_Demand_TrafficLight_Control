/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : DIO					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	October 8, 2022		*/
/*	Last Edit :	February 24, 2022	*/
/************************************/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#define DIO_PORTA	27
#define DIO_PORTB	10
#define DIO_PORTC	19
#define DIO_PORTD	99

#define DIO_OUTPUT	123
#define DIO_INPUT	100
#define DIO_PullUp	197

#define DIO_HIGH	111
#define DIO_LOW	140

typedef enum EN_Error_t
{
    OK, ERROR
}EN_Error_t;

EN_Error_t DIO_SetPortDirection(u8 Port, u8 Direction);
EN_Error_t DIO_SetPortValue(u8 Port, u8 Value);
u8	 DIO_GetPortValue(u8 Port);

EN_Error_t DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
EN_Error_t DIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8	 DIO_GetPinValue(u8 Port, u8 Pin);

#endif