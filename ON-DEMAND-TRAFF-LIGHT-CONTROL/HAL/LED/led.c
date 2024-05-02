/*
 * led.c
 *
 * Created: 1/5/2023 7:49:34 PM
 *  Author: hp
 */ 
#include "led.h"
#include <stdio.h>
#include  <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/LST_types.h"
#include "../../LIB/LBIT_math.h"

void LED_Init(u8 LED_PORT, u8 LED_PIN)
{
	
		DIO_Init(LED_PORT,LED_PIN,OUTPUT);
	
	
}
void LED_ON(u8 LED_PORT, u8 LED_PIN)
{
	DIO_SetPinDirection(LED_PORT,LED_PIN,DIO_OUTPUT);
	DIO_SetPinValue(LED_PORT,LED_PIN,DIO_HIGH);
}
void LED_OFF(u8 LED_PORT, u8 LED_PIN)
{
	DIO_SetPinDirection(LED_PORT,LED_PIN,DIO_OUTPUT);
	DIO_SetPinValue(LED_PORT,LED_PIN,DIO_LOW);
}
void LED_Toggle(u8 LED_PORT, u8 LED_PORT)
{
	u8 Value;
	Value = DIO_GetPinValue(LED_PORT,LED_PORT);
	if(Value == 1)
	{
		DIO_SetPinDirection(LED_PORT,LED_PIN,DIO_OUTPUT);
		DIO_SetPinValue(LED_PORT,LED_PIN,DIO_LOW);
	}
	else if(Value == 0)
	{
		DIO_SetPinDirection(LED_PORT,LED_PIN,DIO_OUTPUT);
		DIO_SetPinValue(LED_PORT,LED_PIN,DIO_HIGH);
	}
}
void YELLOW_LED_Blink();
{
		DIO_SetPinValue(DIO_PORTA, 1, DIO_HIGH);
		DIO_SetPinValue(DIO_PORTB, 1, DIO_HIGH);
		//LED_ON(DIO_PORTA , 1);
		//LED_ON(DIO_PORTB , 1);
		TIM_TimerDelay(390);
		DIO_SetPinValue(DIO_PORTA, 1, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, 1, DIO_LOW);
		//LED_OFF(DIO_PORTA , 1);
		//LED_OFF(DIO_PORTB , 1);
		TIM_TimerDelay(190);
		DIO_SetPinValue(DIO_PORTA, 1, DIO_HIGH);
		DIO_SetPinValue(DIO_PORTC, 1, DIO_HIGH);
		//LED_ON(DIO_PORTA , 1);
		//LED_ON(DIO_PORTB , 1);
		TIM_TimerDelay(390);
}