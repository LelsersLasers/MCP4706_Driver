/**************************************************************************/
/*!
@file trianglewave.pde
@author Adafruit Industries
@license BSD (see license.txt)

Modified for MCP4706 by Pio Baettig

This example will generate a triangle wave with the MCP4706 DAC.

This is an example sketch for the MCP4706

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!
*/
/**************************************************************************/
#include <Wire.h>
#include <Adafruit_MCP4706.h>

Adafruit_MCP4706 dac;

void setup(void) {
  // For MCP4706 the address is 0x60 (different types, verify)
  dac.begin(0x60);
  }

void loop(void) {
  uint8_t counter;
  for (counter = 0; counter < 255; counter++)
  {
    dac.setVoltage(counter);
  }
  for (counter = 255; counter > 0; counter--)
  {
    dac.setVoltage(counter);
  }
}
