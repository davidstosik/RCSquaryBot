#include <Arduino.h>
#include "Powertrain.h"

#include "Motor.h"
#include "SerialLog.h"

Powertrain::Powertrain(int leftServoPin, int rightServoPin) :
  mLeft(leftServoPin, 90, 180, 0),
  mRight(rightServoPin, 90, 0, 180)
{
  SerialLog::Trace("Powertrain::Powertrain(%d, %d)", leftServoPin, rightServoPin);
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