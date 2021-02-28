// Copyright 2021 Egor Buzanov

#include <random>
#include <string>
#include <vector>

#include "Factory.h"

int main() {
  Factory factory;
  std::vector<Employee*> staff = factory.makeStaff("Projects.txt", "Staff.txt");

  std::random_device rd;
  std::mt19937 mersenne(rd());
  for (auto& emp : staff) {
    emp->setWorktime(mersenne() % 100);
  }

  for (auto& emp : staff) {
    emp->calc();
  }

  for (auto& emp : staff) {
    emp->printInfo();
  }

  return 0;
}
