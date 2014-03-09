#include "utils.h"
#include "blue_cap_peripheral.h"
#include "bond_peripheral.h"
#include "services.h"

static services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
static hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

BondPeripheral::BondPeripheral(uint8_t _reqn, uint8_t _rdyn, uint16_t _eepromOffset, uint8_t _maxBonds) : BlueCapBondedPeripheral(_reqn, _rdyn, _eepromOffset, _maxBonds) {
  setServicePipeTypeMapping(services_pipe_type_mapping, NUMBER_OF_PIPES);
  setSetUpMessages(setup_msgs, NB_SETUP_MESSAGES);
}

void BondPeripheral::didReceiveCommandResponse(uint8_t commandId, uint8_t* data, uint8_t size) {
  switch(commandId) {
    case ACI_CMD_CONNECT:
      INFO_LOG(F("ACI_CMD_CONNECT response received"));
      break;
    case ACI_CMD_GET_DEVICE_VERSION:
      INFO_LOG(F("ACI_CMD_GET_DEVICE_VERSION response received"));
      break;
    case ACI_CMD_BOND:
      INFO_LOG(F("ACI_CMD_BOND response received"));
      break;
    case ACI_CMD_CHANGE_TIMING:
      INFO_LOG(F("ACI_CMD_CHANGE_TIMING response received"));
      break;
    default:
      break;
  }
}

void BondPeripheral::loop() {
  BlueCapPeripheral::loop();
}

void BondPeripheral::begin() {
  INFO_LOG(F("BondPeripheral::begin"));
  BlueCapPeripheral::begin();
}

bool BondPeripheral::doTimingChange() {
  return true;
}

void BondPeripheral::didBond() {
  INFO_LOG(F("BondPeripheral::didBond"));
}

void BondPeripheral::didReceiveError(uint8_t pipe, uint8_t errorCode) {
  INFO_LOG(F("BondPeripheral::didReceiveError"));
  INFO_LOG(pipe, HEX);
  INFO_LOG(errorCode, HEX);
}
