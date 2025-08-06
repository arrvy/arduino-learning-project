#ifndef SERVO_MODE
#define SERVO_MODE

#include <pin_definition.h>
#include <potentio_mechanism.h>
#include <ESP32_Servo.h>

//* Declaration Class

//* Declaration Variable
extern uint_fast8_t servoValue[4];
extern uint_fast8_t servoValueSmoothed[4];
extern uint_fast8_t servoValuePast[4];
extern uint_fast8_t writingIteration;

//* Declaration Function
void InitServoPotition();
void ManualMode();
void Auto1Mode();
void Auto2Mode();
void WiFiMode();


void writeServo(uint_fast8_t poteniometer[4]);

#endif