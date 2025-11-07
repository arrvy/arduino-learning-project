#include <seven_segment.h>

TM1637Display sevenSegment(CLK,DIO);
uint16_t sevenSegmentNumber;
uint8_t sevenSegmentCase = 0;
uint64_t sevenSegmentMillis = 0;
const uint8_t sevenSegmentLove[]={
    SEG_E | SEG_F | SEG_D,
    SEG_C | SEG_D | SEG_E| SEG_G,
    SEG_C | SEG_D | SEG_E,
    SEG_A | SEG_D | SEG_E |SEG_F | SEG_G

};

void sevenSegmentSetup(){
    sevenSegment.setBrightness(0x0f);
}

void sevenSegmentUpdate(){
    if (currentMillis - sevenSegmentMillis > 5000)
    {
        switch (sevenSegmentCase)
        {
        case 0:
            sevenSegment.clear();
            sevenSegmentNumber = dayPassed.toInt();
            Serial.print("Seven Segment Number :");
            Serial.println(sevenSegmentNumber);
            Serial.println(dayPassed);
            sevenSegment.showNumberDec(sevenSegmentNumber,1);
            sevenSegmentCase++;
            break;  
        case 1:
            sevenSegment.clear();
            sevenSegment.setSegments(sevenSegmentLove);
            sevenSegmentCase = 0;
            break;
        default:
            break;
        }
        sevenSegmentMillis = currentMillis;
    }
    

}