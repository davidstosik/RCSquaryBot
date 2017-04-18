#pragma once

#include <IRremote.h>

#define REMOTE_UNPRESSED 0 // Meta code expressing "no button pressed"

class RemoteControl : private IRrecv
{
public:
  RemoteControl();
  void Attach(int recvpin);
  void SetDeviceCode(int nCodeLength, unsigned long nCode);
  unsigned long GetRemoteCode();

private:
  int mDeviceCodeLength;
  unsigned long mDeviceCode;
  bool MatchesDevice(unsigned long nCode);
  unsigned long GetDevicePrefix(unsigned long nCode);
};
