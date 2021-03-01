// Copyright 2021 Tatsenko Ilya
#include <vector>

#include "Factory.h"
#include"Interfaces.h"

int main() {
  Factory factory;
  std::vector<Employee*> staff =
      factory.makeStaff("C:\\Users\\������\\Desktop\\instances\\projects.txt",
                        "C:\\Users\\������\\Desktop\\instances\\staff.txt");

  for (auto& emp : staff) {
    emp->calc();
  }

  for (auto& emp : staff) {
    emp->printInfo();
  }

  return 0;
}