// Copyright DB 2021

#include <random>
#include "Employee.h"
#include "Factory.h"

int main() {
  std::vector<Employee*> staff = StaffFactory::makeStaff();

  std::minstd_rand simple_rand;
  simple_rand.seed(42);

  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }

  for (auto emp : staff) {
    emp->calc();
  }

  for (auto emp : staff) {
    emp->printInfo();
  }
  return 0;
}