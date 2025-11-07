#ifndef RTC_H  
#define RTC_H

#include <pin_definition.h>

#include <Wire.h>
#include <RTClib.h>


extern RTC_DS3231 rtc;

//? Function Declaration

extern void RTCSetup();
extern void caclutateCount();
extern void RTCUpdate();
// extern void RTCSetup();

//? Variable Declaration

// Time Now Variable 
extern char daysOfTheWeek[7][12];
extern uint64_t RTCmillis;
extern String formattedTime;
extern String dayOfWeek;
extern String yearStr;
extern String monthStr;
extern String dayStr;
extern String hourStr;
extern String minuteStr;
extern String secondStr;

// Time Passed Variable

// extern String yearPassed;
// extern String monthPassed;
extern String dayPassed;
// extern String hourPassed;
// extern String minutePassed;
// extern String secondPassed;

extern DateTime now;
extern DateTime target;
extern TimeSpan passed;

#endif
