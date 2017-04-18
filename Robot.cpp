#include "Robot.h"

#include "SerialLog.h"
#include "BenQRemote.h"

Robot::Robot() :
  powertrain(),
  remote()
{
  SerialLog::Trace("Robot::Robot()");
  remote.SetDeviceCode(REMOTE_BENQ_DEVICE_CODE_LENGTH, REMOTE_BENQ_DEVICE_CODE);
}

void Robot::attachPowertrain(int leftPin, int rightPin)
{
  SerialLog::Trace("Robot::attachPowertrain(%d, %d)", leftPin, rightPin);
  powertrain.attach(leftPin, rightPin);
}

void Robot::attachRemote(int pin)
{
  SerialLog::Trace("Robot::attachRemote(%d)", pin);
  remote.Attach(pin);
}

void Robot::loop()
{
  switch(remote.GetRemoteCode())
  {
    case(REMOTE_UP):
      powertrain.goForward();
      delay(500);
      break;
    case(REMOTE_DOWN):
      powertrain.goBackward();
      delay(500);
      break;
    case(REMOTE_LEFT):
      powertrain.rotateLeft();
      delay(500);
      break;
    case(REMOTE_RIGHT):
      powertrain.rotateRight();
      delay(500);
      break;
  }
  powertrain.stop();
  delay(10);
}
