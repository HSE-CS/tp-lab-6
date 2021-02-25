// Copyright NikDemoShow 2021
#include<iostream>
#include<sstream>
#include<string>
#include"Factory.h"

int main() {
  Factory F;
  std::vector<Employee*> staff = F.makeStaff("src/Personals.txt");
  for (Employee* emp : staff) {
    emp->setWorkTime();
  }
  for (Employee* emp : staff) {
    emp->calc();
  }
  for (Employee* emp : staff) {
    emp->printInfo();
  }
  return 0;
}