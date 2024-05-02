/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : DIO					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	October 8, 2022		*/
/*	Last Edit :	February 24, 2022	*/
/************************************/

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

typedef struct
{
	u8 PIN;
	u8 DDR;
	u8 PORT;
}GPIO_type;

#define GPIOA	((volatile GPIO_type*)0x39)
#define GPIOB	((volatile GPIO_type*)0x36)
#define GPIOC	((volatile GPIO_type*)0x33)
#define GPIOD	((volatile GPIO_type*)0x30)

#endif