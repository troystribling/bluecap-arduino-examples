// bond.ino
#include <SPI.h>
#include <EEPROM.h>
#include "dlog.h"
#include "blue_cap_peripheral.h"
#include "bond_peripheral.h"

#define REQN_PIN      9
#define RDYN_PIN      8
#define EEPROM_OFFSET 0
#define RESET_PIN     6
#define ADD_BOND_PIN  5
#define MAX_BONDS     2

BondPeripheral bond(REQN_PIN, RDYN_PIN, EEPROM_OFFSET, MAX_BONDS);

void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif

  pinMode(RESET_PIN, INPUT);
  pinMode(ADD_BOND_PIN, INPUT);
  DLOG(F("To delete the bond stored in EEPROM, connect pin 6 to 5v and reset."));
  DLOG(F("To add a bond connect pin 5 to 5v."));
  if (digitalRead(RESET_PIN) == HIGH) {
    DLOG(F("Clearing EEPROM bond"));
    bond.clearBondData();
    DLOG(F("Remove wire and reset"));
    while(1){delay(1000);};
  }
  bond.begin();
}

void loop() {
  bond.loop();
  if (digitalRead(ADD_BOND_PIN) == HIGH) {
    bond.addBond();
    DLOG(F("Added bond. Remove wire"));
    delay(5000);
  }
}

