#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>



const char* ssid = "Tenda_562B88";
const char* password = "ardydanfitri";

// ! Coba ganti nilai portnya
AsyncWebServer server(80);

#define thumbLedPin 27
#define indexLedPin 26
#define middleLedPin 25
#define ringLedPin 32
#define pinkyLedPin 33

#define LED_BUILTIN 2

void ServerGet();
void LEDinit();


void setup() {
  Serial.begin(115200 );

  LEDinit();

  Serial.println("Connecting to Wifi...");
  WiFi.begin(ssid,password);
  int attempts = 0;
  while(WiFi.status() != WL_CONNECTED && attempts < 20){
    delay(1000);
    Serial.print(".");
    attempts++;
  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.println("\n Connected to WiFI");
    Serial.print("\n IP Address: ");
    Serial.println(WiFi.localIP());
    
    ServerGet();
  
    server.begin();
    Serial.println("Server Started");
    }else{
      Serial.println("\nFailed to connect WiFi");
  }
}

void loop() {

}


void LEDinit(){
  pinMode(thumbLedPin, OUTPUT);
  pinMode(indexLedPin, OUTPUT);
  pinMode(middleLedPin, OUTPUT);
  pinMode(ringLedPin, OUTPUT);
  pinMode(pinkyLedPin, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(thumbLedPin,LOW);
  digitalWrite(indexLedPin,LOW);
  digitalWrite(middleLedPin,LOW);
  digitalWrite(ringLedPin,LOW);
  digitalWrite(pinkyLedPin,LOW);

  digitalWrite(LED_BUILTIN,LOW);
}

void ServerGet(){
    server.on("/led/thumb/on", HTTP_GET, [](AsyncWebServerRequest *request) {
      digitalWrite(thumbLedPin,HIGH);
      request -> send(200, "text/plain", "Price - 300");
    });
   server.on("/led/thumb/off", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(thumbLedPin, LOW);
     request->send(200, "text/plain", "Thumb LED is OFF");
   });
   server.on("/led/index/on", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(indexLedPin, HIGH);
     request->send(200, "text/plain", "Index finger LED is ON");
   });
   server.on("/led/index/off", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(indexLedPin, LOW);
     request->send(200, "text/plain", "Index finger LED is OFF");
   });
   server.on("/led/middle/on", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(middleLedPin, HIGH);
     request->send(200, "text/plain", "Middle finger LED is ON");
   });
   server.on("/led/middle/off", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(middleLedPin, LOW);
     request->send(200, "text/plain", "Middle finger LED is OFF");
   });
   server.on("/led/ring/on", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(ringLedPin, HIGH);
     request->send(200, "text/plain", "Ring finger LED is ON");
   });
   server.on("/led/ring/off", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(ringLedPin, LOW);
     request->send(200, "text/plain", "Ring finger LED is OFF");
   });
   server.on("/led/pinky/on", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(pinkyLedPin, HIGH);
     request->send(200, "text/plain", "Pinky finger LED is ON");
   });
   server.on("/led/pinky/off", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(pinkyLedPin, LOW);
     request->send(200, "text/plain", "Pinky finger LED is OFF");
   });

}