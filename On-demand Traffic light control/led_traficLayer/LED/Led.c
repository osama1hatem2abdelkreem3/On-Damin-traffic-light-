/*
 * Led.c
 *
 * Created: 22/02/2023
 *  Author: osama
 */
#include "LED.h"
void LED_init(uint8_t ledPin, uint8_t ledPort)
{
	// initialize led pin to be output
	DIO_init(ledPin, ledPort, OUTPUT);
}
void LED_on(uint8_t ledPin, uint8_t ledPort)
{
	// set pin value high
	DIO_write(ledPin, ledPort, HIGH);
}
void LED_off(uint8_t ledPin, uint8_t ledPort)
{
	// set pin value low
	DIO_write(ledPin, ledPort, LOW);
}
void LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	// toggle pin
	DIO_toggle(ledPin, ledPort);
}
