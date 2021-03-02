// Copyright 2020 Polina Lukicheva
#include "Personal.h"
#include <iostream>

void Personal::setSalary(int salary) {
  this->salary = salary;
}

int Personal::getSalary() {
  return salary;
}

int Personal::calc() {
  salary = 0;
  return 0;
}

void Personal::printInfo() {
  std::cout << "{id=" + std::to_string(getId()) +
    ", name=" + getName() +
    ", position=" + getPosition() +
    ", payment=" + std::to_string(getPayment()) +
    ", salary" + std::to_string(getSalary()) + "}" << std::endl;
}

int Personal::calcBonus() {
  return 0;
}

int Personal::calcBase(int salary, int worktime) {
  return salary * worktime;
}

int Driver::calc() {
  setSalary(calcBase(getPayment(), getWorkTime()) + calcBonus());
  return getSalary();
}

int Driver::calcBase(int salary, int worktime) {
  return Personal::calcBase(salary, worktime);
}

void Driver::printInfo() {
  Personal::printInfo();
}

int Cleaner::calc() {
  setSalary(calcBase(getPayment(), getWorkTime()));
  return getSalary();
}

int Cleaner::calcBase(int salary, int worktime) {
  return Personal::calcBase(salary, worktime);
}

void Cleaner::printInfo() {
  Personal::printInfo();
}
