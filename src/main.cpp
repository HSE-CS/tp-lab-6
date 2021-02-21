//// Copyright 2021 Ozhiganova Polina
#include <zconf.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "Factory.h"
#include "Employee.h"

int randomGener(int min, int max) {
  int range = max-min+1;
  return rand()%range + min;
}

int main() {
  //  WORK WITH FILE
  std::ifstream f(R"(C:\tp-lab-6\src\data\dataset.json)");
  if (!f.is_open()) {
    std::cout << "*** Error opening file ***";
    exit(1);
  }
  nlohmann::json jf = nlohmann::json::parse(f);
  f.close();
  //  PARSE DATA
  std::vector<Employee *> staff = Factory::makeStaff(jf);
  // WORK TIME
  for (Employee *emp : staff) {
    int hours = randomGener(20, 50);
    emp->setWorkTime(hours);
  }
  // SET SALARY
  for (Employee *emp : staff) {
    emp->calc();
  }
  // GET DATA
  for (Employee *emp : staff) {
    emp->printInfo();
  }
  return 0;
}
