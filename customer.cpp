#include "customer.h"

Customer::Customer(const int &id)
  : id(id)
{
  shave_time = 1 + rand() % 4;
  thread = new std::thread(std::bind(&Customer::waitToBeShaved, this));
}

Customer::~Customer()
{
  quit = true;
  cv.notify_one();
  delete thread;
}

void Customer::welcome()
{
  cv.notify_one();
  thread->join();
}

int Customer::getId()
{
  return id;
}

void Customer::waitToBeShaved()
{
  std::unique_lock<std::mutex> lk(mutex);
  cv.wait(lk);

  if(!quit)
    {
      std::this_thread::sleep_for(std::chrono::seconds(shave_time));
    }
}
