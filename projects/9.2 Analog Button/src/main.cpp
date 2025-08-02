//* Include Library
#include <Arduino.h>

//* TODO : Buat sistem ambil nama var
// #include <string.h>
#define STRINGIZE_THIS(var) #var

//* Defining Pin
#define BUTTON_PIN 36

//* Variable Declaration & Initialization
u_int16_t ButtonInput;
uint64_t timeNow;
uint64_t timeButton1 = millis();
uint64_t timeButtonSelect = millis();
uint64_t timeButton3 = millis();
uint64_t timeInputButton = millis();


uint16_t maxbut1 = 0;
uint16_t maxbutselect = 0;
uint16_t maxbut3 = 0;

bool but1 = 0;
bool butselect = 0;
bool but3 = 0;
//--//
bool but1_now = 1;
bool butselect_now = 1;
bool but3_now = 1;

//* Function Declaration

void buttonRead();
void attachingPin();
int maximumValue(uint16_t highest,uint16_t inputnow);
void showMaxValue(uint16_t butvalue, uint16_t inputnow);

void setup(){
Serial.begin(115200);
timeNow = millis();

}

void loop(){
  if (millis() - timeNow > 15){
    buttonRead();
    timeNow = millis();

    if(millis() - timeInputButton > 100){
      Serial.print("ButtonRead = ");
      Serial.println(ButtonInput);
      timeInputButton = millis();
    }

  }
}


//* Function Implementation
void buttonRead(){
  ButtonInput = analogRead(BUTTON_PIN);


  if (ButtonInput >= 550 && ButtonInput < 800)
  {
    // Serial.println("Button Left (KEY 1) Is Clicked");
    maxbut1 = maximumValue(maxbut1,ButtonInput);
    showMaxValue(maxbut1,ButtonInput);

    //* Mengurangi Intensitas Input Masuk
    if(millis() - timeButton1 >= 200){
      Serial.println("Button Left (KEY 1) Is Clicked");
      //but1 = but1_now;
      timeButton1 = millis();
    }

  }else if(ButtonInput >300 && ButtonInput < 450)
  {
    Serial.println("Button Select and Left (KEY 2 & KEY 3) Is Clicked");

  }else if (ButtonInput >= 200 && ButtonInput < 300)
  { 
    // Serial.println("Button Select (SELECT) Is Clicked");
    maxbutselect = maximumValue(maxbutselect,ButtonInput);
    showMaxValue(maxbutselect,ButtonInput);

    if(millis() - timeButtonSelect >= 200){
      Serial.println("Button Select (SELECT) Is Clicked");
      //but1 = but1_now;
      timeButtonSelect = millis();
    }

  }else if (ButtonInput >= 5 && ButtonInput < 100)
  {
    // Serial.println("Button Right Is (KEY 3) Clicked");
    maxbut3 = maximumValue(maxbut3,ButtonInput);
    showMaxValue(maxbut3,ButtonInput);

    if(millis() - timeButton3 >= 200){
      Serial.println("Button Right Is (KEY 3) Clicked");
      //but1 = but1_now;
      timeButton3 = millis();
    }

  } else if(ButtonInput >= 800 && ButtonInput < 1000){
    Serial.println("Button Left and Select (KEY 1 & KEY 2) Is Clicked");
  } else
  {
    // Serial.println("Not Clicked");
  }

}


void attachingPin(){

}

int maximumValue(uint16_t highest,uint16_t inputnow){
  if(highest > inputnow){
    return highest;
  }
  else{
    return inputnow;
  }
}

void showMaxValue(uint16_t butvalue, uint16_t inputnow){
  if(butvalue == inputnow){
      Serial.print("Maximum But = ");
      Serial.println(butvalue);
    }
} 

void printlnButtonCondition(bool butCondition, bool butConditionNow){

}