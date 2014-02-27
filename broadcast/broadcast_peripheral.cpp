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

void BroadcastPeripheral::didReceiveData(uint8_t characteristicId, uint8_t* data, uint8_t size) {
}

void BroadcastPeripheral::didReceiveCommandResponse(uint8_t commandId, uint8_t* data, uint8_t size) {
}

void BroadcastPeripheral::didDisconnect() {
}

void BroadcastPeripheral::didConnect() {
}

void BroadcastPeripheral::didTimeout() {
}

void BroadcastPeripheral::didStartAdvertising() {
}

void BroadcastPeripheral::didReceiveError(uint8_t pipe, uint8_t errorCode) {
}

void BroadcastPeripheral::didReceiveStatusChange() {
}

void BroadcastPeripheral::didBond() {
}

bool BroadcastPeripheral::doTimingChange() {
    return true;
}
