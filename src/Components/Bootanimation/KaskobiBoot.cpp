#include "../UI.h"

extern KeyPad KeyPad;
extern LED LED;
extern MIDI Midi;

void UI::kaskobiWaitAnimation()
{
  brightness_cache = brightness;
  if(brightness > 96)
    LED.setBrightness(96);

  if(uiTimer.tick(300))
  {
    if(onPause)
    {
      onPause --;
    }
    else if(LED.readXYLED(0x07))
    {
      for (u8 i = 64; i > 0; i--)
      {
        LED.setXYW(0x07, led_gamma[(i*4)-1], true);
        LED.update();
        delay(10);
      }
      LED.offXY(0x07, true);
      LED.update();
      onPause = 2;
    }
    else
    {
      for (u8 i = 1; i <= 64; i++)
      {
        LED.setXYW(0x07, led_gamma[(i*4)-1], true);
        LED.update();
        delay(10);
      }
    onPause = 2;
    }
    LED.update();
  }
}

void UI::kaskobiBootAnimation() //8x8 only
{
  LED.fill(0);
  LED.enableOverlayMode();
  //StageOne
  u16 delay = 60;
  for(s8 y = 7; y >= 0; y--)
  {
    for(u8 x = 0; x < 8; x++)
    {
      while(!uiTimer.isLonger(delay))
      {
        // if(Midi.available())
        // {
        //   LED.disableOverlayMode();
        //   return;
        // }

        KeyPad.scan();
        if(KeyPad.fn.state == PRESSED)
        {
          LED.setBrightness(brightness_cache);
          LED.disableOverlayMode();
          return;
        }
      }
      uiTimer.recordCurrent();
      LED.onXY(xytoxy(x, y), true);
      LED.update();
    }
    delay *= 0.8;
  }

  // uiTimer.recordCurrent();
  // while(!uiTimer.isLonger(30))
  // {
  //   KeyPad.scan();
  //   if(KeyPad.fnChanged)
  //   {
  //     if(!KeyPad.fn)
  //     {
  //       LED.disableOverlayMode();
  //       return;
  //     }
  //   }
  // }

  //Stage2
  delay = 15;

  //shuffle the array
  u8 shuffle[NUM_LEDS];
  for(u8 i = 0; i < NUM_LEDS; i++)
  {
    shuffle[i] = i;
  }
  //randomSeed(analogRead(PC3) * analogRead(PC4) * analogRead(PC5));
  randomSeed(micros());

  for (u16 i = 0; i < 500; i++)
  {
    u8 r1 = random(0, NUM_LEDS);
    u8 r2 = random(0, NUM_LEDS);
    u8 t = shuffle[r1];
    shuffle[r1] = shuffle[r2];
    shuffle[r2] = t;
  }

  for(int i = 0; i <NUM_LEDS+15; i++)
  {

    while(!uiTimer.isLonger(delay))
    {
      // if(Midi.available())
      // {
      //   LED.disableOverlayMode();
      //   return;
      // }

      KeyPad.scan();
      if(KeyPad.fn.state == PRESSED)
      {
        LED.setBrightness(brightness_cache);
        LED.disableOverlayMode();
        return;
      }
    }
    uiTimer.recordCurrent();
    if(i < NUM_LEDS)
    LED.setPalette(shuffle[i], 0, 44, true);
    if(i > 0 && i < NUM_LEDS + 2)
    LED.setPalette(shuffle[i-2], 0, 28, true);
    if(i > 1 && i < NUM_LEDS + 4)
    LED.setPalette(shuffle[i-4], 0, 12, true);
    if(i > 2 && i < NUM_LEDS + 6)
    LED.setPalette(shuffle[i-6], 0, 116, true);
    if(i > 3 && i < NUM_LEDS + 8)
    LED.setPalette(shuffle[i-8], 0, 102, true);
    if(i > 4 && i < NUM_LEDS + 10)
    LED.off(shuffle[i-10], true);

    LED.update();
  }
  //end
  LED.setBrightness(brightness_cache);
  LED.disableOverlayMode();
  return;
}
