#define BLYNK_TEMPLATE_ID "TMPL65YI6CrnG"
#define BLYNK_TEMPLATE_NAME "LED ESP32"
#define BLYNK_AUTH_TOKEN "bXTxBdb6A2UnHPPv8yKjipHLvqU4H-Az"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "KOST BU TATI";
char pass[] = "rihana01";
// Define DAC pins
#define V1 1
#define LED 25

int i = 0;
BlynkTimer timer;

void BLYNK_WRITE(V1){
  int data = param.asInt();
  analWrite(LED, data);
}
void setup() {
  
  //pinMode(LED,OUTPUT); //error gara2 ini (definisi dua pin)
  Blynk.begin(auth,ssid,pass);
}
 
void loop() {
  Blynk.run();
  timer.run();
  }
 
 
