#ifndef _HELLO_WORLD_PERIPHERAL_H
#define _HELLO_WORLD_PERIPHERAL_H

#import "blue_cap_peripheral.h"

class HelloWorldPeripheral : public BlueCapPeripheral {
public:

  HelloWorldPeripheral();

protected:

  void onDataReceived(uint8_t characteristic_id, uint8_t* data, uint8_t length);

private:
};

#endif