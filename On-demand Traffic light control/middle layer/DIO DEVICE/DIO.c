/*
 * DIO_prog.c
 *
  * Created: 22/02/2023
  *  Author: osama
 */
#include "DIO.h"



void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	// check for pin direction
	switch (direction)
	{
	case OUTPUT:
		// check for port number
		switch (portNumber)
		{
		// set the selected pin in the selected port DDR register
		// so the pin became output
		case PORTA:
			Set_Bit(DDRA_REG, pinNumber);
			break;
		case PORTB:
			Set_Bit(DDRB_REG, pinNumber);
			break;
		case PORTC:
			Set_Bit(DDRC_REG, pinNumber);
			break;
		case PORTD:
			Set_Bit(DDRD_REG, pinNumber);
			break;
		}
		break;
	case INPUT:
		switch (portNumber)
		{
		// clear the selected pin in the selected port DDR register
		// so the pin became input
		case PORTA:
			Clear_Bit(DDRA_REG, pinNumber);
			break;
		case PORTB:
			Clear_Bit(DDRB_REG, pinNumber);
			break;
		case PORTC:
			Clear_Bit(DDRC_REG, pinNumber);
			break;
		case PORTD:
			Clear_Bit(DDRD_REG, pinNumber);
			break;
		}
		break;
	}
}
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{

	switch (value)
	{
	// check for pin value
	case HIGH:
		// check for port number
		switch (portNumber)
		{

		// set the selected pin in the selected port PORT register
		// so the pin value became high
		case PORTA:
			Set_Bit(PORTA_REG, pinNumber);
			break;
		case PORTB:
			Set_Bit(PORTB_REG, pinNumber);
			break;
		case PORTC:
			Set_Bit(PORTC_REG, pinNumber);
			break;
		case PORTD:
			Set_Bit(PORTD_REG, pinNumber);
			break;
		}
		break;
	case LOW:
		switch (portNumber)
		{
		// clear the selected pin in the selected port PORT register
		// so the pin value became low
		case PORTA:
			Clear_Bit(PORTA_REG, pinNumber);
			break;
		case PORTB:
			Clear_Bit(PORTB_REG, pinNumber);
			break;
		case PORTC:
			Clear_Bit(PORTC_REG, pinNumber);
			break;
		case PORTD:
			Clear_Bit(PORTD_REG, pinNumber);
			break;
		}
		break;
	}
}
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	switch (portNumber)
	{
	// check for port number
	// toggle the selected pin in the selected port PORT register
	case PORTA:
		Toggle_Bit(PORTA_REG, pinNumber);
		break;
	case PORTB:
		Toggle_Bit(PORTB_REG, pinNumber);
		break;
	case PORTC:
		Toggle_Bit(PORTC_REG, pinNumber);
		break;
	case PORTD:
		Toggle_Bit(PORTD_REG, pinNumber);
		break;
	}
}
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	// check for port number
	switch (portNumber)
	{
	// get pin value for selected port PIN register
	//  and assign the value to given address
	case PORTA:
		*value = Get_Bit(PINA_REG, pinNumber);
		break;
	case PORTB:
		*value = Get_Bit(PINB_REG, pinNumber);
		break;
	case PORTC:
		*value = Get_Bit(PINC_REG, pinNumber);
		break;
	case PORTD:
		*value = Get_Bit(PIND_REG, pinNumber);
		break;
	}
}
