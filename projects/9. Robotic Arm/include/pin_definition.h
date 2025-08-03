#ifndef PIN_DEFINITION
#define PIN_DEFINITION

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
const uint_fast8_t DO = 262;    
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

//* Servo


#endif