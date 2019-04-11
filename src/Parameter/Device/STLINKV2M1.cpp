#include "../DeviceSelector.h"

void loadConfigSTLINKV2M1()
{

  //LED
  led_pin = PB11;
  sys_led_pin = PA7;

  led_color_correction = 0xFFFFFF;

  support_wrgb = false;

  brightness_button = 0;

  flash_button = 0;

  //EEPROM
  eeprom_enable = false;
  eeprom_user_adds_0 = 0;
  eeprom_user_adds_1 = 0;
  eeprom_palette_adds_0 = 0;
  eeprom_palette_adds_1 = 0;
  eeprom_sys_adds_0 = 0;
  eeprom_sys_adds_1 = 0;
  eeprom_pagesize = 0x400;
}
