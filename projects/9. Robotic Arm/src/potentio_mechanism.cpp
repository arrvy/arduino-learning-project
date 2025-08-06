#include <potentio_mechanism.h>

//* Initialize Class

//* Initialize Variable
uint_fast8_t potentiometerValue[4] = {90, 90, 90, 90};
uint_fast8_t potentiometerValuePast[4];

uint64_t potentiomterTimer[4];

//* Initialize Function

void readPotentiometer(int pin,int index){
    potentiometerValue[(int)index]=map(analogRead(pin),0,4055,0,180);
}
void writePotentiometer(int index){
    if(millis()-potentiometerValuePast[index] > 500){
        Serial.print("Value Potentiometer ");
        Serial.print(index);
        Serial.print("= ");
        Serial.println(potentiometerValue[index]);
        potentiometerValuePast[index] = millis();
    }
}