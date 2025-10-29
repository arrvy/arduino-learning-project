#include <Arduino.h>
#include <oled.h>
#include <rtc.h>
#include <led_matrix.h>

void setup(){
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop(){
  digitalWrite(LED_BUILTIN,HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN,LOW);
  delay(200);
}
