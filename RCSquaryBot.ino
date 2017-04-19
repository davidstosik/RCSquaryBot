#include <Arduino.h>

#include "SerialLog.h"
#include "Robot.h"
#include "Led.h"

#define SERIAL_FREQ 115200
#define LOG_LEVEL LEVEL_ALL

// Pin numbers
#define PIN_LED_GREEN 5
#define PIN_LED_ORANGE 6
#define PIN_LED_RED 7
#define PIN_SERVO_LEFT 9
#define PIN_SERVO_RIGHT 10
#define PIN_IR_RECEIVER 11

Robot robot;
Led redLed, orangeLed, greenLed;;

void beginLog()
{
  Serial.begin(SERIAL_FREQ);
  while (!Serial) {} // wait for serial port to connect
  Serial.println("\n"); // clear with a new line
  SerialLog::Init(LOG_LEVEL);
}

void setup()
{
  beginLog();
  SerialLog::Info("Starting setup");

  robot.attachPowertrain(PIN_SERVO_LEFT, PIN_SERVO_RIGHT);
  robot.attachRemote(PIN_IR_RECEIVER);

  redLed.attach(PIN_LED_RED);
  orangeLed.attach(PIN_LED_ORANGE);
  greenLed.attach(PIN_LED_GREEN);

  redLed.blink(200);
  orangeLed.blink(200, 67);
  greenLed.blink(200, 133);

  SerialLog::Info("Finished setup");
}

void loop()
{
  redLed.loop();
  orangeLed.loop();
  greenLed.loop();
  robot.loop();
}
