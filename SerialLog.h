#ifndef SerialLog_h
#define SerialLog_h

#include <Arduino.h>

#define SERIAL_LOG_DEFAULT_BUFFER_SIZE 128

#define LEVEL_ALL 0
#define LEVEL_TRACE 30
#define LEVEL_DEBUG 60
#define LEVEL_INFO 90
#define LEVEL_WARN 120
#define LEVEL_ERROR 150
#define LEVEL_FATAL 180
#define LEVEL_NONE UINT8_MAX

class SerialLog
{
public:
 
  static void Init(uint8_t nLevel = LEVEL_INFO, int nBufferSize = SERIAL_LOG_DEFAULT_BUFFER_SIZE);
  static void SetLevel(uint8_t nLevel);
  static void SetBufferSize(int nBufferSize);

  static void Write(uint8_t nLevel, int nSize, const char *szFormat, ...);
  static void Write(uint8_t nLevel, const char *szFormat, ...);

  static void Fatal(const char *szFormat, ...);
  static void Error(const char *szFormat, ...);
  static void Warn(const char *szFormat, ...);
  static void Info(const char *szFormat, ...);
  static void Debug(const char *szFormat, ...);
  static void Trace(const char *szFormat, ...);

private:
  static int m_nLevel;
  static int m_nBufferSize;
  static bool ShouldLog(uint8_t nLevel);
  SerialLog();
  static void VWrite(uint8_t nLevel, const char *szFormat, va_list args, int nSize = 0);
};

#endif
