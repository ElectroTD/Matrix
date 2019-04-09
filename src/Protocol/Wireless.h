#ifndef WIRELESS_H
#define WIRELESS_H

#include "Arduino.h"
#include "../Protocol/MIDI.h"

class Wireless
{
public:
  Wireless();
  void poll();
  void getMIDI();
  void sentNoteOn(u8 channel, u8 note, u8 velocity);
  void sentNoteOff(u8 channel, u8 note, u8 velocity);
  void sentXYon(u8 xy, u8 velocity);
  void sentXYoff(u8 xy, u8 velocity);
};

#endif
