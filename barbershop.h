#ifndef BARBERSHOP_H
#define BARBERSHOP_H

#include <list>
#include "customer.h"
#include "global.h"

class BarberShop
{
public:
  BarberShop(const int &seats);
  void run();
  void addCustomer(const int &id);

  void printStat();

private:
  std::thread *barber_thread;
  void startBarber();
  std::list<Customer *> waiting_room;
  std::mutex waiting_room_lock;
  int max_seats;
};

#endif // BARBERSHOP_H
