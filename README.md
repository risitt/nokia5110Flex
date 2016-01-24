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
1. Download or clone the latest release
2. Extract the archive contents if you downloaded the .zip
3. Copy or move the folder "nokia5110Flex" to your Ardunio library folder
	* On a Windows PC, this is likely to be C:\Program Files (x86)\Arduino\libraries
	* On Linux, this is likely to be /home/<username>/Sketchbook/libraries or /home/<username>/Arduino/libraries
5. Restart the Arduino IDE if it was running
6. Include the library in your sketch: **#include &lt;nokia5110Flex.h&gt;**
7. Read the API Documentation, or see the example sketches for information on how to use the library
