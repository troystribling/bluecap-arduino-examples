// advertise.ino
// adverise device. the simplest program that does something

#include <SPI.h>
#include "bluecap.h"
#include "dlog.h"

BlueCap ble("BlueCap");

void setup() {
  Serial.begin(9600);
  ble.begin();
}

void loop() {
  ble.doEvents();
}



