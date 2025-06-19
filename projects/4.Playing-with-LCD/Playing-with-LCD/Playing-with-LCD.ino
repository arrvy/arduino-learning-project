#include <LiquidCrystal.h>
LiquidCrystal tampilan(12,11,4,5,6,7);

int i = 0;
#define

void setup()
{
  pinMode( LED_BUILTIN , OUTPUT);
  tampilan.begin(16,2);

}

void loop() {
 
  if (i > 1){
    i = 0;
  }
  tampilan.setCursor(5, i);
  i++;
  tampilan.print("Arduino <");
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  tampilan.clear(); // Clears the LCD screen 

 
}