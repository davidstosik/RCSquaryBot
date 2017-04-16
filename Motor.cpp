#include <Arduino.h>
#include "Motor.h"

#include "SerialLog.h"

Motor::Motor(int servoPin, int neutral, int backward, int forward) :
  mServo()
{
  mServoPin = servoPin;
  mServo.attach(mServoPin);
  SerialLog::Trace("Motor::Motor(%d, %d, %d, %d)", mServoPin, neutral, backward, forward);
  mNeutral = neutral;
  mBackward = backward;
  mForward = forward;
  mReversed = (forward < backward);

  stop();
}

bool Motor::isReversed()
{
  SerialLog::Trace("Motor::isReversed() => %s", mReversed ? "true" : "false");
  return mReversed;
}

void Motor::stop() {
  SerialLog::Trace("Motor::stop()");
  mServo.write(mNeutral);
}

void Motor::goForward()
{
  SerialLog::Trace("Motor::goForward()");
  mServo.write(mForward);
}

void Motor::goBackward()
{
  SerialLog::Trace("Motor::goBackward()");
  mServo.write(mBackward);
}
