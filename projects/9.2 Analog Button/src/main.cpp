//* Include Library
#include <Arduino.h>
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

}

void loop(){

  if (millis() - timeNow > 15){
    buttonRead();
    timeNow = millis();

    if(millis() - timeInputButton > 100){
      //Serial.print("ButtonRead = ");
      //Serial.println(ButtonInput);
      timeInputButton = millis();
    }

  }
}


//* Function Implementation



void attachingPin(){

}

