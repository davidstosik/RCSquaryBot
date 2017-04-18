#pragma once

#include "Motor.h"

class Powertrain
{
public:
  Powertrain();
  void attach(int leftServoPin, int rightServoPin);
  void stop();
  void goForward();
  void goBackward();
  void rotateLeft();
  void rotateRight();

private:
  Motor mLeft;
  Motor mRight;
};
