#ifndef GLOBAL_H
#define GLOBAL_H

#include <thread>
#include <mutex>
#include <condition_variable>

class Global
{
public:
//  static int
  static std::condition_variable cv;
  static std::mutex cv_mutex;

};

#endif // GLOBAL_H
