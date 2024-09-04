/*
 * LED.h
 *
 * Created: 22/02/2023
 *  Author: osama
 */

#ifndef LED_H_
#define LED_H_
#include "../../middle layer/EXTERNAL_INTRRUPT/EXT_INT.h"
// functions prototypes
void LED_init(uint8_t ledPort, uint8_t LedPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);

#endif /* LED_H_ */
