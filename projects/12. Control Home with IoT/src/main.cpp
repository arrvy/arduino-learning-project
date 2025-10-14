#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
// #include <WiFi.h>


#define LED_BUILTIN 2
const int EN3 = 18; 
const int EN4 = 5; 

const int BUTTON1 = 32;
const int BUTTON2 = 33;

const int PIRPIN = 14;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  digitalWrite(LED_BUILTIN,HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN,LOW);
  delay(500);
}