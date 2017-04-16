#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <IRremote.h>

#define REMOTE_UNPRESSED 0 // Meta code expressing "no button pressed"

class RemoteControl
{
public:
  RemoteControl(int pin);
  unsigned long GetRemoteCode();
  void SetDevice(int nCodeLength, unsigned long nCode);

private:
  IRrecv mReceiver;
  int mDeviceCodeLength;
  unsigned long mDeviceCode;
  bool MatchesDevice(unsigned long nCode);
  unsigned long GetDevicePrefix(unsigned long nCode);
};

#endif
