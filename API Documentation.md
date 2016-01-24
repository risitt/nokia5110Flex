# nokia5110Flex API documentation for Arduino
For an example that implements most of the API methods below, please see the "lcdDemo" sketch in the examples folder.

## Table of Contents
* Starting the library
	* [Configuring and Instantiating nokia5110Flex](#configinstance)
	* [begin()](#begin)
* Writing and positioning text/symbols on the LCD
	* [cls()](#cls)
	* [write() and write_P()](#write)
	* [writeNum()](#writenum)
	* [writeChar()](#writeChar)
	* [newLine()](#newline)
	* [invert](#invert)
	* [moveCursor()](#movecursor)
	* [getCursorX() and getCursorY()](#getcursor)
* Other functions
	* [enableBacklight() and disableBacklight()](#backlight)
	* [enable() and disable()](#enabledisable)
	* [setContrast() and getContrast()](#contrast)
	* [Creating custom glyphs](#custglyphs)


## <a name="configinstance">Configuring and Instantiating nokia5110Flex</a>
First, you need to #include the library and glyphs file in your sketch:

### Example:
```C++
\#include <nokia5110Flex.h>
\#include <nokia5110Glyphs.h> // you can use a different file in your sketch folder that specifies custom glyphs
```

Next, you must create an instance of the nokia5110Flex class. You can create multiple instances to drive multiple screens. This is typically done in the global scope (near the top of your sketch, outside of the loop() or setup() routines).

This is also how you set the configuration options that tell nokia5110Flex what pins you've used and whether to use hardware or software SPI.

If you use hardware SPI, it is important that you connect the LCD's MOSI and SCLK pins to the matching pins on your microcontroller. On an Arduino UNO, Duemilanove, or Pro, the MOSI pin is 11 and the SCLK pin is 13. Additionally, two of the digital out pins (SS and MISO) on your microcontroller are reserved for receiving data. These two pins should *not* be connected to your LCD. On an Arduino UNO, Duemilanove, or Pro, the SS pin is 10 and the MISO pin is 13.

### Example:
```C++
nokia5110Flex lcd(byte pinSCE, byte pinRESET, byte pinDC, byte pinMOSI, byte pinSCLK, byte pinLED, bool hardwareSPI = true); // general syntax
nokia5110Flex lcd(9, 8, 7, 11, 13, 6); // use hardware SPI on an Arduino UNO, Duemilanove or Pro
nokia5110Flex lcd(13, 12, 11, 10, 9, 8, false); // use software SPI
```

## <a name="begin">void begin(void)</a>
You must do this (once) after instantiating nokia5110Flex, usually in the setup section of your sketch. This initializes the display. **You should call begin() within 100ms of powering on your device.**

### Example:
```C++
void setup(void)
{
	lcd.begin(); // initialize the LCD
	...
}
```

## <a name="cls">void cls(void)</a>
Clears the screen and resets the cursor to 0,0.

### Example:
```C++
lcd.cls();
```

## <a name="write">void write(...) and void write_P(...)</a>
Both of these methods write a string to the LCD starting at the current cursor position and advance the cursor to the next available position. The write() method will accept either a String object or c-style string as a parameter, but the write_P() method will only work with c-style strings.

You can use the \n escape sequence within a string to go to the next line. You can also print special characters using the \x__ escape sequence format, where the byte that follows \x refers to the numeric index of the desired glyph (see the charset.png file or the glyphs array in nokia5110Flex.cpp). For example, \xB8 is a copyright symbol.

For strings stored in PROGMEM, you must use write_P. Otherwise, use write().

### Example:
```C++
lcd.write("Some text."); // text not stored in PROGMEM
lcd.write_P(PSTR("\n\n\xB8 2016\nRylee Isitt")); // text stored in PROGMEM
```

## <a name="writenum">void writeNum(...)</a>
Writes a number (byte, int, word, long, float, etc) to the LCD starting at the current cursor position and advances the cursor to the next available position.

### Example:
```C++
lcd.writeNum(100);
```

## <a name="writenum">bool writeChar(byte textByte)</a>
This method writes a single character to the LCD starting at the current cursor position and advances the cursor. If you need to write output to the screen character by character, using this method is faster than passing single characters to the write() method. This method can accept either character literals (use single quotes) or a byte that specifies the numeric index of a glyph.

Returns true as long as the cursor is at a valid position.

### Example:
```C++
lcd.writeChar('A'); // writes the letter A to the LCD screen
lcd.writeChar(0xB8); // writes a copyright symbol to the LCD screen
```

## <a name="movecursor">bool moveCursor(byte x, byte y)</a>
Moves the cursor to the character position specified by x (the column) and y (the row). The LCD has 14 columns and 6 rows of characters. Coordinates are zero indexed, so x ranges from 0 to 13 and y ranges from 0 to 5. The next time a string or number is written to the LCD, it will start at the specified position.

This functions returns true as long as the specified coordinates are valid.

### Example:
```C++
bool validCoords = lcd.moveCursor(3,5); // move the cursor to the 4th column of the 6th row
```

## <a name="movecursor">byte getCursorX(void) and byte getCursorY(void)</a>
These two methods get the current cursor x and y position, respectively.

### Example:
```C++
// record current cursor position
byte prevX = lcd.getCursorX();
byte prevY = lcd.getCursorY();

// move to temporary location and write
lcd.moveCursor(3,5);
lcd.writeChar('x');

// return to previous location
lcd.moveCursor(prevX, prevY);
```


## <a name="newline">bool newLine(void)</a>
Moves the cursor to the first column of the next row and returns true if the new cursor position is valid. If you want to wrap a string over multiple lines, use the \n escape sequence inside of the string instead of using newLine() in between multiple writes.

### Example:
```C++
bool validCoords = lcd.newLine(); // move the cursor to the next line
```

## <a name="invert">invert</a>
A property that you can set to true or false. If set to true, all subsequent text written to the LCD will appear inverted (light text on a dark background) until *invert* is set to false again.

### Example:
```C++
lcd.invert = true; // make text inverted
lcd.write("This text is\ninverted");
lcd.invert = false; // make text normal again
lcd.write("\nThis text is/nnot inverted");
```

## <a name="backlight">void enableBacklight(void) and void disableBacklight(void)</a>
The backlight defaults to being off. You can use these methods to turn it on and off as desired.

### Example:
```C++
lcd.enableBacklight(); // turns the backlight on
```

## <a name="enabledisable">void enable(void) and void disable(void)</a>
These two methods allow you to the enable or disable the LCD's serial interface. You should not need to use them unless you are chaining multiple devices over the same SPI lines, in which case you would disable all but one device at a time. The enable() method is automatically called by most other functions, so it can usually be omitted.

### Example:
```C++
lcdB.disable();
lcdA.write("Screen 1"); // automatically enable lcdA and print the string
lcdA.disable();
lcdB.write("Screen 2"); // automatically enable lcdB and print the string
```

## <a name="contrast">byte setContrast(byte contrast) and byte getContrast(void)</a>
These two methods allow you to set and get the contrast setting. If the display is showing all dark pixels, your contrast setting is probably too high. If you see nothing on the display, your contrast setting may be too low. The default is 0x3F. Both methods return the current contrast.

The contrast is changed without resetting the display and does not clear text currently on the display. This allows your project to impliment an interactive contrast adjustment.

### Example:
```C++
byte prevContrast = lcd.getContrast();
lcd.setContrast(prevContrast+1); // increment the contrast setting
```

## <a name="custglyphs">Creating custom glyphs</a>
Inside the library src folder you will find a nokia5110Glyphs.h file. This file contains a 2 dimensional array of bytes that tells the library how to draw all of the glyphs. To customize these glyphs:

1. Place a copy of this file in the same folder as your sketch.
2. Change the file name so that it differs from the original, eg customGlyphs.h
3. Instead of #include <nokia5110Glyphs.h>, use #include "customGlyphs.h" where customGlyphs.h matches the file name of your custom glyphs file. **Note the double quotes!**
4. Modify the custom glyphs file in your sketch folder as desired.

To make adding or modifying glyphs easier, use the charmaker.xlsx spreadsheet that is included with this library. It will generate the corresponding array of bytes for any 6x8 character.