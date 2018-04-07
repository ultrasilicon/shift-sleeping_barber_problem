#include "log.h"
#include "barbershop.h"
#include "customer.h"


int current_id = 0;

int main(int argc, char *argv[])
{
  if(argc < 2)
    {
      Log::printLine(Log::Fatal, "Fatal Error: no input value");
      Log::printLine(Log::Info, "Usage: " + std::string(argv[0]) + " [number of seats]");
      return 1;
    }

  BarberShop shop(atoi(argv[1]));
  shop.run();

  while(true)
    {
      std::this_thread::sleep_for(std::chrono::seconds(3));
      shop.addCustomer(++ current_id);
    }
}
