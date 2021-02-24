// Copyright 2021 Dev-will-work
#include <iostream>
#include "Interfaces.h"
#include "Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"
#include <random>

int main() {
  StaffFactory sf;
  std::random_device rd;
  std::vector<Employee*> staff = sf.makeStaff();

  // working time assignment
  for (Employee* emp : staff) {
     emp -> setWorkTime(30 + rd() % 20);
  }

  // salary calculation
  for (Employee* emp : staff) {
     emp -> calc();
  }

  // employees data visualisation
  for (Employee* emp : staff) {
     emp -> printInfo();
  }

  // free memory
  for (Employee* emp : staff) {
     delete emp;
  }
}
