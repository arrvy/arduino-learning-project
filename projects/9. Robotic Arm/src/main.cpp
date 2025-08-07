//* Include Library
#include <Arduino.h>
#include <pin_definition.h>
#include <button_mechanism.h>
//#include <lcd_ui.h>
//* TODO : Buat sistem ambil nama var
// #include <string.h>
#define STRINGIZE_THIS(var) #var

//* Defining Pin
//#define BUTTON_PIN 36

//* Variable Declaration & Initialization


//* Function Declaration
void initializePin();

void setup(){
  Serial.begin(115200);
  initializePin();
  initLCD();

  startUI();
  lcd.setCursor(2,0);
  lcd.print("halo");
  writeServo(servoValue);
  delay(1000);
  showCurrentMode();
}

void loop(){
  lcd.setCursor(0, 0);
  
  // if(millis() - lcdTimer > 200){
  //   lcd.clear();
  //   lcdTimer = millis();
  // }

  if (millis() - timeNow > 0){
    // Read Analog Input from Button that correlate
    buttonRead(BUTTON_PIN);
    timeNow = millis();

    //Show input only when clicked
    if(millis() - timeInputButton > 100 && ButtonInput != 0){
      Serial.print("ButtonRead = ");
      Serial.println(ButtonInput);
      timeInputButton = millis();
    }

    if(onMenu){
      handleMenuUI();
    }

  }
  switch ((int)currentMode)
  {
  case 0: // Manual
    ManualMode();
    break;
  case 1: // Auto 1
    break;
  case 2: // Auto 2
    break;
  case 3: // Wi-Fi
    break;
  default:
    break;
  }
}


//* Function Implementation


// For Attaching Pin

void initializePin(){
  //* Input Mode

  //* Output Mode
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(LED_1_ROTATION,OUTPUT);
  pinMode(LED_2_SHOULDER,OUTPUT);
  pinMode(LED_3_ELBOW,OUTPUT);
  pinMode(LED_4_GRIP,OUTPUT);
  initServo();
  
}

