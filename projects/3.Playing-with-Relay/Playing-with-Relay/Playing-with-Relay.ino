#define RELAY_PIN 12

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  //Kita pake normaly close, jadi kalo di 0 in bakalan closed circuit, arus mengalir
  digitalWrite(RELAY_PIN, 0);
  delay(1000);
  digitalWrite(RELAY_PIN, 1);
  delay(1000);
}