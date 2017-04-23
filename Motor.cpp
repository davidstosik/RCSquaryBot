#include "Motor.h"

Motor::Motor() :
  Servo()
{
}

void Motor::attach(int pin)
{
  Servo::attach(pin);
}

void Motor::setValues(int neutral, int backward, int forward)
{
  mNeutral = neutral;
  mBackward = backward;
  mForward = forward;

  stop();
}

bool Motor::isReversed()
{
  return mForward < mBackward;
}

void Motor::stop() {
  write(mNeutral);
}

void Motor::goForward()
{
  write(mForward);
}

void Motor::goBackward()
{
  write(mBackward);
}
