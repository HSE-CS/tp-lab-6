// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 08.02.2021.
//

#include <iostream>

#include "Employee.h"
#include "Factory.h"

int main() {
  auto staff = StaffFactory::make_staff("staff.txt");

  for (auto e : staff) {
    e->set_worktime((unsigned) rand() % 96 + 1);
  }

  for (auto e : staff) {
    e->calc();
  }

  for (auto e : staff) {
    e->print_info();
    std::cout << std::endl;
  }

  return 0;
}
