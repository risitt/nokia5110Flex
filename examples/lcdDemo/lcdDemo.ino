/*

This software is intended for demonstrating the nokia5110Flex library

Written by Rylee Isitt
January 23, 2016

This software is licensed under the GPL v3

*/
#include <SPI.h> // this shouldn't be necessary, but Arduino IDE 1.6.5 has a problem with including SPI.h from a library
#include <nokia5110Flex.h>
#include <nokia5110Glyphs.h>

// Pinout
// Avoid assinging pins 12 and 10 on Arduino UNO, Duemilanove, or Pro when using hardware SPI
// Consult Arduino SPI reference for wiring on other boards
const byte pinLCDSCE = 9;
const byte pinLCDRST = 8;
const byte pinLCDDC = 7;
const byte pinLCDMOSI = 11;
const byte pinLCDSCLK = 13;
const byte pinLCDLED = 6;

// instantiate the nokia5110Flex class for hardware SPI (four pin parameters passed to constructor)
nokia5110Flex lcd(pinLCDSCE, pinLCDRST, pinLCDDC, pinLCDLED);

// instantiate the nokia5110Flex class for software SPI (six pin parameters passed to constructor)
// this is much slower than hardware SPI but it does allow you more flexible assignment of digital out pins
// nokia5110Flex lcd(pinLCDSCE, pinLCDRST, pinLCDDC, pinLCDLED, pinLCDMOSI, pinLCDSCLK);

// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------

void loop(void)
{

    static unsigned int uptime = 0;
    static unsigned long lastTime = 0;
    unsigned long curTime = micros();

    if ((curTime - lastTime) >= 1000000UL)
    {
        lcd.moveCursor(0,0); // make sure that refreshes start at the top left
        lcd.invert = true; // set invert to true to make inverted text (light text on a dark background)
        lcd.write_P(PSTR("SYSTEM STATUS ")); // always use write_P() when sending strings stored in PROGMEM.
        lcd.invert = false; // set invert to false when you no longer want inverted text

        lcd.write("Uptime:"); // use write() to send normal strings
        lcd.write(uptime); // you can output numbers, too
        lcd.writeChar('s'); // you can use writeChar() to write single characters to the LCD

        lcd.newLine(); // one way of going to the next line
        lcd.write_P(PSTR("Contrast:"));
        lcd.write(lcd.getContrast()); // you get get and set the LCD's contrast

        // Another way of adding a newline is to use the \n escape sequence inside a string literal
        // \x__ escape sequences can also be used to specify special characters by their hex value
        lcd.write_P(PSTR("\n\nHej d\x8B!"));

        uptime++;
        lastTime = curTime;
    }

}

// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------

void setup(void)
{
    lcd.begin(); // initialize LCD
    lcd.enableBacklight(); // turn the backlight on
    lcd.cls(); // clear the display
}
