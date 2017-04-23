#include <Arduino.h>

#include "Robot.h"
#include "Led.h"

// Pin numbers
#define PIN_LED_GREEN 5
#define PIN_LED_ORANGE 6
#define PIN_LED_RED 7
#define PIN_SERVO_LEFT 9
#define PIN_SERVO_RIGHT 10
#define PIN_IR_RECEIVER 11
#define PIN_SONAR_ECHO 12
#define PIN_SONAR_TRIGGER 13

Robot robot;
Led redLed, orangeLed, greenLed;

void setup()
{

  robot.attachPowertrain(PIN_SERVO_LEFT, PIN_SERVO_RIGHT);
  robot.attachRemote(PIN_IR_RECEIVER);
  robot.attachCollisionDetector(PIN_SONAR_TRIGGER, PIN_SONAR_ECHO);
  robot.setCollisionMaxDistance(7);

  redLed.attach(PIN_LED_RED);
  orangeLed.attach(PIN_LED_ORANGE);
  greenLed.attach(PIN_LED_GREEN);

  redLed.blink(200);
  orangeLed.blink(200, 67);
  greenLed.blink(200, 133);

}

void loop()
{
  redLed.loop();
  orangeLed.loop();
  greenLed.loop();
  robot.loop();
}
