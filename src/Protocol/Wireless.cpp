#include "Wireless.h"

extern MIDI Midi;

Wireless::Wireless()
{
  Serial4.begin(115200);
}


void Wireless::poll()
{
  while(Serial4.available())
  {
    Wireless::getMIDI();
  }
}


void Wireless::getMIDI()
{
  byte midipacket[3];
  Serial4.readBytes(midipacket,3);
  Midi.noteOn(midipacket[0],midipacket[1],midipacket[2]);
}


void Wireless::sentNoteOn(u8 channel, u8 note, u8 velocity)
{
  byte midipacket[3] = {channel, note, velocity};
  Serial4.write(midipacket,3);
}

void Wireless::sentNoteOff(u8 channel, u8 note, u8 velocity)
{
  Wireless::sentNoteOn(channel, note, velocity);
}

void Wireless::sentXYon(u8 xy, u8 velocity)
{
  u8 y = xy & 0x0F;
  u8 x = (xy & 0xF0) >> 4;

  Wireless::sentNoteOn(midi_channel, keymap[current_keymap][y][x], 127);

}

void Wireless::sentXYoff(u8 xy, u8 velocity)
{
  Wireless::sentXYon(xy, velocity);
}
