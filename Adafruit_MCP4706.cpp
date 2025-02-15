/**************************************************************************/
/*! 
    @file     Adafruit_MCP4706.cpp
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

#include "Adafruit_MCP4706.h"

/**************************************************************************/
/*! 
	@brief  Instantiates a new MCP4706 class
*/
/**************************************************************************/
Adafruit_MCP4706::Adafruit_MCP4706() { }

/**************************************************************************/
/*! 
	@brief  Setups the HW
*/
/**************************************************************************/
void Adafruit_MCP4706::begin(uint8_t addr) {
	_i2caddr = addr;
	Wire.begin();
}
 
/**************************************************************************/
/*! 
	@brief  Sets the output voltage to a fraction of source vref. (Value
		can be 0..255)

	@param[in]  output
		The 8-bit value representing the relationship between
		the DAC's input voltage and its output voltage.
*/
/**************************************************************************/
void Adafruit_MCP4706::setVoltage( uint8_t output) {
	uint8_t twbrback = TWBR;
	TWBR = 12; // 400 khz
	// TWBR = 72; // 100 khz
	Wire.beginTransmission(_i2caddr);
	Wire.write(0);      // First Byte 0
	Wire.write(output); // Second byte: Data bits          (D7.D6.D5.D4.D3.D2.D1.D0)
	Wire.endTransmission();
	TWBR = twbrback;
}