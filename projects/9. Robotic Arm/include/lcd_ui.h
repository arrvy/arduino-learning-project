#ifndef LCD_UI
#define LCD_UI

#include <LiquidCrystal_I2C.h>
#include <ToneESP32.h>

#include <pin_definition.h>



//* Variable Declaration
enum SystemMode{MODE_MANUAL,
                MODE_AUTO_1,
                MODE_AUTO_2,
                MODE_WIFI};

enum menuState{
                OF_SETTING,ON_SETTING
            };

extern uint64_t lcdTimer;
extern uint64_t menuStartTimer;
extern uint_fast8_t menuTimeout;
extern SystemMode currentMode;
extern uint_fast8_t selectedMenuIndex;
extern uint_fast8_t selectedMenuIndexPast;
extern bool onMenu;


//* Class Declaration
extern LiquidCrystal_I2C lcd;


//* Function Declaration
void initLCD();
void startUI();
void enterMenu();
void handleMenuLogic();
void showMenu();
void showCurrentMode();

#endif