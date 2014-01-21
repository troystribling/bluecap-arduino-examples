#include "dlog.h"
#include "blue_cap_peripheral.h"
#include "bond_peripheral.h"
#include "services.h"

static services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
static hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

BondPeripheral::BondPeripheral(uint8_t reqn, uint8_t rdyn): BlueCapPeripheral(reqn, rdyn) {
  setServicePipeTypeMapping(services_pipe_type_mapping, NUMBER_OF_PIPES);
  setSetUpMessages(setup_msgs, NB_SETUP_MESSAGES);
}

void BondPeripheral::loop() {
  BlueCapPeripheral::loop();
}

bool BondPeripheral::arePipesAvailable() {
  return true;
}