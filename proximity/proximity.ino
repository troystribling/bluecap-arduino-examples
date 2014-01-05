// proximity.ino
#include <SPI.h>
#include "bluecap.h"

void setup() {
  Serial.begin(9600);
  bcBegin();
}

void loop() {
  bcDoEvents();
}

