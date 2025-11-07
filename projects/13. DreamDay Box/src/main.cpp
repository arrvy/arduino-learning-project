#include <Arduino.h>

// Library 

// #include <Wire.h>
// #include <SPI.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>


// Inlcude

#include <oled.h>
#include <rtc.h>
#include <seven_segment.h>
#include <led_matrix.h>

uint64_t currentMillis;

void setup() {
  Serial.begin(115200);
  // Wire.begin(SDA,SCL);
  checkOLED();
  RTCSetup();
  sevenSegmentSetup();
  ledMatrixSetup();

}

void loop() {
currentMillis = millis();

OLEDTextList();
RTCUpdate();
sevenSegmentUpdate();
ledMatrixDrawLove();

}


