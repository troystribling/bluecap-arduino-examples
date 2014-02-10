#include "dlog.h"
#include "blue_cap_peripheral.h"
#include "bond_peripheral.h"
#include "services.h"

static services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
static hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

BondPeripheral::BondPeripheral(uint8_t _reqn, uint8_t _rdyn, uint16_t _eepromOffset) : BlueCapPeripheral(_reqn, _rdyn, _eepromOffset) {
  setServicePipeTypeMapping(services_pipe_type_mapping, NUMBER_OF_PIPES);
  setSetUpMessages(setup_msgs, NB_SETUP_MESSAGES);
}

void BondPeripheral::didReceiveCommandResponse(uint8_t commandId, uint8_t* data, uint8_t size) {
  switch(commandId) {
    case ACI_CMD_CONNECT:
      DLOG(F("ACI_CMD_CONNECT response received"));
      break;
    case ACI_CMD_GET_DEVICE_VERSION:
      DLOG(F("ACI_CMD_GET_DEVICE_VERSION response received"));
      break;
    case ACI_CMD_BOND:
      DLOG(F("ACI_CMD_BOND response received"));
      break;
    case ACI_CMD_CHANGE_TIMING:
      DLOG(F("ACI_CMD_CHANGE_TIMING response received"));
      break;
    default:
      break;
  }
}

void BondPeripheral::loop() {
  BlueCapPeripheral::loop();
}

bool BondPeripheral::doTimingChange() {
  return true;
}