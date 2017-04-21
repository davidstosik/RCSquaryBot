#include "Robot.h"

#include "SerialLog.h"
#include "BenQRemote.h"

Robot::Robot() :
  mPowertrain(),
  mRemote(),
  mCollisionDetector()
{
  SerialLog::Trace("Robot::Robot()");
  mRemote.SetDeviceCode(REMOTE_BENQ_DEVICE_CODE_LENGTH, REMOTE_BENQ_DEVICE_CODE);
}

void Robot::attachPowertrain(int leftPin, int rightPin)
{
  SerialLog::Trace("Robot::attachPowertrain(%d, %d)", leftPin, rightPin);
  mPowertrain.attach(leftPin, rightPin);
}

void Robot::attachRemote(int pin)
{
  SerialLog::Trace("Robot::attachRemote(%d)", pin);
  mRemote.Attach(pin);
}

void Robot::attachCollisionDetector(int triggerPin, int echoPin)
{
  SerialLog::Trace("Robot::attachCollisionDetector(%d, %d)", triggerPin, echoPin);
  mCollisionDetector.attach(triggerPin, echoPin);
}

void Robot::setCollisionMaxDistance(unsigned int maxDistance)
{
  SerialLog::Trace("Robot::setCollisionMaxDistance(%d)", maxDistance);
  mCollisionDetector.setMaxDistance(maxDistance);
}

void Robot::loop()
{
  SerialLog::Trace("Robot::loop()");

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
  SerialLog::Trace("Robot::stop(%lu)", time);

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
  SerialLog::Trace("Robot::shouldStop()");

  bool result = false;
  result = result || mState == FORWARD && mCollisionDetector.isTooClose();
  result = result || mStopAt > 0 && mStopAt < millis();
  return result;
}
