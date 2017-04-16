#include <Servo.h>
#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
public:
  Motor(int servoPin, int neutral, int backward, int forward);
  void stop();
  void goForward();
  void goBackward();

private:
  int mServoPin;
  int mNeutral;
  int mBackward;
  int mForward;
  bool mReversed;
  Servo mServo;
  bool isReversed();
};

#endif

