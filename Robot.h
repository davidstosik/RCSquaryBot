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
  unsigned long mStopAt = 0;
  enum State { STOPPED, FORWARD, BACKWARD, ROTATE_LEFT, ROTATE_RIGHT };
  State mState = STOPPED;
  void stop(unsigned long time = 0);
  bool shouldStop();
};
