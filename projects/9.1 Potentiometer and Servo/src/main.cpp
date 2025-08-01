#include <Arduino.h>
#include <ESP32Servo.h>

const int SERVO_1 = 23;
#define POT_1 15

Servo servo1;
int pot1read = 0; 
int pot2read = 0; 
int pot3read = 0; 
int pot4read = 0; 

void PotentioRead();


int time_now = millis();
int time_pot = millis();
int time_servo = millis();
void setup() {

  Serial.begin(9600);
  servo1.attach(SERVO_1,500,2400);

  // analog input, doesn't need to be pinMode 
  // (if declare as pinMode, it will change/work in digital signal) 
  // pinMode(POT_1,INPUT);
  servo1.write(0);
}

void loop() {

  PotentioRead();
  

  while ((millis() - time_now) >= 100){
  Serial.print("pot1read = ");
  Serial.println(pot1read);
  servo1.write(pot1read);
  delay(15);
  time_now = millis();
  }
  
  
}


void PotentioRead() {
  pot1read = analogRead(POT_1);
  // pot2read = analogRead(POT_1)
  // pot3read = analogRead(POT_1)
  // pot4read = analogRead(POT_1)
  if (millis() - time_pot >=1000){
    Serial.print("Potential Read = ");
    Serial.println(pot1read);
    time_pot = millis();
  }

  // ? Kesalahan koplak anyng
  pot1read = map(pot1read,0,4095,0,180); 
  //int pot2read = analogRead(); 
  //int pot3read = analogRead(); 
  //int pot4read = analogRead(); 

 if (millis() - time_servo >=1000){
    Serial.print("Degree = ");
    Serial.println(pot1read);
    time_servo = millis();
  }
}