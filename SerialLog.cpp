#include "SerialLog.h"

int SerialLog::m_nBufferSize;
int SerialLog::m_nLevel;

void SerialLog::Init(uint8_t nLevel = LEVEL_INFO, int nBufferSize = SERIAL_LOG_DEFAULT_BUFFER_SIZE)
{
  SetLevel(nLevel);
  SetBufferSize(nBufferSize);
}

void SerialLog::SetBufferSize(int nBufferSize)
{
  m_nBufferSize = nBufferSize;
}

void SerialLog::SetLevel(uint8_t nLevel)
{
  m_nLevel = nLevel;
}

bool SerialLog::ShouldLog(uint8_t nLevel)
{
  return nLevel >= m_nLevel;
}

void SerialLog::VWrite(uint8_t nLevel, const char *szFormat, va_list args, int nSize = 0)
{
  if (!ShouldLog(nLevel)) { return; }

  // Guess the required size for the buffer.
  if (nSize == 0) { nSize = m_nBufferSize; }

  char* buffer = malloc(nSize*sizeof(char));
  vsnprintf(buffer, nSize, szFormat, args);

  Serial.println(buffer);
  free(buffer);
}

void SerialLog::Write(uint8_t nLevel, int nSize, const char *szFormat, ...)
{
  va_list args;
  va_start(args, szFormat);
  VWrite(nLevel, szFormat, args, nSize);
  va_end(args);
}

void SerialLog::Write(uint8_t nLevel, const char *szFormat, ...)
{
  va_list args;
  va_start(args, szFormat);
  VWrite(nLevel, szFormat, args);
  va_end(args);
}

void SerialLog::Fatal(const char *szFormat, ...)
{
  va_list args;
  va_start(args, szFormat);
  VWrite(LEVEL_FATAL, szFormat, args);
  va_end(args);
}

void SerialLog::Error(const char *szFormat, ...)
{
  va_list args;
  va_start(args, szFormat);
  VWrite(LEVEL_ERROR, szFormat, args);
  va_end(args);
}

void SerialLog::Warn(const char *szFormat, ...)
{
  va_list args;
  va_start(args, szFormat);
  VWrite(LEVEL_WARN, szFormat, args);
  va_end(args);
}

void SerialLog::Info(const char *szFormat, ...)
{
  va_list args;
  va_start(args, szFormat);
  VWrite(LEVEL_INFO, szFormat, args);
  va_end(args);
}

void SerialLog::Debug(const char *szFormat, ...)
{
  va_list args;
  va_start(args, szFormat);
  VWrite(LEVEL_DEBUG, szFormat, args);
  va_end(args);
}

void SerialLog::Trace(const char *szFormat, ...)
{
  va_list args;
  va_start(args, szFormat);
  VWrite(LEVEL_TRACE, szFormat, args);
  va_end(args);
}
