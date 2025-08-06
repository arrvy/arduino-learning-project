#ifndef POTENTIOMETER_MECHANISM
#define POTENTIOMETER_MECHANISM

#include <Arduino.h>
#include <pin_definition.h>

//* Declaration Class

//* Declaration Variable
extern uint_fast8_t potentiometerValue[4];
extern uint_fast8_t potentiometerValuePast[4];

extern uint64_t potentiomterTimer[4];

//* Declaration Function

void readPotentiometer(int pin, int index);
void writePotentiometer(int index);

#endif