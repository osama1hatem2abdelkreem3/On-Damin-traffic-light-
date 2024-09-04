/*
 * TRAFFIC_LIGHTS.c
 *
 * Created: 22/02/2023
 *  Author: osama
 */

#include "TRAFFIC_LIGHTS.h"
// global variables to be accessed by all functions
uint8_t CarsMode;	   // for car current status
uint8_t resetFlag = 0; // for resetting normal mode function to beginning
void T_Lights_init(void)
{
	// initializing leds for cars and pedestrian
	LED_init(PIN0, PORTA);
	LED_init(PIN1, PORTA);
	LED_init(PIN2, PORTA);
	LED_init(PIN0, PORTB);
	LED_init(PIN1, PORTB);
	LED_init(PIN2, PORTB);
}
void T_LIGHTS_NormalMode(void)
{
	// while normal mode hasn't been reset before
	while (resetFlag == 0)
	{
		// turn cars green on
		CarsGreenEnable();
		// wait for 5 secs then check for reset
		TIMER0_Delay(5000);
		if (resetFlag == 1)
		{
			TurnCarsOff();
			resetFlag = 0;
			break;
		}
		// turn cars green off
		CarsGreenDisable();
		// blink cars yellow for 5 secs
		CarsSteady();
		// check for reset
		if (resetFlag == 1)
		{
			TurnCarsOff();
			resetFlag = 0;
			break;
		}
		// turn cars red on
		CarsRedEnable();
		// wait for 5 secs then check for reset
		TIMER0_Delay(5000);
		if (resetFlag == 1)
		{
			TurnCarsOff();
			resetFlag = 0;
			break;
		}
		// turn cars red off
		CarsRedDisable();
		// blink cars yellow for  secs
		CarsSteady();
		// check for reset
		if (resetFlag == 1)
		{
			TurnCarsOff();
			resetFlag = 0;
			break;
		}
	}
}
void CarsGreenEnable(void)
{
	// set cars current sate to green
	CarsMode = CARS_GREEN;
	// turn car green on
	LED_on(PIN0, PORTA);
}
void CarsGreenDisable(void)
{
	// turn cars green off
	LED_off(PIN0, PORTA);
}
void PedsGreenEnable(void)
{
	// turn peds green on
	LED_on(PIN0, PORTB);
}
void PedsGreenDisDisable(void)
{
	// turn peds green off
	LED_off(PIN0, PORTB);
}
void BothSteady(void)
{
	// define variable to be iterator
	static uint8_t i;
	// set cars mode to yellow state
	CarsMode = CARS_YELLOW;
	// blink both yellow for  secs
	for (i = 0; i < 10; i++)
	{
		// toggle both yellow every half second for  seconds
		LED_toggle(PIN1, PORTA);
		LED_toggle(PIN1, PORTB);
		TIMER0_Delay(500);
	}
	// turn both yellow leds off
	LED_off(PIN1, PORTA);
	LED_off(PIN1, PORTB);
}
void CarsSteady(void)
{
	// define variable to be iterator
	static uint8_t i;
	// set cars state to yellow state
	CarsMode = CARS_YELLOW;
	for (i = 0; i < 10; i++)
	{
		// check for reset
		if (resetFlag == 1)
		{
			TurnCarsOff();
			return;
		}
		// toggle cars yellow
		LED_toggle(PIN1, PORTA);
		// delay for half secs
		TIMER0_Delay(500);
	}
	// turn of cars yellow
	LED_off(PIN1, PORTA);
}
void CarsRedEnable(void)
{
	// set cars state to red state
	CarsMode = CARS_RED;
	// turn cars red on
	LED_on(PIN2, PORTA);
}
void CarsRedDisable(void)
{
	// turn cars red off
	LED_off(PIN2, PORTA);
}
void PedsRedEnable(void)
{
	// turn peds red on
	LED_on(PIN2, PORTB);
}
void PedsRedDisable(void)
{
	// turn pin red off
	LED_off(PIN2, PORTB);
}
uint8_t T_Lights_CurrentMode(void)
{
	// return curren car state
	return CarsMode;
}
void TurnCarsOff(void)
{
	// turn off all cars leds
	LED_off(PIN0, PORTA);
	LED_off(PIN1, PORTA);
	LED_off(PIN2, PORTA);
}
void TurnAllOff(void)
{
	// turn of both cars and peds leds
	LED_off(PIN0, PORTA);
	LED_off(PIN1, PORTA);
	LED_off(PIN2, PORTA);
	LED_off(PIN0, PORTB);
	LED_off(PIN1, PORTB);
	LED_off(PIN2, PORTB);
}
void ResetNormalMode(void)
{
	// set the reset flag to reset normal mode to initial flow
	resetFlag = 1;
}
