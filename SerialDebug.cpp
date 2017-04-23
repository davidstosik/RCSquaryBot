#include "SerialDebug.h"

void SerialDebug::init()
{
  Serial.end();
  Serial.begin(SERIAL_FREQ);
  while (!Serial) {}
  Serial.println();
}

void SerialDebug::printf(const __FlashStringHelper *format, ...)
{
  char buf[SERIAL_DEBUG_BUF];
  va_list ap;
  va_start(ap, format);
#ifdef __AVR__
  vsnprintf_P(buf, sizeof(buf), (const char *)format, ap); // progmem for AVR
#else
  vsnprintf(buf, sizeof(buf), (const char *)format, ap); // for the rest of the world
#endif

  Serial.println(buf);

  va_end(ap);
}
