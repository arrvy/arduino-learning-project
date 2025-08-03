#include <Arduino.h>
#include <lcd_ui.h>

//* Variable Definition

SystemMode currentMode = MODE_MANUAL;

uint64_t lcdTimer = millis();
uint_fast8_t menuTimeout = 3000;

//* Class Definition
LiquidCrystal_I2C lcd( LCD_ADDRESS , Kolom , Baris);


//* Function Definition

void initLCD(){
    lcd.init();
    lcd.backlight();
}

void startUI(){
    lcd.setCursor(5,0);
    lcd.print("Welcome");

    delay(100);
    digitalWrite(ledPins[2],HIGH);
    tone(BUZZER,SO);
    delay(400);
    digitalWrite(ledPins[2],LOW);
    digitalWrite(ledPins[3],HIGH);
    tone(BUZZER,FA);
    delay(400);
    lcd.setCursor(6,1);
    lcd.print("o^o");

    digitalWrite(ledPins[3],LOW);
    digitalWrite(ledPins[4],HIGH);
    tone(BUZZER,SI);
    for(int i = 0;i < 5;i++){
    digitalWrite(ledPins[i],HIGH);
    }
    delay(1000);
    for(int i = 0;i < 5;i++){
    digitalWrite(ledPins[i],LOW);
    }
    
    lcd.clear();
    noTone(BUZZER);
}


void enterMenu(){
    onMenu = true;
    lcdTimer = millis();
    selectedMenuIndex = (int)currentMode;
    lcd.clear();
}

void handleMenuLogic(){
    if(true){

    }
}

void showCurrentMode(){

}

