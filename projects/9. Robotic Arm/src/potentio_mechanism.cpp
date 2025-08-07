#include <potentio_mechanism.h>

//* Initialize Class

//* Initialize Variable
uint_fast8_t potentiometerValue[4] = {90, 90, 90, 90};
uint_fast8_t potentiometerValuePast[4];

uint64_t potentiomterTimer[4];

//* Initialize Function

// Function to read potentiometer and save it to array
void readPotentiometer(int pin,int index){
    potentiometerValue[(int)index]=map(analogRead(pin),0,4055,0,180);
}

// Show it to serial monitor for debugging
void writePotentiometer(int index){
    if(millis()-potentiometerValuePast[index] > 500){
        Serial.print("Value Potentiometer ");
        Serial.print(index);
        Serial.print("= ");
        Serial.println(potentiometerValue[index]);
        potentiometerValuePast[index] = millis();
    }
}