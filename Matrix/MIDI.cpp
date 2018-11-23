#include "MIDI.h"

MIDI::MIDI()
{
  //usbmidi usbmidi;
}

void MIDI::Begin()
{
  //usbmidi.registerComponent();
}

void MIDI::Poll()
{
  USBMIDI.poll();
}

void MIDI::NoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
{
  //LEDonMIDI(channel, note, velocity);
  if (RETURN)
  {
    MIDI::SentNoteOn(channel, note, velocity);
    // if (CDCenable)
    // {
    //   CDC.print(channel);
    //   CDC.print("\ton\t");
    //   CDC.print(note);
    //   CDC.print("\t");
    //   CDC.println(velocity);
    // }
  }
}

void MIDI::NoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
{
  //LEDoffMIDI(note);
  if (RETURN)
  {
    MIDI::SentNoteOff(channel, note, velocity);
    // if (CDCenable)
    // {
    //   CDC.print(channel);
    //   CDC.print("\toff\t");
    //   CDC.print(note);
    //   CDC.print("\t");
    //   CDC.println(velocity);
    // }
  }
}


void MIDI::SentNoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
{
  USBMIDI.sendNoteOn(channel, note, velocity);
}

void MIDI::SentNoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
{
  USBMIDI.sendNoteOff(channel, note, velocity);
}
