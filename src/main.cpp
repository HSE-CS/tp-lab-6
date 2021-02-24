// Copyright 2021 Smirnov Grigory
#include "Factory.h"
int main() {
  std::string n = "Glasha";
  Cleaner c(156, n, 130);
  c.printInfo();
  c.setWorkTime(150);
  c.calc();
  std::cout << " " << c.getPos() << " " << c.getPayment();
  Employee* e = new Driver(146, n, 30);
  // std::cout << dynamic_cast<Cleaner*>(e)->getPos();
  // std::cout << e->getPos();
}