#include <Arduino.h>
#include <lcd_ui.h>

//* Variable Definition

SystemMode currentMode = MODE_MANUAL;

String menuItem[] = {"Mode Manual","Auto 1","Auto 2","Wi-Fi"};

uint64_t lcdTimer = millis();
uint_fast8_t menuTimeout = 3000;
uint_fast8_t blink=0;
uint_fast8_t blinkInterval=500;

uint_fast8_t selectedMenuIndex = (int)currentMode;
uint_fast8_t selectedMenuIndexPast = 0;
uint_fast8_t menuCount=4;
bool onMenu = false;
bool blinkOn = false;
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

void handleMenuUI(){
    if(millis() - lcdTimer > menuTimeout){
        onMenu = false; 
        lcdTimer = millis();
        showCurrentMode();
        
    }

    if (millis() - blink > blinkInterval) {
    blinkOn = !blinkOn;
    blink = millis();
  }
    //lcd.setCursor(0, 0);

    for (int i = 0; i < menuCount; i++) {
        lcd.setCursor(0, 1);
        if (i == selectedMenuIndex) {
            if (blinkOn) {
                lcd.print("> " + menuItem[i]);
            } else {
                lcd.print("          ");  // Kosong saat kedip
            }
        }
        // else {
        // lcd.print("  " + menuItem[i]);
        // }
    }

}

void showCurrentMode(){
    
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Mode Aktif : ");
    lcd.setCursor(1,1);
    lcd.print(menuItem[selectedMenuIndex]);
    // selectedMenuIndex
    Serial.print("Current Mode Index ");
    Serial.println(selectedMenuIndex);
}


