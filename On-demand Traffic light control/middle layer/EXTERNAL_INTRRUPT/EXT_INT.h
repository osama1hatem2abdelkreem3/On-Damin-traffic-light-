/*
 * EXT_INT.h
 *
 * Created: 22/02/2023
 *  Author: osama
 */

#ifndef EXT_INT_H_
#define EXT_INT_H_
#include "../TIMER0_NORMAL/TIMER0.h"

// macros for interrupts vectors
#define INT0_vect __vector_1
#define INT1_vect __vector_2
#define INT2_vect __vector_3

// function like macros for ISR function
#define ISR(INT_VECT)                                  \
	void INT_VECT(void) __attribute__((signal, used)); \
	void INT_VECT(void)
// enum for interrupt sense control
typedef enum
{
	LowLevel = 0,
	AnyChange,
	FallingEdge,
	RisingEdge
} SenseControl;
// enum for interrupt choice
typedef enum
{
	INT0 = 0,
	INT1,
	INT2
} Interrupt;
// functions prototypes
void EXT_INT_init(Interrupt interupt, SenseControl senseControl);
void EXT_INT_enable(Interrupt interupt);
void EXT_INT_disble(Interrupt interupt);

#endif /* EXT_INT_H_ */
