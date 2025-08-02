#include <Arduino.h>
#include <button_mechanism.h>

//* Variable Declaration & Inizialitation
const char* buttonchar[] = {"Left (KEY 1)","Select (KEY 2)","Right (KEY 3)","Right and Select (KEY 4)","Select and Left (KEY 1)"};

u_int16_t ButtonInput;
uint64_t timeNow = millis();
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
//* Function Declaration
//--//
bool but1_now = 1;
bool butselect_now = 1;
bool but3_now = 1;



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

void buttonRead(const int buttonpin){
  ButtonInput = analogRead(buttonpin);


  bool anyPressed = false;

  anyPressed |= buttonInterval(0,LED_1_ROTATION,ButtonInput,  maxbut1,timeButton1,550,800);
  anyPressed |= buttonInterval(1,LED_4_GRIP    ,ButtonInput,  maxbutselect,timeButtonSelect,200,300);
  anyPressed |= buttonInterval(2,LED_3_ELBOW   ,ButtonInput,  maxbut3,timeButton3,10,100);


  for(int i = 1; i < 5;i++){
    if(!anyPressed){
        digitalWrite(ledPins[i],LOW);
    }
  }
  // if (ButtonInput >= 550 && ButtonInput < 800)
  // {
  //   // Serial.println("Button Left (KEY 1) Is Clicked");
  //   maxbut1 = maximumValue(maxbut1,ButtonInput);
  //   showMaxValue(maxbut1,ButtonInput);

  //   //* Mengurangi Intensitas Input Masuk
  //   if(millis() - timeButton1 >= 200){
  //     Serial.println("Button Left (KEY 1) Is Clicked");
  //     //but1 = but1_now;
  //     timeButton1 = millis();
  //   }

  // }else if(ButtonInput >300 && ButtonInput < 450)
  // {
  //   Serial.println("Button Select and Left (KEY 2 & KEY 3) Is Clicked");

  // }else if (ButtonInput >= 200 && ButtonInput < 300)
  // { 
  //   // Serial.println("Button Select (SELECT) Is Clicked");
  //   maxbutselect = maximumValue(maxbutselect,ButtonInput);
  //   showMaxValue(maxbutselect,ButtonInput);

  //   if(millis() - timeButtonSelect >= 200){
  //     Serial.println("Button Select (SELECT) Is Clicked");
  //     //but1 = but1_now;
  //     timeButtonSelect = millis();
  //   }

  // }else if (ButtonInput >= 5 && ButtonInput < 100)
  // {
  //   // Serial.println("Button Right Is (KEY 3) Clicked");
  //   maxbut3 = maximumValue(maxbut3,ButtonInput);
  //   showMaxValue(maxbut3,ButtonInput);

  //   if(millis() - timeButton3 >= 200){
  //     Serial.println("Button Right Is (KEY 3) Clicked");
  //     //but1 = but1_now;
  //     timeButton3 = millis();
  //   }

  // } else if(ButtonInput >= 800 && ButtonInput < 1000){
  //   Serial.println("Button Left and Select (KEY 1 & KEY 2) Is Clicked");
  // } else
  // {
  //   // Serial.println("Not Clicked");
  // }

}

//? ini baru gunanya aku belajar saat semester 1, materi Parameter menggunakan Reference
bool buttonInterval(const uint_fast8_t buttonindex,const int buttonpin,u_int16_t butvalue, uint16_t &maxbutvalue,uint64_t &timebutton, uint16_t floor, uint16_t ceil){
    if (butvalue >= floor && butvalue < ceil){
    digitalWrite(buttonpin,HIGH);

    // Serial.println("Button Left (KEY 1) Is Clicked");
    maxbutvalue = maximumValue(maxbutvalue,butvalue);
    // showMaxValue(maxbutvalue,butvalue);

    //* Mengurangi Intensitas Input Masuk
        if(millis() - timebutton >= 200){
        Serial.print("Button ");
        Serial.println(buttonchar[buttonindex]);
        Serial.println("Is Clicked");
        //but1 = but1_now;
        timebutton = millis();
        digitalWrite(buttonpin,HIGH);
        
    }   
        return true;
    }

    return false;

   
}

