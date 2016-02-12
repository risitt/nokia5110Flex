#include "nokia5110Flex.h"

nokia5110Flex::nokia5110Flex(byte pinSCE, byte pinRESET, byte pinDC, byte pinLED, byte pinMOSI, byte pinSCLK)
    : pinSCE(pinSCE), pinRESET(pinRESET), pinDC(pinDC), pinMOSI(pinMOSI), pinSCLK(pinSCLK), pinLED(pinLED), hardwareSPI(false)
{
    contrast = default_contrast;
}

nokia5110Flex::nokia5110Flex(byte pinSCE, byte pinRESET, byte pinDC, byte pinLED)
    : pinSCE(pinSCE), pinRESET(pinRESET), pinDC(pinDC), pinMOSI(255), pinSCLK(255), pinLED(pinLED), hardwareSPI(true)
{
    contrast = default_contrast;
}

nokia5110Flex::~nokia5110Flex() { }

void nokia5110Flex::begin(void)
{
    // set necessary pins as ouput
    pinMode(pinRESET, OUTPUT);
    pinMode(pinSCE, OUTPUT);
    pinMode(pinLED, OUTPUT);
    pinMode(pinDC, OUTPUT);

    if (hardwareSPI)
    {
        // begin hardware SPI
        // this will set SCK, MOSI, and SS as outputs
        // SCK and MOSI will be pulled low
        // SS will be pulled high
        SPI.begin();
    }
    else
    {
        // set MOSI and SCLK pins for output
        // for software SPI
        pinMode(pinMOSI, OUTPUT);
        pinMode(pinSCLK, OUTPUT);
    }

    // reset the LCD - this must be done early on, reset occurs on a LOW pulse
    digitalWrite(pinRESET, LOW);
    digitalWrite(pinRESET, HIGH);

    // start with the LED backlight off
    digitalWrite(pinLED, LOW);
    backlight = false;

    // initialize display
    enable();
    setCmdMode(true);
    send(extended); // sends byte 00100001 (powered up, horizontal addressing, extended instruction set)
    send(extended_Vop | contrast); // sets contrast (V_OP)
    send(extended_bias); // sends byte 00010100 (sets bias value)
    send(extended_temp); // sends byte 00000100 (selects temperature coefficient 0)
    send(basic); // sends byte 00100000 (powered up, horizontal addressing, basic instruction set)
    send(basic_dispNorm); // sends byte 00001100 (normal display mode)
    setCmdMode(false);
}

void nokia5110Flex::send(byte dataOrCmd)
{
    if (!enabled) enable();
    if (hardwareSPI)
        SPI.transfer(dataOrCmd);
    else
        shiftOut(pinMOSI, pinSCLK, MSBFIRST, dataOrCmd);
}

void nokia5110Flex::enable(void)
{
    // SPI settings for the Nokia LCD:
    // SCE is slave select pin, chip is active when low
    // Speed: 4 MHz
    // Send data by MSBFIRST
    // Data clock is idle when low (Clock Polarity/CPOL = 0)
    // Samples on the rising/positive edge of clock pulses (Clock Phase/CPHA = 0)
    // Use SPI_MODE0
    if (hardwareSPI) SPI.beginTransaction(SPISettings(SPEED_4MHZ, MSBFIRST, SPI_MODE0));
    digitalWrite(pinSCE, LOW); // enable serial interface
    enabled = true;
}

void nokia5110Flex::disable(void)
{
    digitalWrite(pinSCE, HIGH); // disable serial interface
    if (hardwareSPI) SPI.endTransaction();
    enabled = false;
}

byte nokia5110Flex::setContrast(byte newContrast)
{
    newContrast &= ~extended_Vop;
    contrast = newContrast;
    setCmdMode(true);
    send(extended); // sends byte 00100001 (powered up, horizontal addressing, extended instruction set)
    send(extended_Vop | contrast); // sets contrast (V_OP)
    send(basic); // sends byte 00100000 (powered up, horizontal addressing, basic instruction set)
    setCmdMode(false);
    return contrast;
}

bool nokia5110Flex::moveCursor(byte x, byte y)
{
    while (x >= xChars)
    {
        x -= xChars;
        y++;
    }
    if (y < yChars)
    {
        setCmdMode(true);
        send(basic_setX | x * charWidth); // set column
        send(basic_setY | y); // set row
        setCmdMode(false);
        xChar = x;
        yChar = y;
        return true;
    }
    return false;
}

bool nokia5110Flex::writeChar(byte textByte)
{
    bool validPos;
    if ((xChar >= xChars) || (textByte == newLineByte)) validPos = newLine();
    else validPos = ((xChar < xChars) && (yChar < yChars));

    if ((textByte != newLineByte) && validPos)
    {
        for (int i = 0; i < (charWidth); i++)
        {
            byte glyphByte = pgm_read_byte(&(glyphs[textByte-0x01][i]));
            if (invert) glyphByte = ~glyphByte;
            send(glyphByte); // set pixels
        }
        xChar++;
    }

    return validPos;
}

void nokia5110Flex::write_P(const char *text)
{
    byte textByte;
    while ((textByte = pgm_read_byte(text++)) != 0x00)
        nokia5110Flex::writeChar(textByte);
}

void nokia5110Flex::write_P(const char* const* address)
{
    char* text = (char*)pgm_read_word(address);
    byte textByte;
    while ((textByte = pgm_read_byte(text++)) != 0x00)
        nokia5110Flex::writeChar(textByte);
}

void nokia5110Flex::write(String text)
{
    byte textByte;
    byte strLength = text.length();
    for (byte i=0; i < strLength; i++)
    {
        textByte = text[i];
        nokia5110Flex::writeChar(textByte);
    }
}

void nokia5110Flex::write(const char *text)
{
    byte textByte;
    while ((textByte = (text++)[0]) != 0x00)
        nokia5110Flex::writeChar(textByte);
}

void nokia5110Flex::cls(void)
{
    moveCursor(0,0);
    for (word i=0; i < xAddrs * yAddrs; i++)
        send(0); // clear pixels
}
