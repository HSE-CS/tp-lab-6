// Copyright 2021 Lab_6 TiNa
#include "Employee.h"
#include "Factory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
  Factory file("staff.txt");
  std::vector<Personal*> staff = file.makeStaff();
  Personal* pers;
  for (int i = 0; i < staff.size(); i++) {
    staff[i]->calc();
    pers = staff[i];
    std::cout << i+1 << ":" << std::endl;
    pers->printInfo();
    std::cout << std::endl;
  }

    return 0;
}
