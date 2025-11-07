#include <oled.h>
#include <string.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

uint64_t OLEDmillis = 0;
uint8_t textCase = 0;

void checkOLED(){
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
}

void OLEDDisplay(String text){

  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(21,15);
  display.print(text);

  display.display();

}

void OLEDTextList(){
  if (currentMillis - OLEDmillis > 3500)
  {
   
   switch (textCase)
   {
   case 0:
    if(hourStr.toInt() > 4 && hourStr.toInt() <= 11){

      OLEDDisplay("Selamat Pagiii :)");
    }
    else if (hourStr.toInt() > 11 && hourStr.toInt() <= 14)
    {
      OLEDDisplay("Selamatz Siangz :v");
    }
    else if (hourStr.toInt() > 14 && hourStr.toInt() <= 18)
    {
      OLEDDisplay("Selamat Soree :)");
    }
    else if (hourStr.toInt() > 18 && hourStr.toInt() <= 22)
    {
      OLEDDisplay("Met Malemm zzz...");
    }
    else
    {
      OLEDDisplay("Tidorr Woyy!!");
    }
    
    
    textCase++;
    break;
   case 1:
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(formattedTime);
    display.setCursor(0,20);
    display.print(rtc.getTemperature());
    display.println("ºC");
    display.display();
    textCase++;
   break;
   case 2:
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,15);
    display.print("Day Passed : ");
    display.println(dayPassed);
    display.display();
    textCase = 0;
    break;
   default:
   OLEDDisplay("Error");
    break;
   }

   OLEDmillis = currentMillis;
  }

}


