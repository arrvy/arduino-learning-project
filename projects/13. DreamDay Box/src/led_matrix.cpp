#include <led_matrix.h>

LedControl ledMatrix(MDIN,MCLK,MCS,1);

uint64_t ledMatrixMillis = 0;

byte ledMatrixLove[8] = {B00000000,
                B01100110,
                B11111111,
                B11111111,
                B01111110,
                B00111100,
                B00011000,
                B00000000           
                };


void ledMatrixSetup(){
    ledMatrix.shutdown(0,false);
    ledMatrix.setIntensity(0,1);
    ledMatrix.clearDisplay(0);

}

void ledMatrixDrawLove(){
    if (currentMillis - ledMatrixMillis > 10000)
    ledMatrix.setRow(0,0,ledMatrixLove[0]);
    ledMatrix.setRow(0,1,ledMatrixLove[1]);
    ledMatrix.setRow(0,2,ledMatrixLove[2]);
    ledMatrix.setRow(0,3,ledMatrixLove[3]);
    ledMatrix.setRow(0,4,ledMatrixLove[4]);
    ledMatrix.setRow(0,5,ledMatrixLove[6]);
    ledMatrix.setRow(0,6,ledMatrixLove[6]);
    ledMatrix.setRow(0,7,ledMatrixLove[7]);
    ledMatrixMillis = currentMillis;
}
