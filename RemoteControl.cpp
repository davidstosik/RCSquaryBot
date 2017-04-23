#include "RemoteControl.h"

RemoteControl::RemoteControl() :
  IRrecv(0)
{
  mDeviceCodeLength = 0;
  mDeviceCode = 0;
}

void RemoteControl::Attach(int recvpin)
{
  irparams.recvpin = recvpin;
  enableIRIn();
}

void RemoteControl::SetDeviceCode(int nCodeLength, unsigned long nCode)
{
  mDeviceCodeLength = nCodeLength;
  mDeviceCode = nCode;
}

unsigned long RemoteControl::GetRemoteCode()
{
  decode_results ir_results;

  if (!decode(&ir_results)) { return REMOTE_UNPRESSED; }
  unsigned long result = (&ir_results)->value;
  resume();
  if (!MatchesDevice(result)) { return REMOTE_UNPRESSED; }

  return result;
}

bool RemoteControl::MatchesDevice(unsigned long nCode)
{
  return mDeviceCode == GetDevicePrefix(nCode);
}

unsigned long RemoteControl::GetDevicePrefix(unsigned long nCode)
{
  int shiftCount = 8 * sizeof(nCode) - mDeviceCodeLength;
  return nCode >> shiftCount;
}
