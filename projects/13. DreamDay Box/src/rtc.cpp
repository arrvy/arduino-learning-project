#include <rtc.h>

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Time Now Variable
String formattedTime;
String dayOfWeek;
String yearStr;
String monthStr;
String dayStr;
String hourStr;
String minuteStr;
String secondStr;

//  Time Passed Variable

// String dayOfWeek;
// String yearPassed;
// String monthPassed;
String dayPassed;
// String hourPassed;
// String minutePassed;
// String secondPassed;

DateTime now;
DateTime target(2022,12,22,12,0,0);
TimeSpan passed;

uint64_t RTCmillis = 0;

void RTCSetup(){
 if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}

void calculateCount(){
    passed = now - target;
    dayPassed = passed.totalseconds() / 86400;
}

void RTCUpdate(){

    calculateCount();

    if (currentMillis - RTCmillis > 3000)
    {
        // Get the current time from the RTC
        now = rtc.now();
        
        // Getting each time field in individual variables
        // And adding a leading zero when needed;
        yearStr = String(now.year(), DEC);
        monthStr = (now.month() < 10 ? "0" : "") + String(now.month(), DEC);
        dayStr = (now.day() < 10 ? "0" : "") + String(now.day(), DEC);
        hourStr = (now.hour() < 10 ? "0" : "") + String(now.hour(), DEC); 
        String minuteStr = (now.minute() < 10 ? "0" : "") + String(now.minute(), DEC);
        String secondStr = (now.second() < 10 ? "0" : "") + String(now.second(), DEC);
        dayOfWeek = daysOfTheWeek[now.dayOfTheWeek()];

        // Complete time string
        Serial.println(dayStr);
        formattedTime = dayOfWeek + ", " + yearStr + "-" + monthStr + "-" + dayStr + " " + hourStr + "." + minuteStr + "." + secondStr;

        // Print the complete formatted time
        Serial.println(formattedTime);

        // Getting temperature
        Serial.print(rtc.getTemperature());
        Serial.println("°C");

        Serial.println();

        Serial.print("Day Passed: ");
        Serial.println(dayPassed);

        RTCmillis = currentMillis;
    }
    
 
}


