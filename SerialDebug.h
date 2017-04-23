#ifndef SerialDebug_h
#define SerialDebug_h

// Uncomment any of the two following lines to enable debug/trace.
//#define S_DEBUG_ON
//#define S_TRACE_ON

#include <Arduino.h>

#define SERIAL_DEBUG_BUF 128
#define SERIAL_FREQ 230400

#ifdef S_DEBUG_ON
  #define S_DEBUG(x) Serial.println(x)
  #define S_DEBUGF(x, ...) SerialDebug::printf(F(x), ##__VA_ARGS__)
#else
  #define S_DEBUG(x)
  #define S_DEBUGF(x, ...)
#endif

#ifdef S_TRACE_ON
  #define S_TRACE(x) Serial.println(x)
  #define S_TRACEF(x, ...) SerialDebug::printf(F(x), ##__VA_ARGS__)
#else
  #define S_TRACE(x)
  #define S_TRACEF(x, ...)
#endif

#if defined(S_TRACE_ON) || defined(S_DEBUG_ON)
  #define S_DEBUG_INIT SerialDebug::init()
#else
  #define S_DEBUG_INIT
#endif

class SerialDebug
{
public:
  static void init();
  static void printf(const __FlashStringHelper *format, ...);
};

#endif
