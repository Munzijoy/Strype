/*
 * LedWrapper.h
 *
 *  Created on: 08.11.2016
 *      Author: t.linz
 */

#ifndef LEDWRAPPER_H_
#define LEDWRAPPER_H_

#include <stdint.h>
#include <map>
#include <string>
#include <exception>

#include "LookupTable.h"

namespace Application {

// static class to simplify access to the LEDs without accessing the MAX7219 driver hardware directly
class LedWrapper {
    friend class DisplayMode;
    friend class Lookuptable;
public:
    // sets the color for all leds of the panel from the outside
    static void InitLedWrapper(void);
    static void DisplayString(std::string stringToDisplay, uint16_t delayShift = 20, uint16_t delayEnd = 1000);
    static const char* Get8x8Character(const char character){
      return font8x8_basic[static_cast<uint8_t>(character - FONT_OFFSET)]; 
    }
    
    static void DisplayStringSimple(std::string stringToDisplay);
    static bool IsValidCharacter(char c){ return (c > FONT_OFFSET) && (c < 128); }
private:
    static void ClearPanel(void);
    
    static const uint8_t FONT_OFFSET = 0;
    // Constant: font8x8_basic
// Contains an 8x8 font map for unicode points U+0000 - U+007F (basic latin)
    static constexpr char font8x8_basic[128 - FONT_OFFSET][8] = {
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // 0x00
{0x7E,0x81,0xA5,0x81,0xBD,0x99,0x81,0x7E},  // 0x01
{0x7E,0xFF,0xDB,0xFF,0xC3,0xE7,0xFF,0x7E},  // 0x02
{0x36,0x7F,0x7F,0x7F,0x3E,0x1C,0x08,0x00},  // 0x03
{0x08,0x1C,0x3E,0x7F,0x3E,0x1C,0x08,0x00},  // 0x04
{0x1C,0x3E,0x1C,0x7F,0x7F,0x6B,0x08,0x1C},  // 0x05
{0x08,0x08,0x1C,0x3E,0x7F,0x3E,0x08,0x1C},  // 0x06
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // 0x07
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // 0x08
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // 0x09
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // 0x0A
{0xF0,0xE0,0xF0,0xBE,0x33,0x33,0x33,0x1E},  // 0x0B
{0x3C,0x66,0x66,0x66,0x3C,0x18,0x7E,0x18},  // 0x0C
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // 0x0D
{0xFE,0xC6,0xFE,0xC6,0xC6,0xE6,0x67,0x03},  // 0x0E
{0x99,0x5A,0x3C,0xE7,0xE7,0x3C,0x5A,0x99},  // 0x0F
{0x01,0x07,0x1F,0x7F,0x1F,0x07,0x01,0x00},  // 0x10
{0x40,0x70,0x7C,0x7F,0x7C,0x70,0x40,0x00},  // 0x11
{0x18,0x3C,0x7E,0x18,0x18,0x7E,0x3C,0x18},  // 0x12
{0x66,0x66,0x66,0x66,0x66,0x00,0x66,0x00},  // 0x13
{0xFE,0xDB,0xDB,0xDE,0xD8,0xD8,0xD8,0x00},  // 0x14
{0x7E,0xC3,0x1E,0x33,0x33,0x1E,0x31,0x1F},  // 0x15
{0x00,0x00,0x00,0x00,0x7E,0x7E,0x7E,0x00},  // 0x16
{0x18,0x3C,0x7E,0x18,0x7E,0x3C,0x18,0xFF},  // 0x17
{0x18,0x3C,0x7E,0x18,0x18,0x18,0x18,0x00},  // 0x18
{0x18,0x18,0x18,0x18,0x7E,0x3C,0x18,0x00},  // 0x19
{0x00,0x18,0x30,0x7F,0x30,0x18,0x00,0x00},  // 0x1A
{0x00,0x0C,0x06,0x7F,0x06,0x0C,0x00,0x00},  // 0x1B
{0x00,0x00,0x03,0x03,0x03,0x7F,0x00,0x00},  // 0x1C
{0x00,0x24,0x66,0xFF,0x66,0x24,0x00,0x00},  // 0x1D
{0x00,0x18,0x3C,0x7E,0xFF,0xFF,0x00,0x00},  // 0x1E
{0x00,0xFF,0xFF,0x7E,0x3C,0x18,0x00,0x00},  // 0x1F
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // 0x20
{0x0C,0x1E,0x1E,0x0C,0x0C,0x00,0x0C,0x00},  // 0x21
{0x36,0x36,0x36,0x00,0x00,0x00,0x00,0x00},  // 0x22
{0x36,0x36,0x7F,0x36,0x7F,0x36,0x36,0x00},  // 0x23
{0x0C,0x3E,0x03,0x1E,0x30,0x1F,0x0C,0x00},  // 0x24
{0x00,0x63,0x33,0x18,0x0C,0x66,0x63,0x00},  // 0x25
{0x1C,0x36,0x1C,0x6E,0x3B,0x33,0x6E,0x00},  // 0x26
{0x06,0x06,0x03,0x00,0x00,0x00,0x00,0x00},  // 0x27
{0x18,0x0C,0x06,0x06,0x06,0x0C,0x18,0x00},  // 0x28
{0x06,0x0C,0x18,0x18,0x18,0x0C,0x06,0x00},  // 0x29
{0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00},  // 0x2A
{0x00,0x0C,0x0C,0x3F,0x0C,0x0C,0x00,0x00},  // 0x2B
{0x00,0x00,0x00,0x00,0x00,0x0E,0x0C,0x06},  // 0x2C
{0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00},  // 0x2D
{0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00},  // 0x2E
{0x60,0x30,0x18,0x0C,0x06,0x03,0x01,0x00},  // 0x2F
{0x1E,0x33,0x3B,0x3F,0x37,0x33,0x1E,0x00},  // 0x30
{0x0C,0x0F,0x0C,0x0C,0x0C,0x0C,0x3F,0x00},  // 0x31
{0x1E,0x33,0x30,0x1C,0x06,0x33,0x3F,0x00},  // 0x32
{0x1E,0x33,0x30,0x1C,0x30,0x33,0x1E,0x00},  // 0x33
{0x38,0x3C,0x36,0x33,0x7F,0x30,0x30,0x00},  // 0x34
{0x3F,0x03,0x1F,0x30,0x30,0x33,0x1E,0x00},  // 0x35
{0x1C,0x06,0x03,0x1F,0x33,0x33,0x1E,0x00},  // 0x36
{0x3F,0x33,0x30,0x18,0x0C,0x06,0x06,0x00},  // 0x37
{0x1E,0x33,0x33,0x1E,0x33,0x33,0x1E,0x00},  // 0x38
{0x1E,0x33,0x33,0x3E,0x30,0x18,0x0E,0x00},  // 0x39
{0x00,0x00,0x0C,0x0C,0x00,0x0C,0x0C,0x00},  // 0x3A
{0x00,0x00,0x0C,0x0C,0x00,0x0E,0x0C,0x06},  // 0x3B
{0x18,0x0C,0x06,0x03,0x06,0x0C,0x18,0x00},  // 0x3C
{0x00,0x00,0x3F,0x00,0x3F,0x00,0x00,0x00},  // 0x3D
{0x06,0x0C,0x18,0x30,0x18,0x0C,0x06,0x00},  // 0x3E
{0x1E,0x33,0x30,0x18,0x0C,0x00,0x0C,0x00},  // 0x3F
{0x3E,0x63,0x7B,0x7B,0x7B,0x03,0x1E,0x00},  // 0x40
{0x0C,0x1E,0x33,0x33,0x3F,0x33,0x33,0x00},  // 0x41
{0x3F,0x66,0x66,0x3E,0x66,0x66,0x3F,0x00},  // 0x42
{0x3C,0x66,0x03,0x03,0x03,0x66,0x3C,0x00},  // 0x43
{0x3F,0x36,0x66,0x66,0x66,0x36,0x3F,0x00},  // 0x44
{0x7F,0x46,0x16,0x1E,0x16,0x46,0x7F,0x00},  // 0x45
{0x7F,0x46,0x16,0x1E,0x16,0x06,0x0F,0x00},  // 0x46
{0x3C,0x66,0x03,0x03,0x73,0x66,0x7C,0x00},  // 0x47
{0x33,0x33,0x33,0x3F,0x33,0x33,0x33,0x00},  // 0x48
{0x1E,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00},  // 0x49
{0x78,0x30,0x30,0x30,0x33,0x33,0x1E,0x00},  // 0x4A
{0x67,0x66,0x36,0x1E,0x36,0x66,0x67,0x00},  // 0x4B
{0x0F,0x06,0x06,0x06,0x46,0x66,0x7F,0x00},  // 0x4C
{0x63,0x77,0x7F,0x6B,0x63,0x63,0x63,0x00},  // 0x4D
{0x63,0x67,0x6F,0x7B,0x73,0x63,0x63,0x00},  // 0x4E
{0x1C,0x36,0x63,0x63,0x63,0x36,0x1C,0x00},  // 0x4F
{0x3F,0x66,0x66,0x3E,0x06,0x06,0x0F,0x00},  // 0x50
{0x1E,0x33,0x33,0x33,0x3B,0x1E,0x38,0x00},  // 0x51
{0x3F,0x66,0x66,0x3E,0x1E,0x36,0x67,0x00},  // 0x52
{0x1E,0x33,0x07,0x1C,0x38,0x33,0x1E,0x00},  // 0x53
{0x3F,0x2D,0x0C,0x0C,0x0C,0x0C,0x1E,0x00},  // 0x54
{0x33,0x33,0x33,0x33,0x33,0x33,0x3F,0x00},  // 0x55
{0x33,0x33,0x33,0x33,0x33,0x1E,0x0C,0x00},  // 0x56
{0x63,0x63,0x63,0x6B,0x7F,0x77,0x63,0x00},  // 0x57
{0x63,0x63,0x36,0x1C,0x36,0x63,0x63,0x00},  // 0x58
{0x33,0x33,0x33,0x1E,0x0C,0x0C,0x1E,0x00},  // 0x59
{0x7F,0x33,0x19,0x0C,0x46,0x63,0x7F,0x00},  // 0x5A
{0x1E,0x06,0x06,0x06,0x06,0x06,0x1E,0x00},  // 0x5B
{0x03,0x06,0x0C,0x18,0x30,0x60,0x40,0x00},  // 0x5C
{0x1E,0x18,0x18,0x18,0x18,0x18,0x1E,0x00},  // 0x5D
{0x08,0x1C,0x36,0x63,0x00,0x00,0x00,0x00},  // 0x5E
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF},  // 0x5F
{0x0C,0x0C,0x18,0x00,0x00,0x00,0x00,0x00},  // 0x60
{0x00,0x00,0x1E,0x30,0x3E,0x33,0x6E,0x00},  // 0x61
{0x07,0x06,0x3E,0x66,0x66,0x66,0x3D,0x00},  // 0x62
{0x00,0x00,0x1E,0x33,0x03,0x33,0x1E,0x00},  // 0x63
{0x38,0x30,0x30,0x3E,0x33,0x33,0x6E,0x00},  // 0x64
{0x00,0x00,0x1E,0x33,0x3F,0x03,0x1E,0x00},  // 0x65
{0x1C,0x36,0x06,0x0F,0x06,0x06,0x0F,0x00},  // 0x66
{0x00,0x00,0x6E,0x33,0x33,0x3E,0x30,0x1F},  // 0x67
{0x07,0x06,0x36,0x6E,0x66,0x66,0x67,0x00},  // 0x68
{0x0C,0x00,0x0E,0x0C,0x0C,0x0C,0x1E,0x00},  // 0x69
{0x18,0x00,0x1E,0x18,0x18,0x18,0x1B,0x0E},  // 0x6A
{0x07,0x06,0x66,0x36,0x1E,0x36,0x67,0x00},  // 0x6B
{0x0E,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00},  // 0x6C
{0x00,0x00,0x37,0x7F,0x6B,0x63,0x63,0x00},  // 0x6D
{0x00,0x00,0x1F,0x33,0x33,0x33,0x33,0x00},  // 0x6E
{0x00,0x00,0x1E,0x33,0x33,0x33,0x1E,0x00},  // 0x6F
{0x00,0x00,0x3B,0x66,0x66,0x3E,0x06,0x0F},  // 0x70
{0x00,0x00,0x6E,0x33,0x33,0x3E,0x30,0x78},  // 0x71
{0x00,0x00,0x1B,0x36,0x36,0x06,0x0F,0x00},  // 0x72
{0x00,0x00,0x3E,0x03,0x1E,0x30,0x1F,0x00},  // 0x73
{0x08,0x0C,0x3E,0x0C,0x0C,0x2C,0x18,0x00},  // 0x74
{0x00,0x00,0x33,0x33,0x33,0x33,0x6E,0x00},  // 0x75
{0x00,0x00,0x33,0x33,0x33,0x1E,0x0C,0x00},  // 0x76
{0x00,0x00,0x63,0x63,0x6B,0x7F,0x36,0x00},  // 0x77
{0x00,0x00,0x63,0x36,0x1C,0x36,0x63,0x00},  // 0x78
{0x00,0x00,0x33,0x33,0x33,0x3E,0x30,0x1F},  // 0x79
{0x00,0x00,0x3F,0x19,0x0C,0x26,0x3F,0x00},  // 0x7A
{0x38,0x0C,0x0C,0x07,0x0C,0x0C,0x38,0x00},  // 0x7B
{0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x00},  // 0x7C
{0x07,0x0C,0x0C,0x38,0x0C,0x0C,0x07,0x00},  // 0x7D
{0x6E,0x3B,0x00,0x00,0x00,0x00,0x00,0x00},  // 0x7E
{0x08,0x1C,0x36,0x63,0x63,0x63,0x7F,0x00},  // 0x7F
};
};

}

class DisplayException : public std::exception {
public:
  DisplayException(const char* exceptionString){ Application::LedWrapper::DisplayString(exceptionString); }
};

#endif /* LEDWRAPPER_H_ */
