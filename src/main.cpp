//  Copyright 2021 GHA created by Klykov Anton

#include "Employee.h"
#include "Factory.h"

int main() {
  StaffFactory staff_factory;
  std::vector<Employee*> staff = staff_factory.getStaff();
  for (int i = 0; i < staff.size(); ++i) {
    staff[i]->setWorkTime();
  }
  for (int i = 0; i < staff.size(); ++i) {
    staff[i]->calc();
  }
  for (int i = 0; i < staff.size(); ++i) {
      staff[i]->printinfo();
  }
  return 0;
}

