#include "hello_world_peripheral.h"
#include "dlog.h"
#include "services.h"

HelloWorldPeripheral::HelloWorldPeripheral(): BlueCapPeripheral() {
  services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
  setServicePipeTypeMapping(services_pipe_type_mapping, NUMBER_OF_PIPES);
  hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;
  setSetUpMessages(setup_msgs, NB_SETUP_MESSAGES);
}