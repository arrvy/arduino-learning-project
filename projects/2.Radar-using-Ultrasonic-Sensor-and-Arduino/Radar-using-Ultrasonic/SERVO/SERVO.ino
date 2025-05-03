#include <Servo.h>

Servo myservo;
int pos=0;
int i,j,k;
 
 void setup(){
  myservo.attach(9);

 }

 void loop(){
  //inisialisasi pos=0 disini biar pergerakan servo soft
  for (i=0;i<5;i++){
    for (pos=0;pos<=180;pos++){
      myservo.write(pos);
      delay(10);
    }
    for (pos=180;pos>=0;pos--){
      myservo.write(pos);
      delay(10);
    }
  }

  for (j=0;j<3;j++){
    for (pos=0;pos<=180;pos++){
      myservo.write(pos);
      delay(5);
    }
    for (pos=180;pos>=0;pos--){
      myservo.write(pos);
      delay(5);
    }
  }


  


 }
