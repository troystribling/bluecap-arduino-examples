// bond.ino
#include <SPI.h>
#include <EEPROM.h>
#include "aci.h"
#include "utils.h"
#include "blue_cap_peripheral.h"
#include "bond_peripheral.h"

#define REQN_PIN            9
#define RDYN_PIN            8
#define EEPROM_OFFSET       0
#define RESET_PIN           6
#define ADD_BOND_PIN        7
#define MAX_BONDS           2
#define ADD_BOND_PIN_COUNT  20000

uint16_t addBondCount       = 0;
bool updateAddBondCount    = false;

BondPeripheral bond(REQN_PIN, RDYN_PIN, EEPROM_OFFSET, MAX_BONDS);

void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif

  pinMode(RESET_PIN, INPUT);
  pinMode(ADD_BOND_PIN, INPUT);
  DLOG(F("To delete the bond stored in EEPROM, connect pin 6 to 5v and reset."));
  DLOG(F("To add a bond connect pin 6 to 5v."));
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
  if (digitalRead(ADD_BOND_PIN) == HIGH && addBondCount == ADD_BOND_PIN_COUNT) {
    if (bond.addBond()) {
      DLOG(F("Added bond. Remove wire"));
    } else {
      DLOG(F("Failed to add bond. Remove wire"));
    }
    addBondCount = 0;
    updateAddBondCount = false;
    delay(5000);
  } else if (digitalRead(ADD_BOND_PIN) == HIGH) {
    if (updateAddBondCount) {
      addBondCount++;
    }
  } else {
    updateAddBondCount = true;
    addBondCount = 0;
  }
}

