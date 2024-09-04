/*
 * DIO_int.h
 *
  * Created: 22/02/2023
  *  Author: osama
 */



#ifndef DIO_INT_H_
#define DIO_INT_H_
#include "../../lower layer/BitMath.h"

// macros for DIO ports
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
// macros for DIO pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
// macros for DIO direction
#define INPUT 0
#define OUTPUT 1
// macros for DIO value
#define LOW 0
#define HIGH 1

// functions prototypes
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

#endif /* DIO_INT_H_ */
