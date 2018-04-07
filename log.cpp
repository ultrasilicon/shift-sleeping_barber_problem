#include "log.h"

std::mutex Log::mutex;

void Log::printLine(const Log::LogLevel &level, std::string msg)
{
  while (!mutex.try_lock())
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  switch (level) {
    case Info:
      {
        std::cout << msg << std::endl;
        break;
      }
    case Error:
      {
        std::cerr << "\u001b[31m" << msg << "\u001b[0m" << std::endl;
        break;
      }
    case Fatal:
      {
        std::cerr << "\u001b[31m" << msg << "\u001b[0m" << std::endl;
        break;
      }
    default:
      {
        break;
      }
    }
  mutex.unlock();
}

void Log::print(const Log::LogLevel &level, std::string msg)
{
  while (!mutex.try_lock())
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  switch (level) {
    case Info:
      {
        std::cout << msg;
        break;
      }
    case Error:
      {
        std::cerr << "\u001b[31m" << msg << "\u001b[0m";
        break;
      }
    case Fatal:
      {
        std::cerr << "\u001b[31m" << msg << "\u001b[0m";
        break;
      }
    default:
      {
        break;
      }
    }
  mutex.unlock();
}
