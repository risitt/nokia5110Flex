#ifndef nokia5110Glyphs_H
#define nokia5110Glyphs_H

#include <Arduino.h>
#include <avr/pgmspace.h>

/*
  This array stores the pixels for the characters
  usable by the library.

  It is stored in flash memory, so does not use
  up the Arduino's SRAM.

  Each character is 6x8 pixels
*/

const byte nokia5110Flex::GLYPHS[][CHARWIDTH] PROGMEM =
{
    {0x00, 0x7F, 0x41, 0x5D, 0x5D, 0x41} // 01 battery indicator / progress bar, left segment, with mark
    ,{0x5D, 0x5D, 0x41, 0x5D, 0x5D, 0x41} // 02 battery indicator / progress bar, middle segment, with two marks
    ,{0x5D, 0x5D, 0x41, 0x7F, 0x1C, 0x00} // 03 battery indicator, right segment, with mark
    ,{0x5D, 0x5D, 0x41, 0x7F, 0x00, 0x00} // 04 progress bar, right segment, with mark
    ,{0x5D, 0x5D, 0x41, 0x41, 0x41, 0x41} // 05 battery indicator / progress bar, middle segment, with one mark
    ,{0x00, 0x7F, 0x41, 0x41, 0x41, 0x41} // 06 battery indicator / progress bar, left segment, no marks
    ,{0x41, 0x41, 0x41, 0x41, 0x41, 0x41} // 07 battery indicator / progress bar, middle segment, no marks
    ,{0x41, 0x41, 0x41, 0x7F, 0x1C, 0x00} // 08 battery indicator, right segment, no marks
    ,{0x41, 0x41, 0x41, 0x7F, 0x00, 0x00} // 09 progress bar, right segment, no marks
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // 0A RESERVED FOR NEWLINE
    ,{0x0E, 0x01, 0x74, 0x01, 0x0E, 0x00} // 0B wireless indicator
    ,{0x30, 0x48, 0x4D, 0x33, 0x07, 0x00} // 0C male
    ,{0x26, 0x29, 0x79, 0x29, 0x26, 0x00} // 0D female
    ,{0x60, 0x7F, 0x05, 0x65, 0x7F, 0x00} // 0E musical note
    ,{0x2A, 0x1C, 0x77, 0x1C, 0x2A, 0x00} // 0F solar symbol
    ,{0x08, 0x08, 0x3E, 0x1C, 0x08, 0x00} // 10 right arrow with tail
    ,{0x08, 0x1C, 0x3E, 0x08, 0x08, 0x00} // 11 left arrow with tail
    ,{0x04, 0x06, 0x7F, 0x06, 0x04, 0x00} // 12 up arrow with tail
    ,{0x10, 0x30, 0x7F, 0x30, 0x10, 0x00} // 13 down arrow with tail
    ,{0x14, 0x36, 0x7F, 0x36, 0x14, 0x00} // 14 up + down arror with joined tails
    ,{0x00, 0x3E, 0x1C, 0x08, 0x00, 0x00} // 15 right arrow
    ,{0x00, 0x08, 0x1C, 0x3E, 0x00, 0x00} // 16 left arrow
    ,{0x20, 0x30, 0x38, 0x30, 0x20, 0x00} // 17 up arrow
    ,{0x08, 0x18, 0x38, 0x18, 0x08, 0x00} // 18 down arrow
    ,{0x3E, 0x1C, 0x08, 0x00, 0x3E, 0x00} // 19 fast forward
    ,{0x3E, 0x00, 0x08, 0x1C, 0x3E, 0x00} // 1A rewind
    ,{0x3E, 0x3E, 0x00, 0x3E, 0x3E, 0x00} // 1B pause
    ,{0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x00} // 1C stop
    ,{0x70, 0x5F, 0x75, 0x00, 0x00, 0x00} // 1D key
    ,{0x18, 0x24, 0x24, 0x18, 0x00, 0x00} // 1E bullet, not selected
    ,{0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00} // 1F bullet, selected
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // 20 space
    ,{0x00, 0x00, 0x6F, 0x00, 0x00, 0x00} // 21 !
    ,{0x00, 0x07, 0x00, 0x07, 0x00, 0x00} // 22 "
    ,{0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00} // 23 #
    ,{0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00} // 24 $
    ,{0x23, 0x13, 0x08, 0x64, 0x62, 0x00} // 25 %
    ,{0x36, 0x49, 0x56, 0x20, 0x50, 0x00} // 26 &
    ,{0x00, 0x00, 0x07, 0x00, 0x00, 0x00} // 27 '
    ,{0x00, 0x1C, 0x22, 0x41, 0x00, 0x00} // 28 (
    ,{0x00, 0x41, 0x22, 0x1C, 0x00, 0x00} // 29 )
    ,{0x14, 0x08, 0x3E, 0x08, 0x14, 0x00} // 2A *
    ,{0x08, 0x08, 0x3E, 0x08, 0x08, 0x00} // 2B +
    ,{0x00, 0x50, 0x30, 0x00, 0x00, 0x00} // 2C ,
    ,{0x08, 0x08, 0x08, 0x08, 0x08, 0x00} // 2D -
    ,{0x00, 0x60, 0x60, 0x00, 0x00, 0x00} // 2E .
    ,{0x20, 0x10, 0x08, 0x04, 0x02, 0x00} // 2F /
    ,{0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00} // 30 0
    ,{0x00, 0x42, 0x7F, 0x40, 0x00, 0x00} // 31 1
    ,{0x42, 0x61, 0x51, 0x49, 0x46, 0x00} // 32 2
    ,{0x21, 0x41, 0x45, 0x4B, 0x31, 0x00} // 33 3
    ,{0x18, 0x14, 0x12, 0x7F, 0x10, 0x00} // 34 4
    ,{0x27, 0x45, 0x45, 0x45, 0x39, 0x00} // 35 5
    ,{0x3C, 0x4A, 0x49, 0x49, 0x30, 0x00} // 36 6
    ,{0x01, 0x71, 0x09, 0x05, 0x03, 0x00} // 37 7
    ,{0x36, 0x49, 0x49, 0x49, 0x36, 0x00} // 38 8
    ,{0x06, 0x49, 0x49, 0x29, 0x1E, 0x00} // 39 9
    ,{0x00, 0x36, 0x36, 0x00, 0x00, 0x00} // 3A :
    ,{0x00, 0x56, 0x36, 0x00, 0x00, 0x00} // 3B ;
    ,{0x08, 0x14, 0x22, 0x41, 0x00, 0x00} // 3C <
    ,{0x14, 0x14, 0x14, 0x14, 0x14, 0x00} // 3D =
    ,{0x00, 0x41, 0x22, 0x14, 0x08, 0x00} // 3E >
    ,{0x02, 0x01, 0x51, 0x09, 0x06, 0x00} // 3F ?
    ,{0x3E, 0x41, 0x5D, 0x49, 0x4E, 0x00} // 40 @
    ,{0x7E, 0x09, 0x09, 0x09, 0x7E, 0x00} // 41 A
    ,{0x7F, 0x49, 0x49, 0x49, 0x36, 0x00} // 42 B
    ,{0x3E, 0x41, 0x41, 0x41, 0x22, 0x00} // 43 C
    ,{0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00} // 44 D
    ,{0x7F, 0x49, 0x49, 0x49, 0x41, 0x00} // 45 E
    ,{0x7F, 0x09, 0x09, 0x09, 0x01, 0x00} // 46 F
    ,{0x3E, 0x41, 0x49, 0x49, 0x7A, 0x00} // 47 G
    ,{0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00} // 48 H
    ,{0x00, 0x41, 0x7F, 0x41, 0x00, 0x00} // 49 I
    ,{0x20, 0x40, 0x41, 0x3F, 0x01, 0x00} // 4A J
    ,{0x7F, 0x08, 0x14, 0x22, 0x41, 0x00} // 4B K
    ,{0x7F, 0x40, 0x40, 0x40, 0x40, 0x00} // 4C L
    ,{0x7F, 0x02, 0x0C, 0x02, 0x7F, 0x00} // 4D M
    ,{0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00} // 4E N
    ,{0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00} // 4F O
    ,{0x7F, 0x09, 0x09, 0x09, 0x06, 0x00} // 50 P
    ,{0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00} // 51 Q
    ,{0x7F, 0x09, 0x19, 0x29, 0x46, 0x00} // 52 R
    ,{0x46, 0x49, 0x49, 0x49, 0x31, 0x00} // 53 S
    ,{0x01, 0x01, 0x7F, 0x01, 0x01, 0x00} // 54 T
    ,{0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00} // 55 U
    ,{0x0F, 0x30, 0x40, 0x30, 0x0F, 0x00} // 56 V
    ,{0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00} // 57 W
    ,{0x63, 0x14, 0x08, 0x14, 0x63, 0x00} // 58 X
    ,{0x07, 0x08, 0x70, 0x08, 0x07, 0x00} // 59 Y
    ,{0x61, 0x51, 0x49, 0x45, 0x43, 0x00} // 5A Z
    ,{0x00, 0x7F, 0x41, 0x00, 0x00, 0x00} // 5B [
    ,{0x02, 0x04, 0x08, 0x10, 0x20, 0x00} // 5C backslash
    ,{0x00, 0x41, 0x7F, 0x00, 0x00, 0x00} // 5D ]
    ,{0x04, 0x02, 0x01, 0x02, 0x04, 0x00} // 5E ^
    ,{0x40, 0x40, 0x40, 0x40, 0x40, 0x00} // 5F _
    ,{0x00, 0x00, 0x03, 0x04, 0x00, 0x00} // 60 `
    ,{0x20, 0x54, 0x54, 0x54, 0x78, 0x00} // 61 a
    ,{0x7F, 0x48, 0x44, 0x44, 0x38, 0x00} // 62 b
    ,{0x38, 0x44, 0x44, 0x44, 0x20, 0x00} // 63 c
    ,{0x38, 0x44, 0x44, 0x48, 0x7F, 0x00} // 64 d
    ,{0x38, 0x54, 0x54, 0x54, 0x18, 0x00} // 65 e
    ,{0x08, 0x7E, 0x09, 0x01, 0x02, 0x00} // 66 f
    ,{0x0C, 0x52, 0x52, 0x52, 0x3E, 0x00} // 67 g
    ,{0x7F, 0x08, 0x04, 0x04, 0x78, 0x00} // 68 h
    ,{0x00, 0x44, 0x7D, 0x40, 0x00, 0x00} // 69 i
    ,{0x00, 0x20, 0x40, 0x44, 0x3D, 0x00} // 6A j
    ,{0x00, 0x7F, 0x10, 0x28, 0x44, 0x00} // 6B k
    ,{0x00, 0x41, 0x7F, 0x40, 0x00, 0x00} // 6C l
    ,{0x7C, 0x04, 0x18, 0x04, 0x78, 0x00} // 6D m
    ,{0x7C, 0x08, 0x04, 0x04, 0x78, 0x00} // 6E n
    ,{0x38, 0x44, 0x44, 0x44, 0x38, 0x00} // 6F o
    ,{0x7C, 0x14, 0x14, 0x14, 0x08, 0x00} // 70 p
    ,{0x08, 0x14, 0x14, 0x18, 0x7C, 0x00} // 71 q
    ,{0x7C, 0x08, 0x04, 0x04, 0x08, 0x00} // 72 r
    ,{0x48, 0x54, 0x54, 0x54, 0x20, 0x00} // 73 s
    ,{0x04, 0x3F, 0x44, 0x40, 0x20, 0x00} // 74 t
    ,{0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00} // 75 u
    ,{0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00} // 76 v
    ,{0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00} // 77 w
    ,{0x44, 0x28, 0x10, 0x28, 0x44, 0x00} // 78 x
    ,{0x0C, 0x50, 0x50, 0x50, 0x3C, 0x00} // 79 y
    ,{0x44, 0x64, 0x54, 0x4C, 0x44, 0x00} // 7A z
    ,{0x00, 0x08, 0x36, 0x41, 0x41, 0x00} // 7B {
    ,{0x00, 0x00, 0x7F, 0x00, 0x00, 0x00} // 7C |
    ,{0x41, 0x41, 0x36, 0x08, 0x00, 0x00} // 7D }
    ,{0x04, 0x02, 0x04, 0x08, 0x04, 0x00} // 7E ~
    ,{0x40, 0x00, 0x40, 0x00, 0x40, 0x00} // 7F ellipses
    ,{0x78, 0x14, 0x16, 0x15, 0x78, 0x00} // 80 A acute
    ,{0x78, 0x16, 0x15, 0x16, 0x78, 0x00} // 81 A circumflex
    ,{0x78, 0x15, 0x16, 0x14, 0x78, 0x00} // 82 A grave
    ,{0x78, 0x15, 0x14, 0x15, 0x78, 0x00} // 83 A umlaut
    ,{0x78, 0x16, 0x15, 0x16, 0x79, 0x00} // 84 A tilde
    ,{0x70, 0x2A, 0x2D, 0x2A, 0x70, 0x00} // 85 A ring
    ,{0x20, 0x54, 0x56, 0x55, 0x78, 0x00} // 86 a acute
    ,{0x20, 0x56, 0x55, 0x56, 0x78, 0x00} // 87 a circumflex
    ,{0x20, 0x55, 0x56, 0x54, 0x78, 0x00} // 88 a grave
    ,{0x20, 0x55, 0x54, 0x55, 0x78, 0x00} // 89 a umlaut
    ,{0x20, 0x56, 0x55, 0x56, 0x79, 0x00} // 8A a tilde
    ,{0x20, 0x57, 0x55, 0x57, 0x78, 0x00} // 8B a ring
    ,{0x7C, 0x54, 0x56, 0x55, 0x44, 0x00} // 8C E acute
    ,{0x7C, 0x56, 0x55, 0x56, 0x44, 0x00} // 8D E circumflex
    ,{0x7C, 0x55, 0x56, 0x54, 0x44, 0x00} // 8E E grave
    ,{0x7C, 0x55, 0x54, 0x55, 0x44, 0x00} // 8F E umlaut
    ,{0x38, 0x54, 0x56, 0x55, 0x18, 0x00} // 90 e acute
    ,{0x38, 0x56, 0x55, 0x56, 0x18, 0x00} // 91 e circumflex
    ,{0x38, 0x55, 0x56, 0x54, 0x18, 0x00} // 92 e grave
    ,{0x38, 0x55, 0x54, 0x55, 0x18, 0x00} // 93 e umlaut
    ,{0x00, 0x48, 0x7A, 0x49, 0x00, 0x00} // 94 I acute
    ,{0x00, 0x4A, 0x79, 0x4A, 0x00, 0x00} // 95 I circumflex
    ,{0x00, 0x49, 0x7A, 0x48, 0x00, 0x00} // 96 I grave
    ,{0x00, 0x49, 0x78, 0x49, 0x00, 0x00} // 97 I umlaut
    ,{0x00, 0x48, 0x7A, 0x41, 0x00, 0x00} // 98 i acute
    ,{0x00, 0x4A, 0x79, 0x42, 0x00, 0x00} // 99 i circumflex
    ,{0x00, 0x49, 0x7A, 0x40, 0x00, 0x00} // 9A i grave
    ,{0x00, 0x49, 0x78, 0x41, 0x00, 0x00} // 9B i umlaut
    ,{0x38, 0x44, 0x46, 0x45, 0x38, 0x00} // 9C O acute
    ,{0x38, 0x46, 0x45, 0x46, 0x38, 0x00} // 9D O circumflex
    ,{0x38, 0x45, 0x46, 0x44, 0x38, 0x00} // 9E O grave
    ,{0x38, 0x45, 0x44, 0x45, 0x38, 0x00} // 9F O umlaut
    ,{0x38, 0x46, 0x45, 0x46, 0x39, 0x00} // A0 O tilde
    ,{0x30, 0x48, 0x4A, 0x49, 0x30, 0x00} // A1 o acute
    ,{0x30, 0x4A, 0x49, 0x4A, 0x30, 0x00} // A2 o circumflex
    ,{0x30, 0x49, 0x4A, 0x48, 0x30, 0x00} // A3 o grave
    ,{0x30, 0x49, 0x48, 0x49, 0x30, 0x00} // A4 o umlaut
    ,{0x30, 0x4A, 0x49, 0x4A, 0x31, 0x00} // A5 o tilde
    ,{0x3C, 0x40, 0x42, 0x41, 0x3C, 0x00} // A6 U acute
    ,{0x38, 0x42, 0x41, 0x42, 0x38, 0x00} // A7 U circumflex
    ,{0x3C, 0x41, 0x42, 0x40, 0x3C, 0x00} // A8 U grave
    ,{0x3C, 0x41, 0x40, 0x41, 0x3C, 0x00} // A9 U umlaut
    ,{0x38, 0x40, 0x42, 0x21, 0x78, 0x00} // AA u acute
    ,{0x38, 0x42, 0x41, 0x22, 0x78, 0x00} // AB u circumflex
    ,{0x38, 0x41, 0x42, 0x20, 0x78, 0x00} // AC u grave
    ,{0x38, 0x41, 0x40, 0x21, 0x78, 0x00} // AD u umlaut
    ,{0x0C, 0x10, 0x62, 0x11, 0x0C, 0x00} // AE Y acute
    ,{0x0C, 0x50, 0x52, 0x51, 0x3C, 0x00} // AF y acute
    ,{0x0C, 0x51, 0x50, 0x51, 0x3C, 0x00} // B0 y umlaut
    ,{0x4E, 0x51, 0x71, 0x11, 0x0A, 0x00} // B1 C cedilla
    ,{0x58, 0x64, 0x64, 0x24, 0x10, 0x00} // B2 c cedilla
    ,{0x7C, 0x0A, 0x11, 0x22, 0x7D, 0x00} // B3 N tilde
    ,{0x78, 0x12, 0x09, 0x0A, 0x71, 0x00} // B4 n tilde
    ,{0x7C, 0x0A, 0x09, 0x7F, 0x49, 0x00} // B5 AE (ash) uppercase
    ,{0x20, 0x54, 0x7C, 0x54, 0x58, 0x00} // B6 ae (ash) lowercase
    ,{0x7E, 0x01, 0x49, 0x59, 0x36, 0x00} // B7 eszett
    ,{0x08, 0x7F, 0x49, 0x41, 0x3E, 0x00} // B8 eth uppercase
    ,{0x00, 0x70, 0x55, 0x52, 0x7D, 0x00} // B9 eth lowercase
    ,{0x3E, 0x61, 0x5D, 0x43, 0x3E, 0x00} // BA slashed O
    ,{0x38, 0x64, 0x54, 0x4C, 0x38, 0x00} // BB shashed o
    ,{0x7F, 0x12, 0x12, 0x12, 0x0C, 0x00} // BC thorn uppercase
    ,{0x7F, 0x24, 0x24, 0x18, 0x00, 0x00} // BD thorn lowercase
    ,{0x30, 0x48, 0x45, 0x40, 0x20, 0x00} // BE upside-down question mark
    ,{0x00, 0x00, 0x7B, 0x00, 0x00, 0x00} // BF upside-down exclamation mark
    ,{0x08, 0x14, 0x2A, 0x14, 0x22, 0x00} // C0 left double guillemet
    ,{0x22, 0x14, 0x2A, 0x14, 0x08, 0x00} // C1 right double guillemet
    ,{0x26, 0x29, 0x29, 0x2F, 0x28, 0x00} // C2 ordinal a
    ,{0x26, 0x29, 0x29, 0x26, 0x00, 0x00} // C3 ordinal o
    ,{0x18, 0x24, 0x66, 0x24, 0x00, 0x00} // C4 cent symbol
    ,{0x48, 0x7E, 0x49, 0x4A, 0x60, 0x00} // C5 pound symbol
    ,{0x14, 0x3E, 0x55, 0x41, 0x22, 0x00} // C6 euro symbol
    ,{0x2B, 0x2C, 0x78, 0x2C, 0x2B, 0x00} // C7 yuan/yen symbol
    ,{0x7C, 0x20, 0x20, 0x1C, 0x20, 0x00} // C8 micro (lowercase mu)
    ,{0x44, 0x7C, 0x04, 0x7C, 0x44, 0x00} // C9 pi lowercase
    ,{0x4E, 0x71, 0x01, 0x71, 0x4E, 0x00} // CA omega uppercase
    ,{0x3F, 0x21, 0x2D, 0x2D, 0x3F, 0x00} // CB copyright symbol
    ,{0x3F, 0x21, 0x35, 0x29, 0x3F, 0x00} // CC registered trademark symbol
    ,{0x00, 0x00, 0x01, 0x1F, 0x01, 0x00} // CD trademark left side glyph
    ,{0x00, 0x00, 0x17, 0x15, 0x1D, 0x00} // CE service mark left side glyph
    ,{0x1F, 0x01, 0x1F, 0x01, 0x1F, 0x00} // CF trademark/service mark right side glyph
    ,{0x00, 0x07, 0x05, 0x07, 0x00, 0x00} // D0 degree symbol
    ,{0x00, 0x48, 0x5C, 0x48, 0x00, 0x00} // D1 +/-
    ,{0x51, 0x4A, 0x4A, 0x44, 0x44, 0x00} // D2 >=
    ,{0x44, 0x44, 0x4A, 0x4A, 0x51, 0x00} // D3 <=
    ,{0x00, 0x55, 0x00, 0xAA, 0x00, 0x55} // D4 dithered pattern, light
    ,{0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA} // D5 dithered pattern, medium
    ,{0xFF, 0xAA, 0xFF, 0x55, 0xFF, 0xAA} // D6 dithered pattern, dark
    ,{0x00, 0x00, 0xFF, 0x00, 0x00, 0x00} // D7 vertical line segment
    ,{0x08, 0x08, 0x08, 0x08, 0x08, 0x08} // D8 horizontal line segment
    ,{0x00, 0x00, 0xF8, 0x08, 0x08, 0x08} // D9 top left corner segment
    ,{0x08, 0x08, 0xF8, 0x08, 0x08, 0x08} // DA horizontal line segment with downwards extension
    ,{0x08, 0x08, 0xF8, 0x00, 0x00, 0x00} // DB top right corner segment
    ,{0x00, 0x00, 0xFF, 0x08, 0x08, 0x08} // DC vertical line segment with right extension
    ,{0x08, 0x08, 0xFF, 0x08, 0x08, 0x08} // DD four-way intersecting segment
    ,{0x08, 0x08, 0xFF, 0x00, 0x00, 0x00} // DE vertical line segment with left extension
    ,{0x00, 0x00, 0x0F, 0x08, 0x08, 0x08} // DF bottom left corner segment
    ,{0x08, 0x08, 0x0F, 0x08, 0x08, 0x08} // E0 horizontal line segment with upwards extension
    ,{0x08, 0x08, 0x0F, 0x00, 0x00, 0x00} // E1 bottom right corner segment
    ,{0x00, 0x12, 0x1F, 0x10, 0x00, 0x00} // E2 superscript 1
    ,{0x00, 0x1D, 0x15, 0x17, 0x00, 0x00} // E3 superscript 2
    ,{0x00, 0x15, 0x15, 0x1F, 0x00, 0x00} // E4 superscript 3
    ,{0x00, 0x07, 0x04, 0x1F, 0x00, 0x00} // E5 superscript 4
    ,{0x00, 0x17, 0x15, 0x1D, 0x00, 0x00} // E6 superscript 5
    ,{0x00, 0x1F, 0x14, 0x1C, 0x00, 0x00} // E7 superscript 6
    ,{0x00, 0x01, 0x01, 0x1F, 0x00, 0x00} // E8 superscript 7
    ,{0x00, 0x1F, 0x15, 0x1F, 0x00, 0x00} // E9 superscript 8
    ,{0x00, 0x07, 0x05, 0x1F, 0x00, 0x00} // EA superscript 9
    ,{0x00, 0x1F, 0x11, 0x1F, 0x00, 0x00} // EB superscript 0
    ,{0x04, 0x06, 0xF7, 0x06, 0x04, 0x00} // EC vertical scrollbar up arrow
    ,{0x20, 0x60, 0xEF, 0x60, 0x20, 0x00} // ED vertical scrollbar down arrow
    ,{0x03, 0x03, 0xFF, 0x03, 0x03, 0x00} // EE vertical scrollbar indicator, upper position
    ,{0x18, 0x18, 0xFF, 0x18, 0x18, 0x00} // EF vertical scrollbar indicator, mid position
    ,{0xC0, 0xC0, 0xFF, 0xC0, 0xC0, 0x00} // F0 vertical scrollbar indicator, lower position
    ,{0x08, 0x1C, 0x3E, 0x00, 0x08, 0x08} // F1 horizontal scrollbar left arrow
    ,{0x08, 0x08, 0x00, 0x3E, 0x1C, 0x08} // F2 horizontal scrollbar right arrow
    ,{0x3E, 0x3E, 0x08, 0x08, 0x08, 0x08} // F3 horizontal scrollbar indicator, left position
    ,{0x08, 0x08, 0x3E, 0x3E, 0x08, 0x08} // F4 horizontal scrollbar indicator, mid position
    ,{0x08, 0x08, 0x08, 0x08, 0x3E, 0x3E} // F5 horizontal scrollbar indicator, right position
    ,{0x3C, 0x24, 0x24, 0x3C, 0x00, 0x00} // F6 checkbox, not selected
    ,{0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00} // F7 checkbox, selected
    ,{0x7F, 0x00, 0x00, 0x00, 0x7F, 0x00} // F8 double bar
    ,{0x63, 0x75, 0x79, 0x75, 0x63, 0x00} // F9 hourglass
    ,{0x08, 0x08, 0x2A, 0x08, 0x08, 0x00} // FA division symbol
    ,{0x63, 0x55, 0x49, 0x41, 0x41, 0x00} // FB summation symbol
    ,{0x60, 0x40, 0x7F, 0x01, 0x03, 0x00} // FC integration symbol (single-line)
    ,{0x00, 0x00, 0xFF, 0x01, 0x03, 0x00} // FD integration symbol top (multi-line)
    ,{0x60, 0x40, 0x7F, 0x00, 0x00, 0x00} // FE integration symbol bottom (multi-line)
    ,{0x70, 0x4C, 0x43, 0x4C, 0x70, 0x00} // FF delta
};

#endif