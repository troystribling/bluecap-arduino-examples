// hello_world.ino
#include <SPI.h>
#include "hello_world_peripheral.h"

HelloWorldPeripheral hello;

void setup() {
  Serial.begin(9600);
  hello.begin();
}

void loop() {
  hello.listen();
}
