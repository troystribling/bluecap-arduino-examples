#include "broadcast_peripheral.h"
#include "utils.h"

BroadcastPeripheral::BroadcastPeripheral(uint8_t _reqnPin, uint8_t _rdynPin) : BlueCapBroadcastingPeripheral(_reqnPin, _rdynPin) {
}

void BroadcastPeripheral::begin() {
  INFO(F("BroadcastPeripheral::begin"))
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

void BroadcastPeripheral::didStartAdvertising() {
}

void BroadcastPeripheral::didReceiveError(uint8_t pipe, uint8_t errorCode) {
}

void BroadcastPeripheral::didReceiveStatusChange() {
}

void BroadcastPeripheral::didBond() {
}

bool BroadcastPeripheral::doTimingChange() {
}
