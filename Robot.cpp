#include "Robot.h"

#include "SerialLog.h"
#include "BenQRemote.h"

Robot::Robot() :
  mPowertrain(),
  mRemote()
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

void Robot::loop()
{
  switch(mRemote.GetRemoteCode())
  {
    case(REMOTE_UP):
      mPowertrain.goForward();
      delay(500);
      break;
    case(REMOTE_DOWN):
      mPowertrain.goBackward();
      delay(500);
      break;
    case(REMOTE_LEFT):
      mPowertrain.rotateLeft();
      delay(500);
      break;
    case(REMOTE_RIGHT):
      mPowertrain.rotateRight();
      delay(500);
      break;
  }
  mPowertrain.stop();
  delay(10);
}
