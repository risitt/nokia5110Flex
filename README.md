# Nokia 5110 Library for Arduino (nokia5110Flex)
This Arduino library allows you to output text and symbols to a Nokia 5110 graphic LCD using either hardware or software SPI

Written by Rylee Isitt

## Features:
* Can use hardware SPI (fast) or software SPI (slow, but allows more flexible wiring)
* International characters for French, Spanish, German, Swedish, Danish, Icelandic, and probably others
	* See the nokiaLCD-glyphs.png file for the full list of pre-defined symbols
* Allows addition of custom 6x8 symbols (and you can change the existing ones, too)
* To create your own symbols, use the charmaker.xlsx spreadsheet tool to calculate the array of bytes

## License:
GNU Lesser General Public License (LGPL) V2.1

**Please see the LICENSE file for details**

## Installation Instructions:
1. Download the "Source code (zip)" for the latest release of the library: https://github.com/risitt/nokia5110Flex/releases
2. (In the Arduino IDE) Sketch > Include Library > Add .ZIP Library > select the downloaded file > Open
3. Include the library in your sketch: **#include &lt;nokia5110Flex.h&gt;**
4. Include the default character set in your sketch: **#include &lt;nokia5110Glyphs.h&gt;**
5. Read the API Documentation, or see the example sketches for information on how to use the library
