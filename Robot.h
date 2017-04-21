#pragma once

#include "Powertrain.h"
#include "RemoteControl.h"

class Robot
{
public:
  Robot();
  void attachPowertrain(int leftPin, int rightPin);
  void attachRemote(int pin);
  void loop();

private:
  Powertrain mPowertrain;
  RemoteControl mRemote;
};
