#ifndef CollisionDetector_h
#define CollisionDetector_h

#include <NewPingNoTimer.h>

#define MEASURE_PERIOD 100

class CollisionDetector
{
public:
  CollisionDetector();
  void attach(int triggerPin, int echoPin);
  void setMaxDistance(unsigned int maxDistance);
  void loop();
  bool isTooClose();

private:
  NewPing* mSonarPtr;
  int mMaxDistance;
  int mDistanceCm;
  unsigned long mLastMeasure;
  bool shouldMeasure();
};

#endif
