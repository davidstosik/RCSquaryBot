#include "Powertrain.h"

Powertrain::Powertrain() :
  mLeft(),
  mRight()
{
}

void Powertrain::attach(int leftServoPin, int rightServoPin)
{
  mLeft.attach(leftServoPin);
  mRight.attach(rightServoPin);

  mLeft.setValues(90, 180, 0);
  mRight.setValues(90, 0, 180);
}

void Powertrain::stop()
{
  mLeft.stop();
  mRight.stop();
}

void Powertrain::goForward()
{
  mLeft.goForward();
  mRight.goForward();
}

void Powertrain::goBackward()
{
  mLeft.goBackward();
  mRight.goBackward();
}

void Powertrain::rotateLeft()
{
  mLeft.goBackward();
  mRight.goForward();
}

void Powertrain::rotateRight()
{
  mLeft.goForward();
  mRight.goBackward();
}
