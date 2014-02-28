#ifndef _HELLO_WORLD_PERIPHERAL_H
#define _HELLO_WORLD_PERIPHERAL_H

#import "blue_cap_peripheral.h"

class HelloWorldPeripheral : public BlueCapPeripheral {

public:

  HelloWorldPeripheral(uint8_t reqn, uint8_t rdyn);
  void loop();
  void begin();

protected:

  void didReceiveData(uint8_t characteristic_id, uint8_t* data, uint8_t size);
  void didReceiveCommandResponse(uint8_t commandId, uint8_t* data, uint8_t size);
  void didReceiveError(uint8_t pipe, uint8_t errorCode);
  void didStartAdvertising();
  void didConnect();
  bool doTimingChange();

private:

  void setUpdatePeriod(uint8_t* data, uint8_t size);
  void setGreeting();
  void setBatteryLevel(uint8_t* data, uint8_t size);
  void setTemperature(uint8_t* data, uint8_t size);
  void setBLEAddress(uint8_t* data, uint8_t size);
  void writeParams();
  void readParams();

private:

  float  deviceBatteryLevelInitial;

};

#endif
