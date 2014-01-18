// hello_world.ino
#include <SPI.h>
#include "dlog.h"
#include "blue_cap_peripheral.h"
#include "hello_world_peripheral.h"
#include "byte_swap.h"

#define REQN_PIN  9
#define RDYN_PIN  8

HelloWorldPeripheral hello(REQN_PIN, RDYN_PIN);

void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif
  hello.begin();
}

void loop() {
  hello.loop();
}
