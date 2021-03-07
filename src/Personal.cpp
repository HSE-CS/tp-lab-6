// Copyright 2021 Dumarevskaya
#include "Personal.h"
#include <iostream>

int Personal::calcBase(int salary, int wtime) {
  return salary * wtime;
}

int Driver::calcBonus() {
  return 300;
}

int Cleaner::calcBonus() {
  return 0;
}

void Driver::calc() {
  payment = calcBase(salary, worktime) + calcBonus();
}

void Cleaner::calc() {
  payment = calcBase(salary, worktime);
}

void Personal::printInfo() {
  std::cout << "id: " << getId() << "\nname: "
    << getName() << "\nPosition: " << getPosition()
    << "\nWorktime: " << worktime << "\nPayment: " << payment
    << std::endl;
}
