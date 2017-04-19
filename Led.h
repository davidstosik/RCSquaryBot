#pragma once

#define HALF_PERIOD 500

class Led
{
public:
  Led();
  void attach(int pin);
  void turnOff();
  void turnOn();
  void blink(int halfPeriod = HALF_PERIOD, int delay = 0);
  void loop();

private:
  enum State { OFF, ON, BLINKING };
  int mPin;
  State mState;
  unsigned long mBlinkStart;
  int mBlinkHalfPeriod;
  bool blinkIsOn();
};
