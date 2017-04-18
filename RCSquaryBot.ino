#include <Arduino.h>

#include "SerialLog.h"
#include "Robot.h"

#define SERIAL_FREQ 115200
#define LOG_LEVEL LEVEL_ALL

// Pin numbers
#define PIN_LEFT_SERVO 9
#define PIN_RIGHT_SERVO 10
#define PIN_IR_RECEIVER 11

Robot robot;

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

  robot.attachPowertrain(PIN_LEFT_SERVO, PIN_RIGHT_SERVO);
  robot.attachRemote(PIN_IR_RECEIVER);

  SerialLog::Info("Finished setup");
}

void loop()
{
  robot.loop();
}
