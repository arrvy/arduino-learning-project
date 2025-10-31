#include <Arduino.h>

// Library 

// #include <Wire.h>
// #include <SPI.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>


// Inlcude

#include <oled.h>
#include <rtc.h>
#include <led_matrix.h>



void setup() {
  Serial.begin(115200);
  // Wire.begin(SDA,SCL);
  checkOLED();

}

void loop() {
Serial.write("Run \n");
OLEDDisplay("Hello World");
delay(5000);
OLEDDisplay("Mantapp");
delay(5000);
OLEDDisplay("Uhuyy");
delay(5000);

}


