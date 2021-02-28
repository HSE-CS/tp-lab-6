// Copyright 2020 GHA Test Team
#include "Employee.h"
#include "Factory.h"


int main() {
  StaffFactory* staff_factory = new StaffFactory("staff.txt");
  std::vector<Employee*> staff = staff_factory->makeStaff();
  for (Employee* emp : staff) {
    emp->setWorkTime(10 + std::rand() % 50);
    emp->calc();
    emp->printInfo();
    std::cout << std::endl;
  }
  return 0;
}
