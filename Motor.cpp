#include <Arduino.h>
#include "Motor.h"

#include "SerialLog.h"

Motor::Motor() :
  Servo()
{
  SerialLog::Trace("Motor::Motor()");
}

void Motor::attach(int pin)
{
  SerialLog::Trace("Motor::attach(%d)", pin);

  Servo::attach(pin);
}

void Motor::setValues(int neutral, int backward, int forward)
{
  SerialLog::Trace("Motor::setValues(%d, %d, %d)", neutral, backward, forward);

  mNeutral = neutral;
  mBackward = backward;
  mForward = forward;

  stop();
}

bool Motor::isReversed()
{
  SerialLog::Trace("Motor::isReversed()");

  return mForward < mBackward;
}

void Motor::stop() {
  SerialLog::Trace("Motor::stop()");
  write(mNeutral);
}

void Motor::goForward()
{
  SerialLog::Trace("Motor::goForward()");
  write(mForward);
}

void Motor::goBackward()
{
  SerialLog::Trace("Motor::goBackward()");
  write(mBackward);
}
