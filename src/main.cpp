#include<iostream>
#include<sstream>
#include<string>
#include"Factory.h"

int main() {
  Factory F;
  std::vector<Employee*> staff = F.makeStaff("ProgTech/Lab6/Personals.txt");
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