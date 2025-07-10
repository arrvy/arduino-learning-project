#include <ESP32Servo.h> //Library servo khusus ESP32, karena library Servo.h tidak bisa
#include <LiquidCrystal.h>

const int INPUT_BUTTON = 4;
const int LED_BUILTIIN = 2;
const int SERVO = 23;
const int LED_BUZZER = 22;

Servo Servo1;  //Inisialiasi atau membuat Servo1 agar fungsi2 Servo berlaku (tapi belum memasang pin nya dimana)

void setup() {

  Servo1.attach(SERVO);
  pinMode(INPUT_BUTTON, INPUT);
  pinMode(LED_BUILTIIN, OUTPUT);
  pinMode(LED_BUZZER, OUTPUT);
  Serial.begin(9600);
  Servo1.write(0);
}

void loop() {
  int inputval = digitalRead(INPUT_BUTTON);
  Serial.println(inputval);

  if (inputval == 1 ){
    digitalWrite(LED_BUILTIIN, HIGH);
    digitalWrite(LED_BUZZER, HIGH);
    Servo1.write(180);
  }else{
    digitalWrite(LED_BUILTIIN, LOW);
    digitalWrite(LED_BUZZER, LOW);
    Servo1.write(0);
  }
  delay(5);

}
