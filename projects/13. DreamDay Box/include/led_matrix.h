#ifndef LED_MATRIX_H 
#define LED_MATRIX_H

#include <pin_definition.h>

// ? Library
#include <LedControl.h>
#include <binary.h>


// ? Include

// ? Function Declaration

extern void ledMatrixSetup();
extern void ledMatrixUpdate();
extern void ledMatrixDrawLove();
extern LedControl ledMatrix;

// ? Variable Declaration

extern uint64_t ledMatrixMillis;

extern byte ledMatrixLove[];

#endif
