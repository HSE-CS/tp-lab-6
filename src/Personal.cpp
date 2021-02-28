// Copyright 2021 mkhorosh

#include "Personal.h"
#include <iostream>

int Personal::getSalary() {
  salary = payment + calcBonus();
  return salary;
}

int Personal::calcBase(int current_salary, int current_work_time) {
  return current_salary * current_work_time;
}

void Personal::calc() {
  payment = getPayment() * getWorkTime();
}
void Personal::printInfo() {
  std::cout << "id: " << getId() << "\n"
            << "name: " << getName() << "\nPosition: " << getPosition()
            << "\nWorktime: " << getWorkTime() << "\nPayment: " << getPayment()
            << std::endl;
}

int Driver::calcBase(int current_salary, int current_work_time) {
  return Personal::calcBase(current_salary, current_work_time);
}

int Driver::calcBonus() {
  return int(getPayment() * getWorkTime() * 0.5);
}

int Cleaner::calcBonus() {
  return int(calcBase(salary, work_time) * 0.5);
}
