#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>
#include <mutex>
#include <thread>

class Log
{
public:
  enum LogLevel{
    Info = 0,
    Error = 3,
    Fatal = 4,
  };

  static void printLine(const LogLevel &level, std::string msg);
  static void print(const LogLevel &level, std::string msg);

private:
  static std::mutex mutex;
};

#endif // LOG_H
