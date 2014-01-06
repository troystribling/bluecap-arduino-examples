// hello_world.ino
#include <SPI.h>
#include "bluecap.h"
#include "dlog.h"
#include "services.h"

services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

BlueCap ble("BlueCap", setup_msgs, NB_SETUP_MESSAGES, services_pipe_type_mapping, NUMBER_OF_PIPES);

void setup() {
  Serial.begin(9600);
  ble.begin();
}

void loop() {
  ble.doEvents();
}
