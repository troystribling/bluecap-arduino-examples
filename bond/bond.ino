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

BondPeripheral bond(REQN_PIN, RDYN_PIN, 0, 1);

void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif

  pinMode(RESET_PIN, INPUT);
  DLOG(F("To delete the bond stored in EEPROM, connect Pin 6 to 3.3v and Reset."));
  DLOG(F("Make sure that the bond on the phone/PC is deleted as well."));
  DLOG(F("Reset pin value:"));
  DLOG(digitalRead(RESET_PIN), DEC);
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
}

