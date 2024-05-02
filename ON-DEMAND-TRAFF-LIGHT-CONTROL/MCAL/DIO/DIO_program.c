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

void DIO_SetPortDirection(u8 Port, u8 Direction)
{
	
		if( Port == DIO_PORTA)
		{
			GPIOA -> DDR = Direction; 

		}
		else if( Port == DIO_PORTB)
		{
			GPIOB -> DDR = Direction; 

		}
		else if( Port == DIO_PORTC) 
		{
			GPIOC -> DDR = Direction;

		}
		else if( Port == DIO_PORTD)
		{
			GPIOD -> DDR = Direction;

		}
		else 	
		{

		}

}

void DIO_SetPortValue(u8 Port, u8 Value)
{
	switch(Port)
	{
		case DIO_PORTA:
		{
			GPIOA -> PORT = Value;
			break;
		}
		case DIO_PORTB: 
		{
			GPIOB -> PORT = Value; 
			break;
		}
		case DIO_PORTC: 
		{
			GPIOC -> PORT = Value;
			break;
		}
		case DIO_PORTD:
		{
			GPIOD -> PORT = Value;
			break;
		}
		default: 		
		{
			break;
			//report an error
		}
	}
}

u8	 DIO_GetPortValue(u8 Port)
{
	u8 Value;
	switch(Port)
	{
		case DIO_PORTA: 
		{
			Value = GPIOA -> PIN;
			break;
		}
		case DIO_PORTB: 
		{
			Value = GPIOB -> PIN; 
			break;
		}
		case DIO_PORTC:
		{
			Value = GPIOC -> PIN;
			break;
		}
        case DIO_PORTD: 
		{
			Value = GPIOD -> PIN;
			break;
		}
        default:
		{
			Value = 0; 
			break;
		}			
	}
	return Value;
}


void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
	if(Pin>=0 && Pin<=7)
	{
		if(DIO_OUTPUT == Direction)
		{
			
			
				if(Port == DIO_PORTA) 
				{
					SET_BIT(GPIOA -> DDR, Pin);

				}
				else if(Port == DIO_PORTB) 
				{
				SET_BIT(GPIOB -> DDR, Pin);

				}
				else if(Port == DIO_PORTC) 
				{
					SET_BIT(GPIOC -> DDR, Pin);

				}
				else if(Port == DIO_PORTD)
				{
					SET_BIT(GPIOD -> DDR, Pin);

				}
				else  
				{
					//report an error
				}
			
		}
		else if(DIO_INPUT == Direction)
		{
			    if(Port == DIO_PORTA)
				{					
					CLEAR_BIT(GPIOA -> DDR, Pin); 

				}
			    else if(Port == DIO_PORTB)
				{
					CLEAR_BIT(GPIOB -> DDR, Pin); 

				}
			    else if(Port == DIO_PORTC)
				{
					CLEAR_BIT(GPIOC -> DDR, Pin);

				}

			    else if(Port == DIO_PORTD)
				{
					CLEAR_BIT(GPIOD -> DDR, Pin);

				}
				else
				{
					//report an error
				}
			
		}
		else if(DIO_PullUp == Direction)
		{
			switch(Port)
			{
				case DIO_PORTA:
				{
					CLEAR_BIT(GPIOA -> DDR, Pin); 
					SET_BIT(GPIOA -> PORT, Pin); 
					break;
				}
				case DIO_PORTB:
				{
					CLEAR_BIT(GPIOB -> DDR, Pin); 
					SET_BIT(GPIOB -> PORT, Pin);
					break;
				}
				case DIO_PORTC: 
				{
					CLEAR_BIT(GPIOC -> DDR, Pin); 
					SET_BIT(GPIOC -> PORT, Pin);
					break;
				}
				case DIO_PORTD:
				{
					CLEAR_BIT(GPIOD -> DDR, Pin);
					SET_BIT(GPIOD -> PORT, Pin); 
					break;
				}
				default:
				{
					break; 
				}
			}
		}
		else
		{
		}
	}
	else
	{
		
	}
}

void DIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
	if(Pin>=0 && Pin<=7)
	{
		if(DIO_HIGH == Value)
		{
			switch(Port)
			{
				case DIO_PORTA: 
				{
					SET_BIT(GPIOA -> PORT, Pin);
					break;
				}
				case DIO_PORTB: 
				{
					SET_BIT(GPIOB -> PORT, Pin);
					break;
				}
				case DIO_PORTC:
				{

					SET_BIT(GPIOC -> PORT, Pin); 
					break;
				}
				case DIO_PORTD:
				{
					SET_BIT(GPIOD -> PORT, Pin);
					break;
				}
				default:
				{
				   break;//report an error 
				}
			}
		}
		else if(DIO_LOW == Value)
		{
			
				if( DIO_PORTA == Value)
				{
					CLEAR_BIT(GPIOA -> PORT, Pin);

				}
				else if( DIO_PORTB == Value)
				{
					CLEAR_BIT(GPIOB -> PORT, Pin);

				}
				else if( DIO_PORTC == Value)
				{
					CLEAR_BIT(GPIOC -> PORT, Pin);

				}
				else if ( DIO_PORTD == Value) 
				{
					CLEAR_BIT(GPIOD -> PORT, Pin);

				}
				
			}
		
		else
		{
			// an Error
		}
	}
	else
	{
		// an Error
	}
}

u8	 DIO_GetPinValue(u8 Port, u8 Pin)
{
	u8 Value;
	if((Pin>=0) && (Pin<=7))
	{
		switch(Port)
		{
			case DIO_PORTA:
			{
				Value = GET_BIT(GPIOA -> PIN, Pin);
				break;
			}
			case DIO_PORTB:
			{
				Value = GET_BIT(GPIOB -> PIN,Pin);
				break;
			}
			case DIO_PORTC:
			{
				Value = GET_BIT(GPIOC -> PIN, Pin);
				break;
			}
			case DIO_PORTD: 
			{
				Value = GET_BIT(GPIOD -> PIN, Pin); 
				break;
			}
			default:
			{
				Value = 0;
				break;
			}				
		}
	}
	else
	{
		// Error
	}
	return Value;
}
