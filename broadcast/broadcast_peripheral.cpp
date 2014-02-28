#include "broadcast_peripheral.h"
#include "utils.h"
#include "services.h"

static services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
static hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

BroadcastPeripheral::BroadcastPeripheral(uint8_t _reqnPin, uint8_t _rdynPin) : BlueCapBroadcastingPeripheral(_reqnPin, _rdynPin) {
  setServicePipeTypeMapping(services_pipe_type_mapping, NUMBER_OF_PIPES);
  setSetUpMessages(setup_msgs, NB_SETUP_MESSAGES);
}

void BroadcastPeripheral::begin() {
  INFO(F("BroadcastPeripheral::begin"));
  BlueCapPeripheral::begin();
}

void BroadcastPeripheral::loop() {
  BlueCapPeripheral::loop();
}

void BroadcastPeripheral::didReceiveCommandResponse(uint8_t commandId, uint8_t* data, uint8_t size) {
  switch(commandId) {
    case ACI_CMD_BROADCAST:
      INFO(F("ACI_CMD_BROADCAST response received, broadcasting"));
      break;
    default:
      break;
  }
}

void BroadcastPeripheral::didDisconnect() {
  INFO(F("BroadcastPeripheral::didDisconnect"));
}

void BroadcastPeripheral::didTimeout() {
  INFO(F("BroadcastPeripheral::didTimeout"));
  broadcast();
}

void BroadcastPeripheral::didReceiveError(uint8_t pipe, uint8_t errorCode) {
  INFO(F("BroadcastPeripheral::didReceiveError"));
}

bool BroadcastPeripheral::doTimingChange() {
    return true;
}
