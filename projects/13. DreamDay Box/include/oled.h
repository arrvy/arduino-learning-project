#ifndef OLED_H  
#define OLED_H

#include <pin_definition.h>

// Library
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <string.h>

// Inlcude

extern void checkOLED();
extern void OLEDDisplay(String);


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

//  extern agar diketahui compiler kalau ada "display"

extern Adafruit_SSD1306 display;

#endif
