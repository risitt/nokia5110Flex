#include "nokia5110Flex.h"

nokia5110Flex::nokia5110Flex(uint8_t pinSCE, uint8_t pinRESET, uint8_t pinDC, uint8_t pinLED, uint8_t pinMOSI, uint8_t pinSCLK)
    : PINSCE(pinSCE), PINRESET(pinRESET), PINDC(pinDC), PINMOSI(pinMOSI), PINSCLK(pinSCLK), PINLED(pinLED), HARDWARESPI(false)
{
    contrast = DEFAULT_CONTRAST;
}

nokia5110Flex::nokia5110Flex(uint8_t pinSCE, uint8_t pinRESET, uint8_t pinDC, uint8_t pinLED)
    : PINSCE(pinSCE), PINRESET(pinRESET), PINDC(pinDC), PINMOSI(255), PINSCLK(255), PINLED(pinLED), HARDWARESPI(true)
{
    contrast = DEFAULT_CONTRAST;
}

nokia5110Flex::~nokia5110Flex() { }

void nokia5110Flex::begin(void)
{
    // set necessary pins as ouput
    pinMode(PINRESET, OUTPUT);
    pinMode(PINSCE, OUTPUT);
    pinMode(PINLED, OUTPUT);
    pinMode(PINDC, OUTPUT);

    if (HARDWARESPI)
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
        pinMode(PINMOSI, OUTPUT);
        pinMode(PINSCLK, OUTPUT);
    }

    // reset the LCD - this must be done early on, reset occurs on a LOW pulse
    digitalWrite(PINRESET, LOW);
    digitalWrite(PINRESET, HIGH);

    // start with the LED backlight off
    digitalWrite(PINLED, LOW);
    backlight = false;

    // initialize display
    enable();
    setCmdMode(true);
    send(FUNC_SET | FUNC_SET_EXTENDED); // sends uint8_t 00100001 (powered up, horizontal addressing, extended instruction set)
    send(EXTENDED_VOP | contrast); // sets contrast (V_OP)
    send(EXTENDED_BIAS); // sends uint8_t 00010100 (sets bias value)
    send(EXTENDED_TEMP); // sends uint8_t 00000100 (selects temperature coefficient 0)
    send(FUNC_SET); // sends uint8_t 00100000 (powered up, horizontal addressing, basic instruction set)
    send(BASIC_DISPNORM); // sends uint8_t 00001100 (normal display mode)
    setCmdMode(false);
}

void nokia5110Flex::send(uint8_t dataOrCmd)
{
    if (!enabled) enable();
    if (HARDWARESPI)
        SPI.transfer(dataOrCmd);
    else
        shiftOut(PINMOSI, PINSCLK, MSBFIRST, dataOrCmd);
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
    if (HARDWARESPI) SPI.beginTransaction(SPISettings(SPEED_4MHZ, MSBFIRST, SPI_MODE0));
    digitalWrite(PINSCE, LOW); // enable serial interface
    enabled = true;
}

void nokia5110Flex::disable(void)
{
    digitalWrite(PINSCE, HIGH); // disable serial interface
    if (HARDWARESPI) SPI.endTransaction();
    enabled = false;
}

uint8_t nokia5110Flex::setContrast(uint8_t newContrast)
{
    contrast = newContrast & ~EXTENDED_VOP;
    setCmdMode(true);
    send(FUNC_SET | FUNC_SET_EXTENDED); // sends uint8_t 00100001 (powered up, horizontal addressing, extended instruction set)
    send(EXTENDED_VOP | contrast); // sets contrast (V_OP)
    send(FUNC_SET); // sends uint8_t 00100000 (powered up, horizontal addressing, basic instruction set)
    setCmdMode(false);
    return contrast;
}

bool nokia5110Flex::moveCursor(uint8_t x, uint8_t y)
{
    if ((x < XCHARS) && (y < YCHARS))
    {
        setCmdMode(true);
        send(BASIC_SETX | x * CHARWIDTH); // set column
        send(BASIC_SETY | y); // set row
        setCmdMode(false);
        xChar = x;
        yChar = y;
        return true;
    }
    return false;
}

bool nokia5110Flex::writeChar(uint8_t textByte)
{
    bool validPos;
    if ((xChar >= XCHARS) || (textByte == NEWLINEBYTE)) validPos = newLine();
    else validPos = ((xChar < XCHARS) && (yChar < YCHARS));

    if ((textByte != NEWLINEBYTE) && validPos)
    {
        for (int i = 0; i < (CHARWIDTH); i++)
        {
            uint8_t glyphByte = pgm_read_byte(&(GLYPHS[textByte-0x01][i]));
            if (invert) glyphByte = ~glyphByte;
            send(glyphByte); // set pixels
        }
        xChar++;
    }

    return validPos;
}

void nokia5110Flex::write_P(const char *text)
{
    uint8_t textByte;
    while ((textByte = pgm_read_byte(text++)) != 0x00)
        nokia5110Flex::writeChar(textByte);
}

void nokia5110Flex::write_P(const char* const* address)
{
    char* text = (char*)pgm_read_word(address);
    uint8_t textByte;
    while ((textByte = pgm_read_byte(text++)) != 0x00)
        nokia5110Flex::writeChar(textByte);
}

void nokia5110Flex::write(String text)
{
    uint8_t textByte;
    uint8_t strLength = text.length();
    for (uint8_t i=0; i < strLength; i++)
    {
        textByte = text[i];
        nokia5110Flex::writeChar(textByte);
    }
}

void nokia5110Flex::write(const char *text)
{
    uint8_t textByte;
    while ((textByte = (text++)[0]) != 0x00)
        nokia5110Flex::writeChar(textByte);
}

void nokia5110Flex::cls(void)
{
    moveCursor(0,0);
    for (word i=0; i < XADDRS * YADDRS; i++)
        send(0); // clear pixels
}
