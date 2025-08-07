#include <Arduino.h>

#define servoPin 9 //Some of PWM pin on Arduino UNO
#define potentiometer 14

const int pulseDuration = 20000;
int pulseWidth = 500;
uint64_t pulseTimer = 0;
uint32_t serialTimer = 0;

void setup(){
  pinMode(servoPin,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  pulseWidth = map(analogRead(potentiometer),0,1023,400,2500);

  if(millis()-serialTimer > 200){
    Serial.println(pulseWidth);
    serialTimer = millis();
  }

  uint64_t now = micros();
  if(now - pulseTimer > pulseDuration){
    pulseTimer = now;
    digitalWrite(servoPin,HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(servoPin,LOW);
    //delayMicroseconds(pulseDuration-pulseWidth);
  }
}