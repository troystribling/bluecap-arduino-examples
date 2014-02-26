#ifndef _BROADCAST_PERIPHERAL_H
#define _BROADCAST_PERIPHERAL_H

#include "blue_cap_peripheral.h"

class BroadcastPeripheral : public BlueCapBroadcastingPeripheral {

public:

  BroadcastPeripheral(uint8_t _reqnPin, uint8_t _rdynPin);

  void begin();
  void loop();

protected:

  void didReceiveData(uint8_t characteristicId, uint8_t* data, uint8_t size);
  void didReceiveCommandResponse(uint8_t commandId, uint8_t* data, uint8_t size);
  void didDisconnect();
  void didConnect();
  void didStartAdvertising();
  void didReceiveError(uint8_t pipe, uint8_t errorCode);
  void didReceiveStatusChange();
  void didBond();

  bool doTimingChange();

};

#endif