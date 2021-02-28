// Copyright 2021 Schenikova

#include "Manager.h"
#include "Factory.h"
#include "Engineer.h"
#include <string>

int main() {
  StaffFactory sf;
  std::vector <Employee *> staff = sf.makeStaff("../input.txt");
  for (Employee * emp : staff) {
    emp->setWorkTime(40);
  }
  for (Employee * emp : staff) {
    emp->calc();
  }
  for (Employee * emp : staff) {
    emp->printInfo();
  }
  return 0;
}

