// Copyright 2020 S. BOR

#include "Personal.h"

void Personal::setSalary(unsigned salary) {
  this->salary = salary;
}

unsigned Personal::calcBase() {
  return salary * worktime;
}

void Personal::printInfo() {
  this->calc();
  std::cout << this->name << " " << this->position << " " << this->payment
  << std::endl;
}

void Cleaner::calc() {
  payment = calcBase();
}

unsigned Cleaner::calcBonus(unsigned overtimeJob, unsigned cost) {
  return 0;
}

unsigned Driver::calcBonus(unsigned overtimeJob, unsigned cost) {
  return overtimeJob * cost;
}

void Driver::calc() {
  payment = calcBase() + calcBonus(5, 10);
}
