/*

  nokia5110Flex.h - Library for providing a 6x8 glyph-based interface to the Nokia 5110 LCD screen using hardware SPI
  Written by Rylee Isitt

  The character set is based loosely on codepage 437 and codepage 855, with several custom symbols that I expect will be useful
  To use characters below 0x20 or above 0x7E, use an escape sequence in your string to specify the hex or octal value, eg "\xB8 Your Name" for a copyright notice
  To use completely custom characters, either change an existing one, or uncomment one of the "application specific use" entries at the end of glyphs array and enter the needed bytes
  *** See the example folder for help ***

  LCD wiring instructions:
  * Connect the Vcc pin to 3.3V.
  * All of the LCD's data pins have a 3.3V logic level. If using a 5V microcontroller, use voltage dropping resistors, level shifters, or voltage dividers for ALL lines.
  * For hardware SPI:
    * Connect the SCLK pin of the LCD to the SCK pin of the microcontroller (on Arduino boards, this is usually pin 13, 52, or ICSP-3).
    * Connect the DN/MOSI pin of the LCD to the MOSI pin of the microcontroller (on Arduino boards, this is usually pin 11, 51, or ICSP-4).
    * Avoid using the micocontroller MISO pin except as intended with the SPI protocol (on Arduino boards, this is usually pin 12, 50, or ICSP-1).
    * Avoid using the microcontroller slave select (SS) pin except as intended with the SPI protocol (on Arduino boards, this is usually pin 10 or 53).
    * The other digital pins on the LCD (D/C, RST, and SCE) need their own exclusive digital output pins on your microcontroller.
  * For software SPI (be sure to set hardwareSPI to false when you instantiate nokia5110Flex):
    * Connect each of the LCD's SCLK, DN/MOSI, D/C, RST, and SCE pins to an available digital output pin on your microcontroller.

  Important:
  * run begin() as early as possible in your program's execution
  * Prevent the breakout board from flexing, causing the conductive strip to lose contact with the board, by bolting it down to a rigid surface with appropriate spacers.
  * If using hardware SPI (enabled by default), avoid using the microcontroller's MISO and SS pins except as intended for SPI. When using SPI their functionality is limited.
  * If you are chaining multiple slave devices to SPI, be sure that only one slave is enabled at any given time.

  * If you experience problems:
    * Double check wiring and software.
    * Unclip LCD from board and clean contacts on both the board and the LCD, they are sometimes dirty.
    * If the display is all dark, your contrast setting is probably too high.
    * If you see nothing on the display, your contrast setting may be too low.

*/
#ifndef nokia5110Flex_H
#define nokia5110Flex_H

#include <Arduino.h>
#include <SPI.h>
#include <avr/pgmspace.h>

class nokia5110Flex
{
public:
    nokia5110Flex(uint8_t pinSCE, uint8_t pinRESET, uint8_t pinDC, uint8_t pinLED, uint8_t pinMOSI, uint8_t pinSCLK);
    nokia5110Flex(uint8_t pinSCE, uint8_t pinRESET, uint8_t pinDC, uint8_t pinLED);
    ~nokia5110Flex(void);
    void begin(void);
    void enable(void);
    void disable(void);
    uint8_t setContrast(uint8_t newContrast);
    uint8_t getContrast(void) { return contrast; }
    bool moveCursor(uint8_t x, uint8_t y);
    uint8_t getCursorX(void) { return xChar; }
    uint8_t getCursorY(void) { return yChar; }
    void padToNextLine(uint8_t textByte = 0x20)
    {
        uint8_t padLength = XCHARS - xChar;
        for (uint8_t i = 0; i < padLength; i++)
            writeChar(textByte);
    }
    void write(String text);
    void write(const char *text);
    inline void write(uint8_t number) { write(String(number)); }
    inline void write(int8_t number) { write(String(number)); }
    inline void write(uint16_t number) { write(String(number)); }
    inline void write(int16_t number) { write(String(number)); }
    inline void write(uint32_t number) { write(String(number)); }
    inline void write(int32_t number) { write(String(number)); }
    inline void write(float number) { write(String(number)); }
    inline void write(double number) { write(String(number)); }
    inline void writeLine(String text) { write(text); padToNextLine(); }
    inline void writeLine(const char *text) { write(text); padToNextLine(); }
    inline void writeLine(uint8_t number) { write(String(number)); padToNextLine(); }
    inline void writeLine(int8_t number) { write(String(number)); padToNextLine(); }
    inline void writeLine(uint16_t number) { write(String(number)); padToNextLine(); }
    inline void writeLine(int16_t number) { write(String(number)); padToNextLine(); }
    inline void writeLine(uint32_t number) { write(String(number)); padToNextLine(); }
    inline void writeLine(int32_t number) { write(String(number)); padToNextLine(); }
    inline void writeLine(float number) { write(String(number)); padToNextLine(); }
    inline void writeLine(double number) { write(String(number)); padToNextLine(); }
    void write_P(const char *text);
    void write_P(const char* const* text);
    inline void writeLine_P(const char *text) { write_P(text); padToNextLine(); }
    inline void writeLine_P(const char* const* text) { write_P(text); padToNextLine(); }
    bool writeChar(uint8_t textByte);
    inline bool newLine(void) { return moveCursor(0,++yChar); }
    void cls(void);
    void enableBacklight(void) { digitalWrite(PINLED, HIGH); backlight = true; }
    void disableBacklight(void) { digitalWrite(PINLED, LOW); backlight = false; }
    void toggleBacklight(void) { digitalWrite(PINLED, (backlight ? LOW : HIGH)); backlight = !backlight; }
    bool invert;
    static const uint8_t XPIXELS = 84;
    static const uint8_t YPIXELS = 48;
    static const uint8_t XCHARS = 14;
    static const uint8_t YCHARS = 6;
protected:
    static const uint8_t XADDRS = 84;
    static const uint8_t YADDRS = 6;
    static const uint8_t CHARWIDTH = XPIXELS / XCHARS;
    static const uint8_t NEWLINEBYTE = 0x0A;
    static const uint8_t FUNC_SET = 0x20;
    static const uint8_t FUNC_SET_POWERDOWN = 0x04;
    static const uint8_t FUNC_SET_VERTADDR = 0x02;
    static const uint8_t FUNC_SET_EXTENDED = 0x01;
    static const uint8_t BASIC_DISPBLANK = 0x08;
    static const uint8_t BASIC_DISPNORM = 0x0C;
    static const uint8_t BASIC_DISPALLON = 0x09;
    static const uint8_t BASIC_DISPINVERSE = 0x0D;
    static const uint8_t BASIC_SETX = 0x80;
    static const uint8_t BASIC_SETY = 0x40;
    static const uint8_t EXTENDED_VOP = 0x80;
    static const uint8_t EXTENDED_BIAS = 0x14; // sets bias value
    static const uint8_t EXTENDED_TEMP = 0x04; // temperature coefficient 0
    static const uint32_t SPEED_4MHZ = 4000000UL; // 4 Mhz
    static const uint8_t DEFAULT_CONTRAST = 0x3F;
    const static uint8_t GLYPHS[][CHARWIDTH] PROGMEM;
    const uint8_t PINSCE;
    const uint8_t PINRESET;
    const uint8_t PINDC;
    const uint8_t PINMOSI;
    const uint8_t PINSCLK;
    const uint8_t PINLED;
    const bool HARDWARESPI;
    bool enabled;
    bool backlight;
    uint8_t contrast;
    uint8_t yChar;
    uint8_t xChar;
    inline void setCmdMode(bool isCommand) { digitalWrite(PINDC, (isCommand ? LOW : HIGH)); }
    void send(uint8_t dataOrCmd);
};

#endif
