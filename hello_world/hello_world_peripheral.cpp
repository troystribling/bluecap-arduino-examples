#include <avr/pgmspace.h>
#include "hello_world_peripheral.h"
#include "dlog.h"
#include "services.h"

#define MAX_COUNT                     7
#define INITIAL_COUNT                 5
#define MAX_COUNT_EXCEEDED_ERROR_CODE 1

static services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
static hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

static char* greetings[] = {
  "Hello",
  "Aloha",
  "Moin",
  "Sveiki",
  "Moin",
  "Salut",
  "Hola",
  "Ciao",
  "nuqneH",
  "Bonjour",
  "Hej",
  "Molim"
};

static unsigned char count;
static unsigned char currentIndex = 0;

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
        if (sendAck(PIPE_HELLO_WORLD_COUNT_RX_ACK)) {
          DLOG(F("Hello World count ACK successful"));
        } else {
          DLOG(F("Hello World count ACK failed"));
        }
      } else {
        if (sendNack(PIPE_HELLO_WORLD_COUNT_RX_ACK, MAX_COUNT_EXCEEDED_ERROR_CODE)) {
          DLOG(F("Hello World count NACK successful"));
        } else {
          DLOG(F("Hello World count NACK failed"));
        }
      }
      DLOG(F("Hello World Count Update"));
      DLOG(count, DEC);
      break;
  }
}

void HelloWorldPeripheral::didReceiveError(uint8_t pipe, uint8_t) {
}

void HelloWorldPeripheral::loop() {
  if (millis() % 5000 == 0) {
    if (currentIndex < count) {
      currentIndex = 0;
    }
  }
  DLOG(F("Greeting"));
  BlueCapPeripheral::loop();
}
