/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : EXTI				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	October 8, 2022		*/
/*	Last Edit :	February 24, 2022	*/
/************************************/

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#define MCUCR 	*((volatile u8*)0x55)
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

#define MCUCSR 	*((volatile u8*)0x54)
#define ISC2	6

#define GICR	*((volatile u8*)0x5B)
#define INT0	6
#define INT1	7
#define INT2	5

#define GIFR	*((volatile u8*)0x5A)
#define INTF1	7
#define INTF0	6
#define INTF2	5

#endif
