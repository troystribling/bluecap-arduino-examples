#ifndef _BOND_PERIPHERAL_H
#define _BOND_PERIPHERAL_H

#import "blue_cap_peripheral.h"

class BondPeripheral : public BlueCapPeripheral {
public:

  BondPeripheral(uint8_t reqn, uint8_t rdyn);
  void loop();

protected:

  bool arePipesAvailable();
};

#endif