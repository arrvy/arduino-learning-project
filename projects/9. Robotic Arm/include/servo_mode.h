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
void InitServoPotition(); //To initialize servo posititon to neutral value (90°)
void ManualMode(); // Manual mode that use potentiometer mechanism
void Auto1Mode(); // Auto1 that use recordable value from Python code
void Auto2Mode(); // Maybe used Serial Protocol
void WiFiMode(); // Mode that use web based mechanism

// Make servo move smoother
void writeServo(uint_fast8_t poteniometer[4]);

// Init servo with 90° value
void initServo();

extern Servo servo_1,servo_2,servo_3,servo_4;

#endif