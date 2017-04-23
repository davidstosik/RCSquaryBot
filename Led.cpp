#include "Led.h"

#include <Arduino.h>

Led::Led()
{
}

void Led::attach(int pin)
{
  mPin = pin;
  pinMode(mPin, OUTPUT);
}

void Led::turnOff()
{
  mState = OFF;
  digitalWrite(mPin, LOW);
}

void Led::turnOn()
{
  mState = ON;
  digitalWrite(mPin, HIGH);
}

void Led::blink(int halfPeriod = HALF_PERIOD, int delay = 0)
{
  mState = BLINKING;
  mBlinkStart = millis() + delay;
  mBlinkHalfPeriod = halfPeriod;
}

void Led::loop()
{
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
  int timing = (millis() - mBlinkStart) % (mBlinkHalfPeriod * 2);
  return timing < mBlinkHalfPeriod;
}
