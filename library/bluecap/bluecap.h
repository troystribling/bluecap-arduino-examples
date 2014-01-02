#ifndef  _BLUECAP_SHIELD_H
#define _BLUECAP_SHIELD_H

#include <services.h>

class BlueCap {
public:
  void setName(char *name);
  void begin();
  void write(unsigned char data);
  void writeBytes(unsigned char *data, unsigned char len);
  void doEvents();
  int read();
  unsigned char available();
  unsigned char connected(void);
  void setPins(uint8_t reqn, uint8_t rdyn);
};

#endif

