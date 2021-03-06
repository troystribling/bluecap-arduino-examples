// hello_world.ino
#include <SPI.h>
#include <EEPROM.h>
#include "utils.h"
#include "aci.h"
#include "blue_cap_peripheral.h"
#include "hello_world_peripheral.h"

#define REQN_PIN  9
#define RDYN_PIN  8

HelloWorldPeripheral hello(REQN_PIN, RDYN_PIN);

void setup() {
  Serial.begin(9600);
  DBUG_FREE_MEMORY;
  hello.begin();
}

void loop() {
  hello.loop();
}
