/*
 * TIMER0.c
 *
 * Created: 22/02/2023
 *  Author: osama
 */

#include "TIMER0.h"
uint8_t exitFlag = 0; // to skip current delay

void TIMER0_init(Prescaler prescaler, uint8_t preload)
{
	// initialize timer with preload value
	TCNT0_REG = preload;
	// set prescaler value according to choice
	TCCR0_REG = prescaler;
}
void TIMER0_start(int N, uint8_t preload)
{
	// start timer with calculated number of overflows and preload value
	// initialize counter with zero
	int N_counter = 0;
	// loop until counter exceeds number of overflows
	while (N_counter < N)
	{
		// check for exit flag
		if (exitFlag == 1)
		{
			exitFlag = 0;
			return;
		}
		// busy wait until timer overflows
		while (Get_Bit(TIFR_REG, 0) == 0)
			;
		// increment counter
		N_counter++;
		// set timer preload
		TIMER0_setPreload(preload);
		// clear ovof flag by setting to the flag
		Set_Bit(TIFR_REG, 0);
	}
}
void TIMER0_setPreload(uint8_t preload)
{
	// set preload to TCNT register
	TCNT0_REG = preload;
}
void TIMER0_stop(void)
{
	// remove clock source to stop timer
	TCCR0_REG = 0;
}
void TIMER0_reset(void)
{
	// reset timer to skip current delay
	exitFlag = 1;
}
void TIMER0_Delay(uint16_t TimeMs)
{
	// generate timer delay
	// first calculate number of overflows and preload from given time in ms
	int N = (((float)TimeMs / 1000.0) / (256 * (64.0 / 1000000.0)));
	uint8_t preload = 256 - (uint8_t)((float)(((float)TimeMs / 1000.0) / (256 * (1024.0 / 1000000.0))) / (float)N);
	// initialize timer with  prescaler
	TIMER0_init(Prescaler_64, preload);
	// start timer with given number of overfloas and preload value
	TIMER0_start(N, preload);
}
