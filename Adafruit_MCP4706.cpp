/**************************************************************************/
/*! 
    Authors:
    - Original: K.Townsend (Adafruit Industries)
    - Modified for MCP4706 by Pio Baettig
    - Now modifed by Millan kumar for PER HIL 2.0 2025 usage
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
void Adafruit_MCP4706::begin(uint8_t addr, TwoWire &wire) {
    _i2caddr = addr;
    _wire = &wire;
    _wire->begin();
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
void Adafruit_MCP4706::setVoltage(uint8_t output) {
    uint8_t twbrback = TWBR;
    TWBR = 12; // 400 khz
    // TWBR = 72; // 100 khz
    _wire->beginTransmission(_i2caddr);
    _wire->write(MCP4706_CMD_VOLDAC); // First byte: Command (CMD_VOLDAC = 0)
    _wire->write(output);             // Second byte: Data bits (D7.D6.D5.D4.D3.D2.D1.D0)
    _wire->endTransmission();
    TWBR = twbrback;
}


/**************************************************************************/
/*! 
    @brief  Puts the DAC into a low power state using the specified resistor mode

    @param[in]  mode
        Power-down mode, one of:
        - MCP4706_AWAKE
        - MCP4706_PWRDN_1K
        - MCP4706_PWRDN_100K
        - MCP4706_PWRDN_500K
*/
/**************************************************************************/
void Adafruit_MCP4706::setPowerDown(uint8_t mode) {
    uint8_t config = (mode & ~MCP4706_PWRDN_MASK); // ensure only power-down bits are set
    _wire->beginTransmission(_i2caddr);
    _wire->write(config | MCP4706_CMD_VOLCONFIG);  // command with config register
    _wire->endTransmission();
}