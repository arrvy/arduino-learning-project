#ifndef PIN_DEFINITION
#define PIN_DEFINIITON

#include <Arduino.h>

//? ANALOG PIN

#define PIN_A0   (14)
#define PIN_A1   (15)
#define PIN_A2   (16)
#define PIN_A3   (17)
#define PIN_A4   (18)
#define PIN_A5   (19)
#define PIN_A6   (20)
#define PIN_A7   (21)

//? I2C
// Gausa definisikan karena udah dari library
// const int SCL = PIN_A5; 
// const int SDA = PIN_A4;

//? SEVEN SEGMENT (TM1637)
#define DIO 7
#define CLK 8

//? LED MATRIX

#define MDIN 10
#define MCS 11
#define MCLK 12

//? LED

extern uint64_t currentMillis;

#endif