/*
 * TRAFFIC_LIGHTS.h
 *
  * Created: 22/02/2023
  *  Author: osama
 */
#ifndef TRAFFIC_LIGHTS_H_
#define TRAFFIC_LIGHTS_H_


#include "../LED/LED.h"
// macros for car states
#define CARS_RED 3
#define CARS_YELLOW 4
#define CARS_GREEN 5
// functions prototypes
void T_Lights_init(void);
void T_LIGHTS_NormalMode(void);
void CarsGreenEnable(void);
void CarsGreenDisable(void);
void PedsGreenEnable(void);
void PedsGreenDisDisable(void);
void BothSteady(void);
void CarsSteady(void);
void CarsRedEnable(void);
void CarsRedDisable(void);
void PedsRedEnable(void);
void PedsRedDisable(void);
uint8_t T_Lights_CurrentMode(void);
void TurnCarsOff(void);
void TurnAllOff(void);
void ResetNormalMode(void);

#endif /* TRAFFIC_LIGHTS_H_ */
