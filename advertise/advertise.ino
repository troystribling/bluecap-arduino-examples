// advertise.ino
// adverise device. the least that can be done
#include <SPI.h>
#include "bluecap.h"
#include "dlog.h"

void setup() {
  Serial.begin(9600);
  bcBegin();
}

void loop() {
  bcDoEvents();
}



