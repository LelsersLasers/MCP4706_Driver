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

// Power Down Mode definitions
#define MCP4706_PWRDN_MASK     0xF9
#define MCP4706_AWAKE          0x00
#define MCP4706_PWRDN_1K       0x02
#define MCP4706_PWRDN_100K     0x04
#define MCP4706_PWRDN_500K     0x06

// Command definitioins
#define MCP4706_CMD_MASK       0x1F
#define MCP4706_CMD_VOLDAC     0x00
#define MCP4706_CMD_VOLALL     0x40
#define MCP4706_CMD_VOLCONFIG  0x80
#define MCP4706_CMD_ALL        0x60

class Adafruit_MCP4706{
    public:
        Adafruit_MCP4706();
        void begin(uint8_t addr, TwoWire &wire = Wire); 
        void setVoltage(uint8_t output);
        void setPowerDown(uint8_t mode);

    private:
        uint8_t _i2caddr;
        TwoWire *_wire;
};
