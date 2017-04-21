#pragma once

#include "Powertrain.h"
#include "RemoteControl.h"
#include "CollisionDetector.h"

class Robot
{
public:
  Robot();
  void attachPowertrain(int leftPin, int rightPin);
  void attachRemote(int pin);
  void attachCollisionDetector(int triggerPin, int echoPin);
  void setCollisionMaxDistance(unsigned int maxDistance);
  void loop();

private:
  Powertrain mPowertrain;
  RemoteControl mRemote;
  CollisionDetector mCollisionDetector;
  unsigned long mStopAt = 0;
  enum State { STOPPED, FORWARD, BACKWARD, ROTATE_LEFT, ROTATE_RIGHT };
  State mState = STOPPED;
  void stop(unsigned long time = 0);
  bool shouldStop();
};
