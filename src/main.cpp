// Copyright 2021 by Bodrov Egor

#include <iostream>
#include <fstream>
#include <string>
#include "Factory.h"

int main() {
  std::vector<Employee*> staff = FactoryWork::makeStaff();  
  int worktime[30];
  for (int i = 0; i < 30; i++) {
    worktime[i] = std::rand() % 15 + 36;
  }

  std::cout << "Generated worktime for each employee:\n";
  for (int el : worktime) {
    std::cout << el << ' ';
  }

  int k = 0;
  for (auto emp : staff) {
    emp->setWorkTime(worktime[k]);
    k++;
  }
  std::cout << std::endl;

  std::cout << "Relevant worktime for each employee:\n";
  for (auto emp : staff) {
    std::cout << emp->getWorkTime() << ' ';
  }
  std::cout << std::endl;

  for (auto emp : staff) {
    emp->calc();
  }

  std::cout << "Relevant payments for each employee:\n";
  for (auto emp : staff) {
    std::cout << emp->getPayment() << ' ';
  }
  std::cout << std::endl;

  std::cout << "Brief information:\n";
  for (auto emp : staff) {
    emp->printInfo();
    std::cout << "\n -------------- \n";
  }

  return 0;
}
