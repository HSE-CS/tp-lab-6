// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#include "Factory.h"
int main() {
  std::vector < Employee * > staff = StaffFactory::makeStaff();
  for (auto emp : staff) {
    emp->calc();
  }
  for (auto emp : staff) {
    emp->printInfo();
  }
}




