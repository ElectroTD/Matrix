#ifndef MATRIX_VARIABLE
#define MATRIX_VARIABLE

#include <Arduino.h>
#include "MatrixParameter.h"

//DeviceInfo
extern uint8_t DeviceID;

//LED
extern uint8_t Brightness;
extern uint64_t ColourPallette[3][128];
extern uint64_t DefaultColourPallette[2][128] PROGMEM;
extern uint8_t BottomLEDMap[NUM_BOTTOM_LEDS];

//KeyPad
extern uint8_t KeyMap [KEYPADY][KEYPADX];
extern uint8_t DefaultKeyMap [KEYPADY][KEYPADX] PROGMEM;

//TouchBar
extern uint8_t TouchSensitive; //0;

//Sysex
extern uint8_t Rotation;
extern uint8_t MIDIChannel;
extern bool GammaEnable;
extern bool MIDIEnable;
extern bool CDCEnable;
extern bool POWERCORD;
extern bool RETURN;

#endif