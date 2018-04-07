#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "global.h"
#include "log.h"
#include <functional>


class Customer
{
public:
  Customer(const int &id);
  ~Customer();

  void welcome();
  int getId();

private:
  bool quit = false;
  std::condition_variable cv;
  std::mutex mutex;
  int id;
  void waitToBeShaved();
  std::thread *thread;
  int shave_time;
};

#endif // CUSTOMER_H
