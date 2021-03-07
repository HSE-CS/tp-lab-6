// Copyright 2021 Dumarevskaya

#include "Employee.h"
#include "Factory.h"

int main() {
  std::vector<Employee*> staff = StaffFactory::makeStaff("data.txt");

  for (auto emp : staff) {
    emp->setWorkTime(10);
  }


  for (auto emp : staff) {
    emp->calc();
  }


  for (auto emp : staff) {
    emp->printInfo();
  }

  return 0;
}
