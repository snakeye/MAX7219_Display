#pragma once

#include "Driver.h"
#include "MAX7219.h"

#define TEXT_ALIGN_LEFT 0      // Text is aligned to left side of the display
#define TEXT_ALIGN_LEFT_END 1  // Beginning of text is just outside the right end of the display
#define TEXT_ALIGN_RIGHT 2     // End of text is aligned to the right of the display
#define TEXT_ALIGN_RIGHT_END 3 // End of text is just outside the left side of the display
#define TEXT_ALIGN_CENTER 4    // center

namespace LedMatrixDisplay
{
namespace MAX7219
{
namespace Arduino
{

class MAX7219_SPI : public Driver
{
public:
  unsigned int pinCS;

public:
  void init(const unsigned int _driverCount);
  void send(const unsigned char reg, const unsigned char value);
  void send(const unsigned int matrix, const unsigned char reg, const unsigned char value);
  void send(const unsigned char *reg, const unsigned char *values);
};

template <class LedMatrixArray>
class LedMatrixDisplayColumnAnodeY : public LedMatrixDisplayColumnAnode<LedMatrixArray, MAX7219_SPI>
{
public:
};

template <class LedMatrixArray>
class LedMatrixDisplayColumnCathodeY : public LedMatrixDisplayColumnCathode<LedMatrixArray, MAX7219_SPI>
{
public:
};

} // namespace Arduino
} // namespace MAX7219
} // namespace LedMatrixDisplay