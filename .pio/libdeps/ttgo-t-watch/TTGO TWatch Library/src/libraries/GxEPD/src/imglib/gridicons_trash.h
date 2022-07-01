#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
// 24 x 24 gridicons_trash
const unsigned char gridicons_trash[] PROGMEM = { /* 0X01,0X01,0XB4,0X00,0X40,0X00, */
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x81, 
0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x3C, 0xFF, 0xF8, 
0x00, 0x1F, 0xF8, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 
0xFC, 0x00, 0x3F, 0xFC, 0x00, 0x3F, 0xFC, 0x00, 
0x3F, 0xFE, 0x00, 0x7F, 0xFC, 0x00, 0x3F, 0xFE, 
0x00, 0x7F, 0xFC, 0x00, 0x3F, 0xFE, 0x00, 0x7F, 
0xFE, 0x00, 0x7F, 0xFE, 0x00, 0x7F, 0xFE, 0x00, 
0x7F, 0xFE, 0x00, 0x7F, 0xFF, 0x00, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
