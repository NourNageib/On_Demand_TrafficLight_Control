/*
 * led.h
 *
 * Created: 1/5/2023 7:49:22 PM
 *  Author: hp
 */ 


#ifndef LED_H_
#define LED_H_


void LED_Init(u8 LED_PORT, u8 LED_PIN)
void LED_ON(u8 LED_PORT, u8 LED_PIN)
void LED_OFF(u8 LED_PORT, u8 LED_PIN);
void LED_Toggle(u8 LED_PORT, u8 LED_PORT)
void YELLOW_LED_Blink(void);


#endif /* LED_H_ */