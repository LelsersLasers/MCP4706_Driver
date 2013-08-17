/**************************************************************************/
/*! 
    @file     Adafruit_MCP4706.h
    @author   K.Townsend (Adafruit Industries)
	@license  BSD (see license.txt)
	
        Modified for MCP4706 by Pio Baettig

	I2C Driver for Microchip's MCP4706 I2C DAC

	This is a library for the MCP4706 8-bit DAC modified from
        Adafruit MCP4725 library
	----> https://www.adafruit.com/products/???
		
	Adafruit invests time and resources providing this open source code, 
	please support Adafruit and open-source hardware by purchasing 
	products from Adafruit!

	@section  HISTORY

    v1.0 - First release
*/
/**************************************************************************/

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

class Adafruit_MCP4706{
 public:
  Adafruit_MCP4706();
  void begin(uint8_t a);  
  void setVoltage( uint8_t output);

 private:
  uint8_t _i2caddr;
};
