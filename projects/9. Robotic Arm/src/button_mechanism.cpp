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

  anyPressed |= buttonInterval(0,LED_2_SHOULDER,ButtonInput,  maxbut1,timeButton1,500,830);
  anyPressed |= buttonInterval(1,LED_4_GRIP    ,ButtonInput,  maxbutselect,timeButtonSelect,200,330);
  anyPressed |= buttonInterval(2,LED_3_ELBOW   ,ButtonInput,  maxbut3,timeButton3,50,94);

  // if (anyPressed == 1 && ButtonInput < 200 && ButtonInput >=300){
    
  // }

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
        digitalWrite(buttonpin,HIGH);
        Serial.print("Button ");
        Serial.println(buttonchar[buttonindex]); 
        Serial.println("Is Clicked");

        //* To go into menu and handling menu system
          handleButtonMenu(butvalue,buttonindex);
        
        

        //but1 = but1_now;
        timebutton = millis();
        
        
    }   
        return true;
    }

    return false;

   
}

void handleButtonMenu(uint16_t value,uint_fast8_t index){
  //* To enter menu logic
  if( (value < 200 || value >=300) && onMenu == false ){
    //Serial.println(onMenu);
    Serial.println("Enter to Menu");
    
    lcd.clear();
    enterMenu();
    //selectedMenuIndex=(int)currentMode;
    
    
    // selectedMenuIndex+=1;
    // if(selectedMenuIndex%3 == 0 && selectedMenuIndex != 0){
    //   selectedMenuIndex = 0;
    // }
  }
   
 if (onMenu != false )
 {

    switch (index)
    {
    case 0:
      Serial.println("Go Left");
      if(selectedMenuIndex == 0){
        selectedMenuIndex = 3;
      }else{
        selectedMenuIndex-=1;
      }
      lcdTimer = millis();
      break;
    case 1:
      Serial.println("Go Select");
      
      switch (selectedMenuIndex)
        {
        case 0:
          currentMode = MODE_MANUAL;
          break;
        case 1:
          currentMode = MODE_AUTO_1;
          break;
        case 2:
          currentMode = MODE_AUTO_2;
          break;
        case 3:
          currentMode = MODE_WIFI;
          break;
        default:
          break;
        }
      selectedMenuIndexPast = selectedMenuIndex;
      onMenu = false;
      showCurrentMode();
      lcdTimer = millis();
      tone(BUZZER,MI,200);
      tone(BUZZER,DO_UP,200);
      break;
    case 2:
      Serial.println("Go Right");
      selectedMenuIndex+=1;
      if(selectedMenuIndex > 3){
        selectedMenuIndex = 0;
      }
      lcdTimer = millis();
      break;
    default:
      break;
    }

  Serial.print("Selected Past = ");
  Serial.println(selectedMenuIndexPast);
  Serial.print("Selected = ");
  Serial.println(selectedMenuIndex);
 }
 

}

