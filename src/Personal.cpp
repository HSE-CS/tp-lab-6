// Copyright 2021 Lab_6 TiNa
#include "Personal.h"
#include <iostream>
#include <string>

int Personal::calcBase(int hour_salary, int work_time) {
  return (hour_salary * work_time);
}

int Personal::calc() {
  salary = calcBase(payment, worktime) + calcBonus();
  return salary;
}

int Personal::calcBonus() { return floor(getPayment() * getWorktime() * 0.3); }

int Personal::getSalary() { return salary; }

void Personal::setSalary(int salary) { this->salary = salary; }

void Personal::printInfo() {
  std::cout << "Info:" << std::endl;
  std::cout << "Id:\t" << getId() << std::endl;
  std::cout << "Name:\t" << getName() << std::endl;
  std::cout << "Position:\t" << getPosition() << std::endl;
  std::cout << "Work time:\t" << getWorktime() << std::endl;
  std::cout << "Salary:\t" << getSalary() << std::endl;
}

int Driver::calcBonus() {
  if (getWorktime() > 30) {
    return (calcBase(getPayment(), getWorktime()) * 0.1);
  } else {
    return 0;
  }
}
