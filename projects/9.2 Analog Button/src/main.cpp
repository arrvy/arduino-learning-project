//* Include Library
#include <Arduino.h>
#include <pin_definition.h>
#include <button_mechanism.h>

//* TODO : Buat sistem ambil nama var
// #include <string.h>
#define STRINGIZE_THIS(var) #var

//* Defining Pin
//#define BUTTON_PIN 36

//* Variable Declaration & Initialization


//* Function Declaration
void attachingPin();



void setup(){
  Serial.begin(115200);
  attachingPin();
}

void loop(){

  if (millis() - timeNow > 0){
    buttonRead(BUTTON_PIN);
    timeNow = millis();

    if(millis() - timeInputButton > 100){
      Serial.print("ButtonRead = ");
      Serial.println(ButtonInput);
      timeInputButton = millis();
    }

  }

}


//* Function Implementation



void attachingPin(){
  //* Input Mode

  //* Output Mode
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(LED_1_ROTATION,OUTPUT);
  pinMode(LED_2_SHOULDER,OUTPUT);
  pinMode(LED_3_ELBOW,OUTPUT);
  pinMode(LED_4_GRIP,OUTPUT);
}

