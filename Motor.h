#pragma once

#include <Servo.h>

class Motor : private Servo
{
public:
  Motor();
  void attach(int pin);
  void setValues(int neutral, int backward, int forward);
  void stop();
  void goForward();
  void goBackward();

private:
  int mNeutral;
  int mBackward;
  int mForward;
  bool isReversed();
};
