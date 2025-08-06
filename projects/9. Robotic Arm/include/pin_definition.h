#ifndef PIN_DEFINITION
#define PIN_DEFINITION

//* Gatau kenapa kok tiba2 error, uint does not name a type, tapi pas dikasih arduino.h bisa, padahal kemarin2 engga usah
#include <Arduino.h>

//* Analog Button
const int BUTTON_PIN = 36;

//* LED and Buzzer
const int LED_BUILTIN = 2;
const int LED_1_ROTATION = 32;
const int LED_2_SHOULDER = 33;
const int LED_3_ELBOW = 26;
const int LED_4_GRIP = 27;
const int ledPins[] = {LED_BUILTIN,LED_1_ROTATION,LED_2_SHOULDER,LED_3_ELBOW,LED_4_GRIP};

//* Buzzer
const int BUZZER = 25;
const uint_fast8_t DO = 3;    
const uint_fast8_t RE = 294;    
const uint_fast8_t MI = 330;    
const uint_fast8_t FA = 349;    
const uint_fast8_t SO = 392;    
const uint_fast8_t LA = 440;    
const uint_fast8_t SI = 494;    
const uint_fast8_t DO_UP = 523;    


//* LCD and I2C
// Kita gaperlu definisi SCL SDA Karena di Library Udah
//const int SCL = 21;
//const int SDA = 22;
const uint8_t LCD_ADDRESS = 0x27;
const int Kolom = 16;
const int Baris = 2;

//* Potentiometer
const int POTENTIO_1_ROTATION = 15;
const int POTENTIO_2_SHOULDER = 2;
const int POTENTIO_3_ELBOW = 4;
const int POTENTIO_4_GRIP = 13;
const int PotentioPins[] = {POTENTIO_1_ROTATION,POTENTIO_2_SHOULDER,POTENTIO_3_ELBOW,POTENTIO_4_GRIP};


//* Servo
const int SERVO_1_ROTATION = 17;
const int SERVO_2_SHOULDER = 5;
const int SERVO_3_ELBOW = 18;
const int SERVO_4_GRIP = 19;
const int ServoPins[]={SERVO_1_ROTATION,SERVO_2_SHOULDER,SERVO_3_ELBOW,SERVO_4_GRIP};

#endif