// Copyright 2021 Shirokov Alexander
#include <iostream>
#include <fstream>
#include <string>
#include "Factory.h"

int main() {
  std::vector<Employee*> staff = FactoryWork::makeStaff();
  for (Employee* emp : staff)
    emp->setWorkTime(std::rand() % 50);
  for (Employee* emp : staff)
    emp->calc();
  for (Employee* emp : staff)
    emp->printInfo();
   return 0;
}
