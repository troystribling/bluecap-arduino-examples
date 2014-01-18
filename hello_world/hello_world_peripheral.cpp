#include <avr/pgmspace.h>
#include "hello_world_peripheral.h"
#include "dlog.h"
#include "services.h"

#define GREETING_COUNT                12
#define INITIAL_UPDATE_PERIOD         1000
#define INVALID_UPDATE_PERIOD_ERROR   1
#define MIN_UPDATE_PERIOD             200
#define MAX_UPDATE_PERIOD             10000

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

static uint16_t updatePeriod;
static unsigned char greetingIndex = 0;

HelloWorldPeripheral::HelloWorldPeripheral(uint8_t reqn, uint8_t rdyn): BlueCapPeripheral(reqn, rdyn) {
  setServicePipeTypeMapping(services_pipe_type_mapping, NUMBER_OF_PIPES);
  setSetUpMessages(setup_msgs, NB_SETUP_MESSAGES);
  updatePeriod = INITIAL_UPDATE_PERIOD;
}

void HelloWorldPeripheral::didReceiveData(uint8_t characteristicId, uint8_t* data, uint8_t length) {
  switch(characteristicId) {
    case PIPE_HELLO_WORLD_UPDATE_PERIOD_RX_ACK:
      setUpdatePeriod(data, length);
      break;
  }
}

void HelloWorldPeripheral::didReceiveError(uint8_t pipe, uint8_t) {
  DLOG(F("HelloWorldPeripheral"));
}

void HelloWorldPeripheral::loop() {
  // setGreeting();
  BlueCapPeripheral::loop();
}

void HelloWorldPeripheral::setUpdatePeriod(uint8_t* data, uint8_t length) {
   memcpy(&updatePeriod, data, PIPE_HELLO_WORLD_UPDATE_PERIOD_RX_ACK_MAX_SIZE);
    if (updatePeriod > MIN_UPDATE_PERIOD && updatePeriod < MAX_UPDATE_PERIOD) {
      if (sendAck(PIPE_HELLO_WORLD_UPDATE_PERIOD_RX_ACK)) {
        DLOG(F("Hello World Update Period ACK successful"));
      } else {
        DLOG(F("Hello World Update Period ACK failed"));
      }
    } else {
      if (sendNack(PIPE_HELLO_WORLD_UPDATE_PERIOD_RX_ACK, INVALID_UPDATE_PERIOD_ERROR)) {
        DLOG(F("Hello World Update Period NACK successful"));
      } else {
        DLOG(F("Hello World Update Period NACK failed"));
      }
    }
    DLOG(F("Hello World Update Period Update"));
    DLOG(updatePeriod, DEC);
}

void HelloWorldPeripheral::setGreeting() {
  if (millis() % updatePeriod == 0) {
    DLOG(F("Greeting"));
    char* greeting = greetings[greetingIndex];
    DLOG(greeting);
    sendData(PIPE_HELLO_WORLD_GREETING_SET, (uint8_t*)greeting, strlen(greeting));
    greetingIndex++;
    if (greetingIndex >= GREETING_COUNT) {
      greetingIndex = 0;
    }
  }
}
