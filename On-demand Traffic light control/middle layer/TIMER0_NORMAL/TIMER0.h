/*
 * TIMER0.h
 *
  * Created: 22/02/2023
  *  Author: osama
 */
#ifndef TIMER0_H_
#define TIMER0_H_

#include "../DIO DEVICE/DIO.h"
// enum for prescaler choice
typedef enum
{
	NoClkSource = 0,
	Prescaler_1,
	Prescaler_8,
	Prescaler_64,
	Prescaler_254,
	Prescaler_1024
} Prescaler;
// functions prototypes
void TIMER0_init(Prescaler prescaler, uint8_t preload);
void TIMER0_start(int N, uint8_t preload);
void TIMER0_setPreload(uint8_t preload);
void TIMER0_stop(void);
void TIMER0_reset(void);
void TIMER0_Delay(uint16_t TimeMs);

#endif /* TIMER0_H_ */
