#include "../Parameter/MatrixVariable.h"

//LED setting
extern u8 brightness = 64;
extern u16 max_mAh = 1000;
extern u8 fps = 60;

extern u32 palette[2][128] =     //WRGB Colour Palette
{{            //MatrixColorPalette
  0x00000000, //0
  0x00050505, //1
  0x00101010, //2
  0x00242424, //3
  0x004E4E4E, //4
  0x00727272, //5
  0x00AFAFAF, //6
  0x00FFFFFF, //7
  0x00130000, //8
  0x00270000, //9
  0x005D0000, //10
  0x00A20000, //11
  0x00FF0000, //12
  0x00FF0C0C, //13
  0x00FF1F1F, //14
  0x00FF3F3F, //15
  0x00130500, //16
  0x00270A00, //17
  0x005D1700, //18
  0x00A22900, //19
  0x00FF4000, //20
  0x00FF490C, //21
  0x00FF571F, //22
  0x00FF6F3F, //23
  0x00130A00, //24
  0x00271400, //25
  0x005D2F00, //26
  0x00A25100, //27
  0x00FF8000, //28
  0x00FF860C, //29
  0x00FF8F1F, //30
  0x00FF9F3F, //31
  0x00130E00, //32
  0x00271D00, //33
  0x005D4600, //34
  0x00A27A00, //35
  0x00FFBF00, //36
  0x00FFC20C, //37
  0x00FFC71F, //38
  0x00FFCF3F, //39
  0x00131300, //40
  0x00272700, //41
  0x005D5D00, //42
  0x00A2A200, //43
  0x00FFFF00, //44
  0x00FFFF0C, //45
  0x00FFFF1F, //46
  0x00FFFF3F, //47
  0x000A1300, //48
  0x00142700, //49
  0x002F5D00, //50
  0x0051A200, //51
  0x0080FF00, //52
  0x0086FF0C, //53
  0x008FFF1F, //54
  0x009FFF3F, //55
  0x00001300, //56
  0x00002700, //57
  0x00005D00, //58
  0x0000A200, //59
  0x0000FF00, //60
  0x000CFF0C, //61
  0x001FFF1F, //62
  0x003FFF3F, //63
  0x0000130D, //64
  0x0000271A, //65
  0x00005D3E, //66
  0x0000A26C, //67
  0x0000FFAA, //68
  0x000CFFAE, //69
  0x001FFFB4, //70
  0x003FFFBF, //71
  0x00001113, //72
  0x00002727, //73
  0x00005D5D, //74
  0x0000A2A2, //75
  0x0000FFFF, //76
  0x000CFFFF, //77
  0x001FFFFF, //78
  0x003FFFFF, //79
  0x00000A13, //80
  0x00001427, //81
  0x00002F5D, //82
  0x000051A2, //83
  0x000080FF, //84
  0x000C86FF, //85
  0x001F8FFF, //86
  0x003F9FFF, //87
  0x00000013, //88
  0x00000027, //89
  0x0000005D, //90
  0x000000A2, //91
  0x000000FF, //92
  0x000C0CFF, //93
  0x001F1FFF, //94
  0x003F3FFF, //95
  0x000A0013, //96
  0x00140027, //97
  0x002F005D, //98
  0x005100A2, //99
  0x008000FF, //100
  0x00860CFF, //101
  0x008F1FFF, //102
  0x009F3FFF, //103
  0x00130013, //104
  0x00270027, //105
  0x005D005D, //106
  0x00A200A2, //107
  0x00FF00FF, //108
  0x00FF0CFF, //109
  0x00FF1FFF, //110
  0x00FF3F9F, //111
  0x0013000A, //112
  0x00270014, //113
  0x005D002F, //114
  0x00A20051, //115
  0x00FF0080, //116
  0x00FF0C86, //117
  0x00FF1F8F, //118
  0x00FF3F9F, //119
  0x00130005, //120
  0x0027000A, //121
  0x005D0017, //122
  0x00A20029, //123
  0x00FF0040, //124
  0x00FF0C49, //125
  0x00FF1F57, //126
  0x00FF3F6F  //127
}};
