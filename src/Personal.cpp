// Copyright 2021 Pavlova D.

#include "Personal.h"

int Personal::calcBase(int _salary, int _wtime) { return _salary * _wtime; }

void Personal::calc() { payment = calcBase(salary, worktime) + calcBonus(); }

void Personal::printInfo() {
  std::cout << "id: " << getId() << "\n"
            << "name: " << getName() << "\nPosition: " << getPosition()
            << "\nWorktime: " << worktime << "\nPayment: " << payment
            << std::endl;
}

int Driver::calcBonus() {
  return static_cast<int>(calcBase(salary, worktime) * 0.5);
}

int Cleaner::calcBonus() {
  return static_cast<int>(calcBase(salary, worktime) * 0.5);
}
