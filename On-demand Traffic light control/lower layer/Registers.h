/*
 * Registers.h
 *
  * Created: 22/02/2023
  *  Author: osama
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "Types.h"
// DIO_Reegisters
#define PORTA_REG *((volatile uint8_t *)0x3B)
#define DDRA_REG *((volatile uint8_t *)0x3A)
#define PINA_REG *((volatile uint8_t *)0x39)

#define PORTB_REG *((volatile uint8_t *)0x38)
#define DDRB_REG *((volatile uint8_t *)0x37)
#define PINB_REG *((volatile uint8_t *)0x36)

#define PORTC_REG *((volatile uint8_t *)0x35)
#define DDRC_REG *((volatile uint8_t *)0x34)
#define PINC_REG *((volatile uint8_t *)0x33)

#define PORTD_REG *((volatile uint8_t *)0x32)
#define DDRD_REG *((volatile uint8_t *)0x31)
#define PIND_REG *((volatile uint8_t *)0x30)

// TIMER0 Registers

#define TIMSK_REG *((volatile uint8_t *)0x59)
#define TCCR0_REG *((volatile uint8_t *)0x53)
#define TCNT0_REG *((volatile uint8_t *)0x52)
#define TIFR_REG *((volatile uint8_t *)0x58)

// External Interrupt Registers
#define MCUCR_REG *((volatile uint8_t *)0x55)
#define MCUCSR_REG *((volatile uint8_t *)0x54)
#define GICR_REG *((volatile uint8_t *)0x5B)

#define S_REG *((volatile uint8_t *)0x5F)
#endif /* REGISTERS_H_ */