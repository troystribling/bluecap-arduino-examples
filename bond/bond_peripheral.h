#ifndef _BOND_PERIPHERAL_H
#define _BOND_PERIPHERAL_H

#import "blue_cap_peripheral.h"

class BondPeripheral : public BlueCapPeripheral {
public:

  BondPeripheral(uint8_t _reqn, uint8_t _rdyn, uint16_t _eepromOffset);
  void loop();

protected:

  void didReceiveCommandResponse(uint8_t commandId, uint8_t* data, uint8_t size);
  bool doTimingChange();
  void didBond();

};

#endif