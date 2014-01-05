// advertise.ino
// adverise device. the simplest that can be done

#include <SPI.h>
#include "bluecap.h"
#include "dlog.h"

BlueCap ble;

void setup() {
  Serial.begin(9600);
  ble.begin();
}

void loop() {
  ble.doEvents();
}



