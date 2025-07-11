#include <ESP32Servo.h> //Library servo khusus ESP32, karena library Servo.h tidak bisa
#include <LiquidCrystal.h>

#define BLYNK_TEMPLATE_ID "TMPL6y0C54eMp"
#define BLYNK_TEMPLATE_NAME "CatFeeder"
#define BLYNK_AUTH_TOKEN "xwezacK1spzeSvYa8zL0pSDHZ2p1fwV0"

/* Comment this out to disable prints and save space */
// #define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

const int INPUT_BUTTON = 4;
const int LED_BUILTIIN = 2;
const int SERVO = 23;
const int LED_BUZZER = 22;

Servo Servo1;  //Inisialiasi atau membuat Servo1 agar fungsi2 Servo berlaku (tapi belum memasang pin nya dimana)
LiquidCrystal lcd (13,14,26,25,33,32);
BlynkTimer timer;

char ssid[] = "Tenda_562B88";
char pass[] = "ardydanfitri";

int value = 0;
int V0value = 0;

BLYNK_WRITE(V0){
  value = param.asInt(); 
}

void updatevalue(){
   V0value = value;
}

void setup() {

  Servo1.attach(SERVO);
  pinMode(INPUT_BUTTON, INPUT);
  pinMode(LED_BUILTIIN, OUTPUT);
  pinMode(LED_BUZZER, OUTPUT);
  lcd.begin(16,2);

  Serial.begin(9600);
  Servo1.write(0);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L,updatevalue);
}

void loop() {
  Blynk.run();
  timer.run();
  
  
 
  int btnState = digitalRead(INPUT_BUTTON);
  int inputval = btnState || V0value;
  Serial.println(inputval);


  lcd.print("PetFeeder #!");

  if (inputval == 1 ){
    digitalWrite(LED_BUILTIIN, HIGH);
    digitalWrite(LED_BUZZER, HIGH);
    Servo1.write(90);
  }else{
    digitalWrite(LED_BUILTIIN, LOW);
    digitalWrite(LED_BUZZER, LOW);
    Servo1.write(0);
  }
  delay(5);

}
