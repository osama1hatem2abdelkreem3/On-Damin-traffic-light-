/*
 * app.c
 *
  * Created: 22/02/2023
  *  Author: osama
 */

#include "app.h"
ISR(INT0_vect)
{
	// delay to detect long press and make no action
	uint8_t value;
	TIMER0_Delay(500);
	DIO_read(PIN2, PORTD, &value);
	if (value == 0)
	{
		// long press detected
		// nothing here
		// return immediately to continue normal mode
	}
	else
	{
		// there is on long press
		// check for current state (cars)
		uint8_t currentMode = T_Lights_CurrentMode();
		if (currentMode == CARS_GREEN || currentMode == CARS_YELLOW)
		{
			
			// if cars state is green or yellow
			/********************************************/
			// turn peds red on 
			PedsRedEnable();
			//turn car green off
			CarsGreenDisable();
			// blink yellow for 5 secs
			BothSteady();
			// turn  peds red off and turn peds green on
			PedsRedDisable();
			PedsGreenEnable();
			// turn cars red on and turn cars green off
			CarsRedEnable();
			CarsGreenDisable();
			// wait for 5 secs
			TIMER0_Delay(5000);
			//turn car red off
			CarsRedDisable();
			// blink both yellow leds for 5 secs
			BothSteady();
			/********************************************/
			// turn all leds of
			TurnAllOff();
			// reset timer to escape after return
			TIMER0_reset();
			// reset normal mode to beginning
			ResetNormalMode();
			/********************************************/
		}
		else if (T_Lights_CurrentMode() == CARS_RED)
		{
			// if cars state is  red
			/********************************************/
			//turn peds green on
			PedsGreenEnable();
			// turn cars red on and turn cars green off
			CarsRedEnable();
			CarsGreenDisable();
			// wait for 5 secs
			TIMER0_Delay(5000);
			//turn cars red off
			CarsRedDisable();
			// blink both yellow while peds green on
			BothSteady();
			/********************************************/
			// turn off all leds
			TurnAllOff();
			// reset timer to escape after return
			TIMER0_reset();
			// reset normal mode to beginning
			ResetNormalMode();
		}
	}
}

void appInit(void)
{
	// initialize external interrupt 0
	EXT_INT_init(INT0, FallingEdge);
	// initialize traffic lights module
	
}
void appStart(void)
{
	// enable external interrupt 0
	EXT_INT_enable(INT0);
	while (1)
	{
		// call normal mode function
		T_LIGHTS_NormalMode();
	}
}