#include <Servo.h>

Servo myservo;
int pos = 0;
const int trigPin = 10;
const int echoPin = 11; 

long duration;
long distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  // Initialize the servo movement
  for (int i = 0; i < 5; i++) {
    for (pos = 0; pos <= 180; pos++) {
      myservo.write(pos);
      delay(10);
      outputDistance(pos); // Pass the current position to outputDistance
    }
    for (pos = 180; pos >= 0; pos--) {
      myservo.write(pos);
      delay(10);
      outputDistance(pos); // Pass the current position to outputDistance
    }
  }

  for (int j = 0; j < 3; j++) {
    for (pos = 0; pos <= 180; pos++) {
      myservo.write(pos);
      delay(5);
      outputDistance(pos); // Pass the current position to outputDistance
    }
    for (pos = 180; pos >= 0; pos--) {
      myservo.write(pos);
      delay(5);
      outputDistance(pos); // Pass the current position to outputDistance
    }
  }
}

long calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Calculate distance in cm
  return distance;
}

void outputDistance(int angle) {
  distance = calculateDistance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  // Send the angle and distance to the Serial Plotter
  Serial.print("Angle_");
  Serial.print(angle);
  Serial.print(":");
  Serial.println(distance); // Use println to send each value on a new line
}