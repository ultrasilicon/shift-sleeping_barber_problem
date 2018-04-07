#ifndef CUSTOMER_H
#define CUSTOMER_H

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

  int id;
  int shave_time;
  bool quit = false;
  std::condition_variable cv;
  std::mutex mutex;
  std::thread *thread;

  void waitToBeShaved();
};

#endif // CUSTOMER_H
