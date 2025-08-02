#ifndef BUTTON_MECHANISM
#define BUTTON_MECHANISM
#include <pin_definition.h>

//* Variable Declaration & Inizialitation
extern const char* buttonchar[];

extern u_int16_t ButtonInput;
extern uint64_t timeNow;
extern uint64_t timeButton1;
extern uint64_t timeButtonSelect;
extern uint64_t timeButton3;
extern uint64_t timeInputButton;


extern uint16_t maxbut1;
extern uint16_t maxbutselect;
extern uint16_t maxbut3;

extern bool but1;
extern bool butselect;
extern bool but3;
//* Function Declaration
//--//
extern bool but1_now;
extern bool butselect_now;
extern bool but3_now;

void buttonRead(const int buttonpin);
int maximumValue(uint16_t highest,uint16_t inputnow);
void showMaxValue(uint16_t butvalue, uint16_t inputnow);
// void buttonInterval(u_int16_t butvalue, uint16_t maxbutvalue,uint64_t timebutton, uint16_t floor, uint16_t ceil);
bool buttonInterval(const uint_fast8_t buttonindex,const int buttonpin,u_int16_t butvalue, uint16_t &maxbutvalue,uint64_t &timebutton, uint16_t floor, uint16_t ceil);

#endif 
