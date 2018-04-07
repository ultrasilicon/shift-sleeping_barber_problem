#include "barbershop.h"

BarberShop::BarberShop(const int &seats)
  : max_seats(seats)
{
}

void BarberShop::run()
{
  barber_thread = new std::thread(std::bind(&BarberShop::startBarber, this));
}

void BarberShop::addCustomer(const int &id)
{
  Customer *c = new Customer(id);

  //! not equal ("waiting_room.size() >= max_seats"), because my algorithm includes the people being shaved in the queue
  //! because std::list automatically call destructor after invoke pop_front().
  if(waiting_room.size() > max_seats)
    {
      Log::printLine(Log::Info, "Waiting Room Full");
      delete c;
    }
  else
    {
      waiting_room.push_back(c);
    }
  printStat();
}


void BarberShop::startBarber()
{
  while (true)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      if(waiting_room.size() > 0)
        {
          waiting_room.front()->welcome();
          Log::printLine(Log::Info, std::string("Customer ") + std::to_string(waiting_room.front()->getId()) + std::string(" leaving"));
          delete waiting_room.front();
          waiting_room.pop_front();
          printStat();
        }
      else
        {
          printStat();
          while (waiting_room.size() == 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
          continue;
        }
    }
}


void BarberShop::printStat()
{
  if(waiting_room.size() == 0)
      Log::printLine(Log::Info, "Barber sleeping");
  else
      Log::printLine(Log::Info, std::string("Barber cutting the hair of customer: ") + std::to_string(waiting_room.front()->getId()));

  Log::print(Log::Info, "Waiting room:");
  bool first = true;
  for(Customer *c : waiting_room)
    {
      if(first)
        {
          first = !first;
          continue;
        }
      Log::print(Log::Info, std::string(" ") + std::to_string(c->getId()));
    }
  Log::print(Log::Info, "\n");
}
