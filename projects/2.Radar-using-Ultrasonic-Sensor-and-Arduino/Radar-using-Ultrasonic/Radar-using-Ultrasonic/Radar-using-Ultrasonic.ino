#include <Servo.h>

Servo myservo;
int pos=0;
int i,j,k;
 
const int trigPin = 10;
const int echoPin = 11; 

long duration;
long distance;


 void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  myservo.attach(9);
  

 }

 void loop(){
  //inisialisasi pos=0 disini biar pergerakan servo soft
  for (i=0;i<5;i++){
    for (pos=0;pos<=180;pos++){
      myservo.write(pos);
      delay(10);
      outputDistance(pos);
    }
    for (pos=180;pos>=0;pos--){
      myservo.write(pos);
      delay(10);
      outputDistance(pos);
    }
  }

  for (j=0;j<3;j++){
    for (pos=0;pos<=180;pos++){
      myservo.write(pos);
      delay(5);
      outputDistance(pos);
    }
    for (pos=180;pos>=0;pos--){
      myservo.write(pos);
      delay(5);
      outputDistance(pos);
    }
  }
 }


 int calculateDistance(){
  digitalWrite(trigPin,0);
  delayMicroseconds(2);

  digitalWrite(trigPin,1);
  delayMicroseconds(10);
  digitalWrite(trigPin,1);
  duration=pulseIn(echoPin,1);
  distance= duration*0.034/2;
  return distance;
}

int outputDistance(int degree){
   distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(degree); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
}