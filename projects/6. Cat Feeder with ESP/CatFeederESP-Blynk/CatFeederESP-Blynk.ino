/*************************************************************

  Blynk using a LED widget on your phone!

  App dashboard setup:
    LED widget on V3
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL6y0C54eMp"
#define BLYNK_TEMPLATE_NAME         "CatFeeder"
#define BLYNK_AUTH_TOKEN            "xwezacK1spzeSvYa8zL0pSDHZ2p1fwV0"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Tenda_562B88";
char pass[] = "ardydanfitri";

// Select your pin with physical button
const int btnPin = 2;


BlynkTimer timer;

int V0value = 0;

BLYNK_WRITE(V0){
  V0value = param.asInt();
  //digitalWrite(btnPin,V0value);
}

void updatevalue(){
  digitalWrite(btnPin, V0value);
}
void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  pinMode(btnPin,OUTPUT);
  digitalWrite(btnPin,LOW);

  timer.setInterval(500L,updatevalue);
} 

void loop()
{
  Blynk.run();
  timer.run();
}
