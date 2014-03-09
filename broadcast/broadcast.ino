// broadcast.ino
#include <SPI.h>
#include <EEPROM.h>
#include "aci.h"
#include "utils.h"
#include "blue_cap_peripheral.h"
#include "broadcast_peripheral.h"

#define REQN_PIN            9
#define RDYN_PIN            8

uint16_t addBondCount       = 0;
bool updateAddBondCount    = false;

BroadcastPeripheral broadcast(REQN_PIN, RDYN_PIN);

void setup() {
  Serial.begin(9600);
  DBUG_FREE_MEMORY;
  broadcast.begin();
}

void loop() {
  broadcast.loop();
}
