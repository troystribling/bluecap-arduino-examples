#include "hello_world_peripheral.h"
#include "dlog.h"
#include "services.h"

#define MAX_COUNT                     7
#define INITIAL_COUNT                 5
#define MAX_COUNT_EXCEEDED_ERROR_CODE 1

static services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
static hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

HelloWorldPeripheral::HelloWorldPeripheral(uint8_t reqn, uint8_t rdyn): BlueCapPeripheral(reqn, rdyn) {
  setServicePipeTypeMapping(services_pipe_type_mapping, NUMBER_OF_PIPES);
  setSetUpMessages(setup_msgs, NB_SETUP_MESSAGES);
  count = INITIAL_COUNT;
}

void HelloWorldPeripheral::didReceiveData(uint8_t characteristicId, uint8_t* data, uint8_t length) {
  switch(characteristicId) {
    case PIPE_HELLO_WORLD_COUNT_RX_ACK:
      memcpy(&count, data, 1);
      if (count <= MAX_COUNT) {
        sendAck(PIPE_HELLO_WORLD_COUNT_RX_ACK);
      } else {
        sendNack(PIPE_HELLO_WORLD_COUNT_RX_ACK, MAX_COUNT_EXCEEDED_ERROR_CODE);
      }
      DLOG(F("Hello World Count Update"));
      DLOG(count, DEC);
      break;
  }
}

void HelloWorldPeripheral::loop() {
  BlueCapPeripheral::loop();
}
