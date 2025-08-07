#include <servo_mode.h>


//* Nilai normal/not energize usahakan 90°
uint_fast8_t servoValue[4] = {90,90,90,90};
uint_fast8_t servoValueSmoothed[4]={0,0,0,0};
uint_fast8_t servoValuePast[4] = {90,90,90,90};
uint_fast8_t writingIteration = 0;


Servo servo_1,servo_2,servo_3,servo_4;

void ManualMode(){

    // Ubak pake array pins PotentioPins[]
     readPotentiometer(POTENTIO_1_ROTATION,0);
     readPotentiometer(POTENTIO_2_SHOULDER,1);
     readPotentiometer(POTENTIO_3_ELBOW,2);
     readPotentiometer(POTENTIO_4_GRIP,3);

    for(int i = 0; i < 4 ; i++){
        
        writePotentiometer(i);
    }

    writeServo(potentiometerValue);

    
}


void writeServo(uint_fast8_t potentiometer[]){
    
// to smoothen the movement of the servo
    for(int i = 0; i< 4; i++){
        servoValueSmoothed[i] = (servoValuePast[i] * 0.95) + (potentiometer[i] * 0.05);
        servoValuePast[i]=servoValueSmoothed[i]; 
        //* Jangan lupa inisialisasi servo
    }

    servo_1.write(servoValueSmoothed[0]);
    servo_2.write(servoValueSmoothed[1]);
    servo_3.write(servoValueSmoothed[2]);
    servo_4.write(servoValueSmoothed[3]);
}

void initServo(){
    servo_1.attach(ServoPins[0]);
    servo_2.attach(ServoPins[1]);
    servo_3.attach(ServoPins[2]);
    servo_4.attach(ServoPins[3]);
}