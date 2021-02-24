// Copyright 2021 Smirnov Grigory
#include "../include/Factory.h"
int main() {
  std::string n = "name";
  Driver c(0, n, 12);
  c.printInfo();
  std::cout << " " << c.getPos();
}