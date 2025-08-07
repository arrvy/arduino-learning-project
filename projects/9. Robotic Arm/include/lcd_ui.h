#ifndef LCD_UI
#define LCD_UI

#include <LiquidCrystal_I2C.h>
#include <ToneESP32.h>
#include <pin_definition.h>



//* Variable Declaration

// Enum for robot/servo mode
enum SystemMode{MODE_MANUAL,
                MODE_AUTO_1,
                MODE_AUTO_2,
                MODE_WIFI};

// 
enum menuState{
                OF_SETTING,ON_SETTING
            };

extern String menuItem[];

extern uint64_t lcdTimer;
extern uint64_t menuStartTimer;
extern uint_fast8_t menuTimeout;
extern uint_fast64_t blink;
extern uint_fast8_t blinkInterval;

extern SystemMode currentMode;
extern uint_fast8_t selectedMenuIndex;
extern uint_fast8_t selectedMenuIndexPast;
extern uint_fast8_t menuCount;
extern bool onMenu;
extern bool blinkOn;

//* Class Declaration
extern LiquidCrystal_I2C lcd;


//* Function Declaration
void initLCD();
void startUI();
void enterMenu();
void handleMenuUI();
void showMenu();
void showCurrentMode();

#endif