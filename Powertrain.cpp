#include "Powertrain.h"

#include "SerialLog.h"

Powertrain::Powertrain() :
  mLeft(),
  mRight()
{
  SerialLog::Trace("Powertrain::Powertrain()");
}

void Powertrain::attach(int leftServoPin, int rightServoPin)
{
  SerialLog::Trace("Powertrain::attach(%d, %d)", leftServoPin, rightServoPin);

  mLeft.attach(leftServoPin);
  mRight.attach(rightServoPin);

  mLeft.setValues(90, 180, 0);
  mRight.setValues(90, 0, 180);
}

void Powertrain::stop()
{
  SerialLog::Trace("Powertrain::stop()");
  mLeft.stop();
  mRight.stop();
}

void Powertrain::goForward()
{
  SerialLog::Trace("Powertrain::goForward()");
  mLeft.goForward();
  mRight.goForward();
}

void Powertrain::goBackward()
{
  SerialLog::Trace("Powertrain::goBackward()");
  mLeft.goBackward();
  mRight.goBackward();
}

void Powertrain::rotateLeft()
{
  SerialLog::Trace("Powertrain::rotateLeft()");
  mLeft.goBackward();
  mRight.goForward();
}

void Powertrain::rotateRight()
{
  SerialLog::Trace("Powertrain::rotateRight()");
  mLeft.goForward();
  mRight.goBackward();
}
