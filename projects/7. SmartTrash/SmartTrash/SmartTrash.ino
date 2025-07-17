#include <Servo.h>

const int TrigPin = 7;
const int EchoPin = 12;
const int PWMPin = 10;

Servo myservo;


long duration;
int distance;
bool opened = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(LED_BUILTIN , OUTPUT);
  myservo.attach(PWMPin);

  // pinMode(TrigPin, OUTPUT);

  Serial.begin(9600); // Starts the serial communication


  digitalWrite(LED_BUILTIN , LOW);
  myservo.write(0);
}

void loop() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);


  duration = pulseIn(EchoPin, HIGH);
  distance = (duration * 0.034) / 2;

  if (distance > 1 && distance < 400){
    if (distance < 10 && opened == false){
      digitalWrite(LED_BUILTIN , HIGH);

      for (int i = 1; i <= 91 ; i++){
        myservo.write(i);
        delay((90/i)+i/9);
      }
      opened = true;
        
    }
    
  }

  if (opened == true && distance > 2 && distance < 400){
    if (distance < 10){
      delay(1500);
    }
    else{
      
      for (int i = 90; i >= 0 ; i--){
        myservo.write(i);
        delay(10);
        digitalWrite(LED_BUILTIN, LOW);
      }
      opened = false;
    }

  }

  Serial.print("Distance: ");
  Serial.println(distance);
}
