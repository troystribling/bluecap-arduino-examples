/*

Copyright (c) 2012, 2013 RedBearLab

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef _BLUECAP_H
#define _BLUECAP_H

#include "nordic/lib_aci.h"

class BlueCap {

public:

  BlueCap(char* name);
  BlueCap(char*           name,
          hal_aci_data_t* messages,
          int             messagesCount);
  BlueCap(char*                         name,
          hal_aci_data_t*               messages,
          int                           messagesCount,
          services_pipe_type_mapping_t* mapping,
          int                           mappingCount);
  ~BlueCap();

  void begin();
  void doEvents();
  void processEvents();

  int read();
  void write(unsigned char data);
  void writeBytes(unsigned char *data, unsigned char len);

  unsigned char available();
  unsigned char connected(void);

  void setDeviceName(char* name);
  void setServicePipeTypeMapping(services_pipe_type_mapping_t* mapping, int count);
  void setSetUpMessages(hal_aci_data_t* messages, int count);

private:

  services_pipe_type_mapping_t*   servicesPipeTypeMapping;
  int                             numberOfPipes;
  hal_aci_data_t*                 setUpMessages;
  int                             numberOfSetupMessages;
  char*                           deviceName;

private:

  void init(char*                         name,
            hal_aci_data_t*               messages,
            int                           messagesCount,
            services_pipe_type_mapping_t* mapping,
            int                           mappingCount);
};

#endif

