#include "CollisionDetector.h"

CollisionDetector::CollisionDetector()
{
}

void CollisionDetector::attach(int triggerPin, int echoPin)
{
  mSonarPtr = new NewPing(triggerPin, echoPin, 0);
}

void CollisionDetector::setMaxDistance(unsigned int maxDistance)
{
  mMaxDistance = maxDistance;
}

void CollisionDetector::loop()
{
  if (shouldMeasure())
  {
    mDistanceCm = mSonarPtr->ping_cm(mMaxDistance);
    mLastMeasure = millis();
  }
}

bool CollisionDetector::isTooClose()
{
  return mDistanceCm > 0 && mDistanceCm < mMaxDistance;
}

bool CollisionDetector::shouldMeasure()
{
  return millis() - mLastMeasure > MEASURE_PERIOD;
}
