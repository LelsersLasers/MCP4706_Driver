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

class Adafruit_MCP4706{
    public:
        Adafruit_MCP4706();
        void begin(uint8_t addr, TwoWire &wire = Wire); 
        void setVoltage(uint8_t output);

    private:
        uint8_t _i2caddr;
        TwoWire *_wire;
};
