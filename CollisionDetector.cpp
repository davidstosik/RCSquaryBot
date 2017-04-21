#include "CollisionDetector.h"

#include "SerialLog.h"

CollisionDetector::CollisionDetector()
{
  SerialLog::Trace("CollisionDetector::CollisionDetector()");
}

void CollisionDetector::attach(int triggerPin, int echoPin)
{
  SerialLog::Trace("CollisionDetector::attach(%d, %d)", triggerPin, echoPin);
  mSonarPtr = new NewPing(triggerPin, echoPin, 0);
}

void CollisionDetector::setMaxDistance(unsigned int maxDistance)
{
  SerialLog::Trace("CollisionDetector::setMaxDistance(%d)", maxDistance);
  mMaxDistance = maxDistance;
}

void CollisionDetector::loop()
{
  SerialLog::Trace("CollisionDetector::loop()");
  if (shouldMeasure())
  {
    mDistanceCm = mSonarPtr->ping_cm(mMaxDistance);
    mLastMeasure = millis();
  }
}

bool CollisionDetector::isTooClose()
{
  SerialLog::Trace("CollisionDetector::isTooClose()");
  return mDistanceCm > 0 && mDistanceCm < mMaxDistance;
}

bool CollisionDetector::shouldMeasure()
{
  SerialLog::Trace("CollisionDetector::shouldMeasure()");
  return millis() - mLastMeasure > MEASURE_PERIOD;
}
