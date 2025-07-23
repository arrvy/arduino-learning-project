#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>  //Library servo khusus ESP32, karena library Servo.h tidak bisa
#include <Wire.h>
#include <RTClib.h>


#define BLYNK_TEMPLATE_ID "TMPL6y0C54eMp"
#define BLYNK_TEMPLATE_NAME "CatFeeder"
#define BLYNK_AUTH_TOKEN "xwezacK1spzeSvYa8zL0pSDHZ2p1fwV0"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>




/* Comment this out to disable prints and save space */
// #define BLYNK_PRINT Serial

const int INPUT_BUTTON = 4;
const int LED_BUILTIIN = 2;
const int SERVO = 19;
const int LED_BUZZER = 18;

Servo Servo1;  //Inisialiasi atau membuat Servo1 agar fungsi2 Servo berlaku (tapi belum memasang pin nya dimana)
BlynkTimer timer;

char ssid[] = "Tenda_562B88";
char pass[] = "ardydanfitri";

int value = 0;
int V0value = 0;
int BlynkHours,BlynkMinutes;
//For RTC
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

//For LCD I2C
const int lcdRows = 2;
const int lcdColumns = 16;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);


BLYNK_WRITE(V0) {
  value = param.asInt();
}
BLYNK_WRITE(V1) {
  BlynkHours = param.asInt();
  Serial.print("Jam diterima dari Blynk: ");
  Serial.println(BlynkHours);
}
BLYNK_WRITE(V2) {
  BlynkMinutes = param.asInt();
  Serial.print("Menit diterima dari Blynk: ");
  Serial.println(BlynkMinutes);
}


void updatevalue() {
  V0value = value;
}

void rtcvalidation(){
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

}
void setup() {
  Serial.begin(9600);

  rtcvalidation();

  lcd.init();
  lcd.backlight();


  Servo1.attach(SERVO);
  pinMode(INPUT_BUTTON, INPUT);
  pinMode(LED_BUILTIIN, OUTPUT);
  pinMode(LED_BUZZER, OUTPUT);



  Servo1.write(0);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L, updatevalue);
}

void loop() {
  Blynk.run();
  timer.run();

  DateTime now = rtc.now();  //DateTime is object that contain t year, month, day, hour, minute, and second.

  String yearStr = String(now.year(), DEC);
  String monthStr = (now.month() < 10 ? "0" : "") + String(now.month(), DEC);
  String dayStr = (now.day() < 10 ? "0" : "") + String(now.day(), DEC);
  String hourStr = (now.hour() < 10 ? "0" : "") + String(now.hour(), DEC);
  String minuteStr = (now.minute() < 10 ? "0" : "") + String(now.minute(), DEC);
  String secondStr = (now.second() < 10 ? "0" : "") + String(now.second(), DEC);
  String dayOfWeek = daysOfTheWeek[now.dayOfTheWeek()];

  String formattedTime = dayOfWeek + ", " + yearStr + "-" + monthStr + "-" + dayStr + " " + hourStr + ":" + minuteStr + ":" + secondStr;
  String LcdTime = yearStr + "-" + monthStr + "-" + dayStr + " " + hourStr + ":" + minuteStr;


  String timenow = hourStr + ":" + minuteStr + ":" + secondStr;
  String alarm = (BlynkHours< 10 ? "0" : "") + String(BlynkHours,DEC) + ":" + (BlynkMinutes< 10 ? "0" : "") + String(BlynkMinutes,DEC) + ":" + "00";

  Serial.println (timenow);
  Serial.println (alarm);
  // Print the complete formatted time
  
    //Serial.println(formattedTime);
    //Serial.println();


  lcd.setCursor(0, 0); //x,y
  // print message
  lcd.print(LcdTime);
  lcd.setCursor(3, 1); //col,row
  lcd.print(">"+alarm+"<");


  int btnState = digitalRead(INPUT_BUTTON);
  int inputval = btnState || V0value;
  Serial.println(inputval);



  if (timenow == alarm){
    digitalWrite(LED_BUILTIIN, HIGH);
    digitalWrite(LED_BUZZER, HIGH);
    Servo1.write(90);
    delay(2000);
  }
  if (inputval == 1) {
    digitalWrite(LED_BUILTIIN, HIGH);
    digitalWrite(LED_BUZZER, HIGH);
    Servo1.write(90);
    delay(2000);
  } else {
    digitalWrite(LED_BUILTIIN, LOW);
    digitalWrite(LED_BUZZER, LOW);
    Servo1.write(0);
  }
  delay(5);
}
