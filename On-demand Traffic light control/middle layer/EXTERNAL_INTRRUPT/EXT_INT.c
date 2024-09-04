/*
 * EXT_INT.c
 *
  * Created: 22/02/2023
  *  Author: osama
 */
#include "EXT_INT.h"

//#include "../../lower layer/BitMath.h"
void EXT_INT_init(Interrupt interupt, SenseControl senseControl)
{
	// enable global interrupt
	Set_Bit(S_REG, 7);
	//select and enable chosen interrupt with chosen sense control
	//and initialize its corresponding pin
	switch (interupt)
	{
	case INT0:
		if (senseControl == FallingEdge)
		{
			DIO_write(PIN2, PORTD, HIGH);
		}
		DIO_init(PIN2, PORTD, INPUT);
		MCUCR_REG = senseControl;
		Set_Bit(GICR_REG, 6);
		break;
	case INT1:
		if (senseControl == FallingEdge)
		{
			DIO_write(PIN3, PORTD, HIGH);
		}
		DIO_init(PIN3, PORTD, INPUT);
		MCUCR_REG = (senseControl << 2);
		Set_Bit(GICR_REG, 7);
		break;
	case INT2:
		if (senseControl == FallingEdge)
		{
			DIO_write(PIN2, PORTB, HIGH);
		}
		DIO_init(PIN2, PORTB, INPUT);
		MCUCSR_REG |= ((senseControl & 0x01) << 6);
		Set_Bit(GICR_REG, 8);
		break;
	}
}
void EXT_INT_enable(Interrupt interupt)
{
	switch (interupt)
	{
	case INT0:
		Set_Bit(S_REG, 7);
		Set_Bit(GICR_REG, 6);
		break;
	case INT1:
		Set_Bit(S_REG, 7);
		Set_Bit(GICR_REG, 7);
		break;
	case INT2:
		Set_Bit(S_REG, 7);
		Set_Bit(GICR_REG, 8);
		break;
	}
}
void EXT_INT_disble(Interrupt interupt)
{
	switch (interupt)
	{
	case INT0:
		Clear_Bit(GICR_REG, 6);
		break;
	case INT1:
		Clear_Bit(GICR_REG, 7);
		break;
	case INT2:
		Clear_Bit(GICR_REG, 8);
		break;
	}
}
