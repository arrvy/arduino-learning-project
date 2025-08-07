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

  // Variable for signal when LED is activated after button clicked, and used for turn off the LED
  bool anyPressed = false;

  // 3 Interval with 3 button (I should make the interval more wider, i still only use 0-1000 rather 0-4095)
  // And this make some fluctuation on lower inteval
  anyPressed |= buttonInterval(0,LED_2_SHOULDER,ButtonInput,  maxbut1,timeButton1,500,830);
  anyPressed |= buttonInterval(1,LED_4_GRIP    ,ButtonInput,  maxbutselect,timeButtonSelect,200,330);
  anyPressed |= buttonInterval(2,LED_3_ELBOW   ,ButtonInput,  maxbut3,timeButton3,50,94);

  for(int i = 1; i < 5;i++){
    if(!anyPressed){
        digitalWrite(ledPins[i],LOW);
    }
  }
  
}

//? ini baru gunanya aku belajar saat semester 1, materi Parameter menggunakan Reference
// Function to make interval of button input
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
      timebutton = millis();
    }   
    return true; // Value for anypressed when clicked
  }
  return false; // Value when not clicked
}

// Function to handling button menu from buttonInterval
void handleButtonMenu(uint16_t value,uint_fast8_t index){
  //* To enter menu logic
  if( (value < 200 || value >=300) && onMenu == false ){
    Serial.println("Enter to Menu");
    lcd.clear();
    enterMenu();
  }
   
 if (onMenu != false )
 {
    switch (index) // If onmenu, Menu mechanism will activate
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
      Serial.println("Go Select"); // When selected, currentMode will change
      
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
      selectedMenuIndexPast = selectedMenuIndex; // Index for LCD UI
      onMenu = false; // To exit menu logic after select
      showCurrentMode();
      lcdTimer = millis();
      tone(BUZZER,MI,200); // sound feedback
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

    // Debugging
    Serial.print("Selected Past = ");
    Serial.println(selectedMenuIndexPast);
    Serial.print("Selected = ");
    Serial.println(selectedMenuIndex);
 }
}

