#include "Robot.h"

#include "BenQRemote.h"
#include "SerialDebug.h"

Robot::Robot() :
  mPowertrain(),
  mRemote(),
  mCollisionDetector()
{
  S_DEBUG_INIT;

  mRemote.SetDeviceCode(REMOTE_BENQ_DEVICE_CODE_LENGTH, REMOTE_BENQ_DEVICE_CODE);
}

void Robot::attachPowertrain(int leftPin, int rightPin)
{
  mPowertrain.attach(leftPin, rightPin);
}

void Robot::attachRemote(int pin)
{
  mRemote.Attach(pin);
}

void Robot::attachCollisionDetector(int triggerPin, int echoPin)
{
  mCollisionDetector.attach(triggerPin, echoPin);
}

void Robot::setCollisionMaxDistance(unsigned int maxDistance)
{
  mCollisionDetector.setMaxDistance(maxDistance);
}

void Robot::loop()
{
  mCollisionDetector.loop();

  switch(mRemote.GetRemoteCode())
  {
    case(REMOTE_UP):
      mState = FORWARD;
      mPowertrain.goForward();
      stop(1000);
      break;
    case(REMOTE_DOWN):
      mState = BACKWARD;
      mPowertrain.goBackward();
      stop(1000);
      break;
    case(REMOTE_LEFT):
      mState = ROTATE_LEFT;
      mPowertrain.rotateLeft();
      stop(1000);
      break;
    case(REMOTE_RIGHT):
      mState = ROTATE_RIGHT;
      mPowertrain.rotateRight();
      stop(1000);
      break;
  }

  if (shouldStop())
  {
    stop();
  }
}

void Robot::stop(unsigned long time = 0)
{
  if (time == 0)
  {
    mStopAt = 0;
    mPowertrain.stop();
    mState = STOPPED;
  } else {
    mStopAt = millis() + time;
  }
}

bool Robot::shouldStop()
{
  bool result = false;
  result = result || mState == FORWARD && mCollisionDetector.isTooClose();
  result = result || mStopAt > 0 && mStopAt < millis();
  return result;
}
