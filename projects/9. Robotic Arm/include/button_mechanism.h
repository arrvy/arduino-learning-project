#ifndef BUTTON_MECHANISM
#define BUTTON_MECHANISM
#include <pin_definition.h>
#include <lcd_ui.h>
#include <servo_mode.h>

//* Variable Declaration & Inizialitation

extern const char* buttonchar[];
extern u_int16_t ButtonInput;
// Time variabel for each button to make delay with millis() (should use fewer variable)
extern uint64_t timeNow;
extern uint64_t timeButton1;
extern uint64_t timeButtonSelect;
extern uint64_t timeButton3;
extern uint64_t timeInputButton;

// Only for debugging for choosing ceil and floor
// But at the end, we use this variable for the rest of the code
extern uint16_t maxbut1;
extern uint16_t maxbutselect;
extern uint16_t maxbut3;

// and this, is not used
extern bool but1;
extern bool butselect;
extern bool but3;
extern bool but1_now;
extern bool butselect_now;
extern bool but3_now;

//* Function Declaration

void buttonRead(const int buttonpin);
int maximumValue(uint16_t highest,uint16_t inputnow);
void showMaxValue(uint16_t butvalue, uint16_t inputnow);
bool buttonInterval(const uint_fast8_t buttonindex,const int buttonpin,u_int16_t butvalue, uint16_t &maxbutvalue,uint64_t &timebutton, uint16_t floor, uint16_t ceil);
void handleButtonMenu(uint16_t value, uint_fast8_t index);
#endif 
