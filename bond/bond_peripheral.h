#ifndef _BOND_PERIPHERAL_H
#define _BOND_PERIPHERAL_H

#import "blue_cap_peripheral.h"

class BondPeripheral : public BlueCapPeripheral {
public:

  BondPeripheral(uint8_t _reqn, uint8_t _rdyn, uint16_t _eepromOffset);
  void loop();

protected:

  bool doTimingChange();
};

#endif