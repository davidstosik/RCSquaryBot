#include "SerialLog.h"
#include "Powertrain.h"
#include "RemoteControl.h"
#include "BenQRemote.h"

#define SERIAL_FREQ 115200
#define LOG_LEVEL LEVEL_ALL

// Pin numbers
#define PIN_LEFT_SERVO 9
#define PIN_RIGHT_SERVO 10
#define PIN_IR_RECEIVER 11

Powertrain pt;
RemoteControl remote;

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

  pt.attach(PIN_LEFT_SERVO, PIN_RIGHT_SERVO);
  remote.Attach(PIN_IR_RECEIVER);
  remote.SetDeviceCode(REMOTE_BENQ_DEVICE_CODE_LENGTH, REMOTE_BENQ_DEVICE_CODE);

  SerialLog::Info("Finished setup");
}

void loop()
{
  switch(remote.GetRemoteCode())
  {
    case(REMOTE_UP):
      pt.goForward();
      delay(500);
      break;
    case(REMOTE_DOWN):
      pt.goBackward();
      delay(500);
      break;
    case(REMOTE_LEFT):
      pt.rotateLeft();
      delay(500);
      break;
    case(REMOTE_RIGHT):
      pt.rotateRight();
      delay(500);
      break;
  }
  pt.stop();
  delay(10);
}
