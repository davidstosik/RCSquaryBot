#include "RemoteControl.h"

#include "SerialLog.h"

RemoteControl::RemoteControl() :
  IRrecv(0)
{
  SerialLog::Trace("RemoteControl::RemoteControl()");

  mDeviceCodeLength = 0;
  mDeviceCode = 0;
}

void RemoteControl::Attach(int recvpin)
{
  SerialLog::Trace("RemoteControl::Attach(%d)", recvpin);

  irparams.recvpin = recvpin;
  enableIRIn();
}

void RemoteControl::SetDeviceCode(int nCodeLength, unsigned long nCode)
{
  SerialLog::Trace("RemoteControl::SetDeviceCode(%d, 0x%08lx)", nCodeLength, nCode);

  mDeviceCodeLength = nCodeLength;
  mDeviceCode = nCode;
}

unsigned long RemoteControl::GetRemoteCode()
{
  SerialLog::Trace("RemoteControl::GetRemoteCode()");

  decode_results ir_results;

  if (!decode(&ir_results)) { return REMOTE_UNPRESSED; }
  unsigned long result = (&ir_results)->value;
  resume();
  if (!MatchesDevice(result)) { return REMOTE_UNPRESSED; }

  SerialLog::Debug("[REMOTECONTROL] Remote code received: 0x%08lx", result);

  return result;
}

bool RemoteControl::MatchesDevice(unsigned long nCode)
{
  SerialLog::Trace("RemoteControl::MatchesDevice(0x%08lx)", nCode);

  bool result = mDeviceCode == GetDevicePrefix(nCode);

  SerialLog::Trace("RemoteControl::MatchesDevice => %s", result ? "true" : "false");
  return result;
}

unsigned long RemoteControl::GetDevicePrefix(unsigned long nCode)
{
  SerialLog::Trace("RemoteControl::GetDevicePrefix(0x%08lx)", nCode);

  int shiftCount = 8 * sizeof(nCode) - mDeviceCodeLength;
  unsigned long result = nCode >> shiftCount;

  SerialLog::Trace("RemoteControl::GetDevicePrefix => 0x%08lx", result);
  return result;
}
