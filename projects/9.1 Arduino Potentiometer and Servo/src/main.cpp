#include <Arduino.h>
#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9); // Atau ganti pin lain
  myServo.write(0);
  delay(1000);
  myServo.write(90);
  delay(1000);
  myServo.write(180);
}

void loop() {}