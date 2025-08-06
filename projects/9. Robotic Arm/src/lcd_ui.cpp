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
    selectedMenuIndexPast =(int)currentMode;
    selectedMenuIndex = (int)currentMode;
    lcd.clear();
}

void handleMenuUI(){ 
    if(millis() - lcdTimer > menuTimeout){
        onMenu = false; 
        lcd.clear();
        digitalWrite(ledPins[0],HIGH);
        tone(BUZZER,DO_UP,100);
        tone(BUZZER,RE,100);
        tone(BUZZER,LA,100);
        showCurrentMode();
        lcdTimer = millis();
         digitalWrite(ledPins[0],LOW);

    }
 //* Else, Agar kode2 selanjutnya di handleMenuUI tidak dilanjutkan
    else{
        if (millis() - blink > blinkInterval) {
        blinkOn = !blinkOn;
        blink = millis();
    }
        //lcd.setCursor(0, 0);

        
        if (blinkOn) {
            lcd.setCursor(0, 1);
            lcd.print("> " + menuItem[selectedMenuIndex]+"      ");
        } else {
            lcd.setCursor(0, 1);
            lcd.print("  " + menuItem[selectedMenuIndex]+"      ");
            // lcd.setCursor(0, 1);
            // lcd.print("                  ");  // Kosong saat kedip
        }
    }

    // for (int i = 0; i < menuCount; i++) {
        // lcd.setCursor(0, 1);
    //     if (i == selectedMenuIndex) {
           
    //     }
    //     // else {
    //     // lcd.print("  " + menuItem[i]);
    //     // }
    // }

}

void showCurrentMode(){
    
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Mode Aktif : ");
    lcd.setCursor(1,1);
    lcd.print(menuItem[selectedMenuIndexPast]);
    // selectedMenuIndex
    Serial.print("Current Mode Index ");
    Serial.println(selectedMenuIndex);
    Serial.print("Current Mode Index Past = ");
    Serial.println(selectedMenuIndexPast);
    Serial.print("Mode Now :");
    Serial.println(currentMode);
}


