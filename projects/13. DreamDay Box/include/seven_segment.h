#ifndef SEVEN_SEGMENT
#define SEVEN_SEGMENT

#include <pin_definition.h>

//? Library
// #include <Arduino.h>
#include <TM1637Display.h>

//? Include
#include <rtc.h>

extern TM1637Display sevenSegment;

//? Function Declaration
extern void sevenSegmentSetup();
extern void sevenSegmentUpdate();

//? Variable Declaration
extern uint16_t sevenSegmentNumber;
extern uint8_t sevenSegmentCase;
extern uint64_t sevenSegmentMillis;
extern const uint8_t sevenSegmentLove[];


#endif 