/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : APP_PROG			*/
/*  Layer	  : APP				    */
/*	Version	  :	1.1		  			*/
/*	Date	  :	October 8, 2022		*/
/*	Last Edit :	February 24, 2022	*/
/************************************/



#include "APP_interface.h"
#include "../HAL/LED/led.h"


	
APP_start(void);
	{
			//Traffic light
		DIO_SetPinDirection(DIO_PORTA, 0, DIO_OUTPUT);
		DIO_SetPinDirection(DIO_PORTA, 1, DIO_OUTPUT);
		DIO_SetPinDirection(DIO_PORTA, 2, DIO_OUTPUT);

		//Pedstrain Light
		DIO_SetPinDirection(DIO_PORTB, 0, DIO_OUTPUT);
		DIO_SetPinDirection(DIO_PORTB, 1, DIO_OUTPUT);
		DIO_SetPinDirection(DIO_PORTB, 2, DIO_OUTPUT);

		//Push Button
		DIO_SetPinDirection(DIO_PORTD, 2, DIO_INPUT);
		DIO_SetPinValue(DIO_PORTD, 2, DIO_HIGH);

		DIO_SetPinDirection(DIO_PORTD, 3, DIO_INPUT);
		DIO_SetPinDirection(DIO_PORTA, 0, DIO_OUTPUT);
		TIM_Init(TIM_TIMER0, TIMCLKSELECT_PRESCALAR_256, TIM_NORMAL, TIMHWPIN_DISCONNECTED);
		TIM_SetCallback(TIM_INT_T0_OVF, Blink);
		TIM_EnableInterrupt(TIM_INT_T0_OVF);
		TIM_TimerDelay(TIM_TIMER0, 2000);
		GIE_EnableGI();
		TIM_StartTimer(TIM_TIMER0);

		EXTI_Init(EXTI_INT0, EXTI_IOC);
		
		u8 CARLIGHT; 
		u8 previous_car;
		u8 Initial_MODE;
		previous_car =1;Initial_MODE=1;
			
		if(Initial_MODE || CARLIGHT==0 || CARLIGHT==1)
		{
				if(!Initial_MODE)
				{
					car=1;
				}
				DIO_SetPinValue(DIO_PORTB, 0, DIO_LOW);//green
				DIO_SetPinValue(DIO_PORTB, 1, DIO_LOW);//yellow
				//LED_OFF(DIO_PORTB , 0);
				//LED_OFF(DIO_PORTB , 1);
			
			
				
				if(CARLIGHT == 0)
				{
					DIO_SetPinValue(DIO_PORTB, 0, DIO_HIGH);
					DIO_SetPinValue(DIO_PORTB, 1, DIO_LOW);
					DIO_SetPinValue(DIO_PORTB, 2, DIO_LOW);
					//LED_ON(DIO_PORTB , 0);
			    	//LED_OFF(DIO_PORTB , 1);
			    	//LED_OFF(DIO_PORTB , 2);
					
					for(u8 i=0;i<50;i++)
					{
						TIM_TimerDelay(68);
						if(!Initial_MODE)
						{
							break;
						}
					}
				}
				CARLIGHT=1;
				previous_car=0;
				 
				else if(CARLIGHT == 1)
				{
					
					if(!Initial_MODE)
					{
						if(previous_car!=2){
							DIO_SetPinValue(DIO_PORTB, 2, DIO_HIGH);
							
							for(u8 i=0;i<5;i++)
							{
								//OR WE CAN USE LED BLINK FUNCTION
								//BLINK FUNCTION
								//YELLOW_LED_Blink();
								DIO_SetPinValue(DIO_PORTA, 1, DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB, 1, DIO_HIGH);
								//OR USE LED ON AND OFF 
								//LED_ON(DIO_PORTA , 1);
				                //LED_ON(DIO_PORTB , 1);
								TIM_TimerDelay(390);
								DIO_SetPinValue(DIO_PORTA, 1, DIO_LOW);
								DIO_SetPinValue(DIO_PORTB, 1, DIO_LOW);
								//LED_OFF(DIO_PORTA , 1);
				                //LED_OFF(DIO_PORTB , 1);
								TIM_TimerDelay(190);
								DIO_SetPinValue(DIO_PORTA, 1, DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB, 1, DIO_HIGH);
								//LED_ON(DIO_PORTA , 1);
				                //LED_ON(DIO_PORTB , 1);
								TIM_TimerDelay(390);
							}
						}
						previous_car=1;
						CARLIGHT=2;
						DIO_SetPinValue(DIO_PORTA, 2, DIO_HIGH);
					}
					else
					{
						
						for(u8 i=0;i<5;i++)
						{
							//LED_ON(DIO_PORTA , 1);
							DIO_SetPinValue(DIO_PORTA, 1, DIO_HIGH);
							TIM_TimerDelay(380);
							//LED_OFF(DIO_PORTA , 1);
							DIO_SetPinValue(DIO_PORTA, 1, DIO_LOW);
							TIM_TimerDelay(180);
							//LED_ON(DIO_PORTA , 1);
							DIO_SetPinValue(DIO_PORTA, 1, DIO_HIGH);
							TIM_TimerDelay(380);
							if(!Initial_MODE)
							{
								previous_car=1;
								break;
							}
						}
					}
					//LED_OFF(DIO_PORTA , 1);
					//LED_OFF(DIO_PORTB , 1);
					DIO_SetPinValue(DIO_PORTA, 1, DIO_LOW);
					DIO_SetPinValue(DIO_PORTB, 1, DIO_LOW);
				
					if(previous_car==0)
					{
						CARLIGHT=2;
						prevcarLED=1;
					}else if(previous_car==2){
						CARLIGHT=0;
						previous_car=1;
					}
					break;
				}
				
				else if(CARLIGHT == 2)
				{
					//LED_OFF(DIO_PORTA , 0);
					//LED_OFF(DIO_PORTA , 1);
					//LED_ON(DIO_PORTA , 2);
					DIO_SetPinValue(DIO_PORTA, 0, DIO_LOW);
					DIO_SetPinValue(DIO_PORTA, 1, DIO_LOW);
					DIO_SetPinValue(DIO_PORTA, 2, DIO_HIGH);
					for(u8 i=0;i<50;i++)
					{
						TIM_TimerDelay(68);
						if(!Initial_MODE)
						{
							break;
						}
					}
					previous_car=2;
					CARLIGHT=1;
					break;
				}
				else
				{
					carLED=2;
					prevcarLED=1;
					break;
				}
				
		}
		
			else
			{
				//Pedstrain LEDs
				DIO_SetPinValue(DIO_PORTB, 2, DIO_HIGH);
				DIO_SetPinValue(DIO_PORTB, 0, DIO_LOW);
				DIO_SetPinValue(DIO_PORTB, 1, DIO_LOW);
				
				//LED FUNCTION
				//LED_OFF(DIO_PORTB , 0);
				//LED_OFF(DIO_PORTB , 1);
				//LED_ON(DIO_PORTB , 2);
				
				//Configure CAR LEDs
				DIO_SetPinValue(DIO_PORTA, 1, DIO_LOW);
				DIO_SetPinValue(DIO_PORTA, 2, DIO_LOW);
				DIO_SetPinValue(DIO_PORTA, 0, DIO_HIGH);
				
				//LED FUNCTION
				//LED_ON(DIO_PORTA , 0);
				//LED_OFF(DIO_PORTA , 1);
				//LED_OFF(DIO_PORTA , 2);
				TIM_TimerDelay(5000);
				
				//CAR_red off
				//LED_OFF(DIO_PORTA , 0);
				DIO_SetPinValue(DIO_PORTA, 0, DIO_LOW);
				
				//PED_GREEN
				for(u8 i=0;i<5;i++)
				{
					//OR WE CAN USE LED BLINK FUNCTION
					//BLINK FUNCTION
					//YELLOW_LED_Blink();
					//OR USE LED ON AND OFF 
					//LED_ON(DIO_PORTA , 1);
					//LED_ON(DIO_PORTB , 1);
					DIO_SetPinValue(DIO_PORTA, 1, DIO_HIGH);
					DIO_SetPinValue(DIO_PORTB, 1, DIO_HIGH);
					TIM_TimerDelay(390);
					
					//LED_OFF(DIO_PORTA , 1);
				    //LED_OFF(DIO_PORTB , 1);
					DIO_SetPinValue(DIO_PORTA, 1, DIO_LOW);
					DIO_SetPinValue(DIO_PORTB, 1, DIO_LOW);
					TIM_TimerDelay(190);
					//LED_ON(DIO_PORTA , 1);
					//LED_ON(DIO_PORTB , 1);
					DIO_SetPinValue(DIO_PORTA, 1, DIO_HIGH);
					DIO_SetPinValue(DIO_PORTB, 1, DIO_HIGH);
					TIM_TimerDelay(390);
				}
				//off yellow  
				DIO_SetPinValue(DIO_PORTA, 1, DIO_LOW);
				DIO_SetPinValue(DIO_PORTB, 1, DIO_LOW);
				
				//LED FUNCTION
				//LED_OFF(DIO_PORTA , 1);
				//LED_OFF(DIO_PORTB , 1);
				
				// PED__RED_ON 
				DIO_SetPinValue(DIO_PORTB, 0, DIO_HIGH);
				//LED_OFF(DIO_PORTB, 0);
				
				//INIT
				Initial_MODE=1;
				
				CARLIGHT=0;
				previous_car=1;
			}
		
	}

