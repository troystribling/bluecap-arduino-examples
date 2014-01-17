#include <avr/pgmspace.h>
#include "hello_world_peripheral.h"
#include "dlog.h"
#include "services.h"

#undef PROGMEM
#define PROGMEM __attribute__(( section(".progmem.data") ))

#define MAX_COUNT                     7
#define INITIAL_COUNT                 5
#define MAX_COUNT_EXCEEDED_ERROR_CODE 1

static services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
static hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

const prog_char english[]   PROGMEM   = "Hello";
const prog_char hawaiian[]  PROGMEM   = "Aloha";
const prog_char saxon[]     PROGMEM   = "Moin";
const prog_char latvian[]   PROGMEM   = "Sveiki";
const prog_char norwegian[] PROGMEM   = "Moin";
const prog_char romainian[] PROGMEM   = "Salut";
const prog_char spanish[]   PROGMEM   = "Hola";
const prog_char swedish[]   PROGMEM   = "Hej";
const prog_char italian[]   PROGMEM   = "Ciao";
const prog_char kligon[]    PROGMEM   = "nuqneH";
const prog_char french[]    PROGMEM   = "Bonjour";
const prog_char danish[]    PROGMEM   = "Hej";
const prog_char bosnian[]   PROGMEM   = "Molim";

PROGMEM const char* const greetings[] = {
  english,
  hawaiian,
  saxon,
  latvian,
  norwegian,
  romainian,
  spanish,
  swedish,
  italian,
  kligon,
  french,
  danish,
  bosnian
};

static unsigned char count;
static char greeting[10];
static unsigned char currentIndex = 0;

HelloWorldPeripheral::HelloWorldPeripheral(uint8_t reqn, uint8_t rdyn): BlueCapPeripheral(reqn, rdyn) {
  setServicePipeTypeMapping(services_pipe_type_mapping, NUMBER_OF_PIPES);
  setSetUpMessages(setup_msgs, NB_SETUP_MESSAGES);
  count = INITIAL_COUNT;
  getGreeting();
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
    getGreeting();
    if (currentIndex < count) {
      currentIndex = 0;
    }
  }
  DLOG(F("Greeting"));
  DLOG(greeting);
  BlueCapPeripheral::loop();
}

void HelloWorldPeripheral::getGreeting() {
    strcpy_P(greeting, (char*)pgm_read_word(&(greetings[currentIndex])));
}