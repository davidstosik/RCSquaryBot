#include "Led.h"

#include <Arduino.h>
#include "SerialLog.h"

Led::Led()
{
  SerialLog::Trace("Led::Led()");
}

void Led::attach(int pin)
{
  SerialLog::Trace("Led::attach(%d)", pin);
  mPin = pin;
  pinMode(mPin, OUTPUT);
}

void Led::turnOff()
{
  SerialLog::Trace("Led::turnOff()");
  mState = OFF;
  digitalWrite(mPin, LOW);
}

void Led::turnOn()
{
  SerialLog::Trace("Led::turnOn()");
  mState = ON;
  digitalWrite(mPin, HIGH);
}

void Led::blink(int halfPeriod = HALF_PERIOD, int delay = 0)
{
  SerialLog::Trace("Led::blink()");
  mState = BLINKING;
  mBlinkStart = millis() + delay;
  mBlinkHalfPeriod = halfPeriod;
}

void Led::loop()
{
  SerialLog::Trace("Led::loop()");
  switch(mState)
  {
    case ON:
      digitalWrite(mPin, HIGH);
      break;
    case OFF:
      digitalWrite(mPin, LOW);
      break;
    case BLINKING:
      digitalWrite(mPin, blinkIsOn() ? HIGH : LOW);
      break;
  }
}

bool Led::blinkIsOn()
{
  SerialLog::Trace("Led::blinkIsOn()");
  int timing = (millis() - mBlinkStart) % (mBlinkHalfPeriod * 2);
  return timing < mBlinkHalfPeriod;
}
