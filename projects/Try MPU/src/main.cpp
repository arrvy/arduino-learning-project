#include <Arduino.h>
// Pin BTS7960 (tanpa enable)

#define TRIG_PIN 9
#define ECHO_PIN 10

long duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Pastikan trigger LOW dulu
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Kirim pulsa 10 µs ke trigger
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Baca waktu pantulan echo
  duration = pulseIn(ECHO_PIN, HIGH);

  // Konversi waktu ke jarak (cm)
  distance = duration * 0.0343 / 2;

  // Tampilkan hasil
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}

