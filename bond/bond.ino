// bond.ino
#include <SPI.h>
#include "dlog.h"
#include "blue_cap_peripheral.h"
#include "bond_peripheral.h"

#define REQN_PIN  9
#define RDYN_PIN  8

BondPeripheral bond(REQN_PIN, RDYN_PIN, 0);

void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif
  bond.begin();
}

void loop() {
  bond.loop();
}

