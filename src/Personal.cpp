// Copyright 2021 by Bodrov Egor

#include <iostream>
#include "Personal.h"

Personal::Personal(int id, int salaryPerHour, std::string name, std::string pos)
    : Employee(id, std::move(name), std::move(pos)),
      salaryPerHour{salaryPerHour} {}

int Personal::calcBase(int salaryPerHour, int worktime) {
  return salaryPerHour * worktime;
}

int Personal::calcBonus() { return 0; }

void Personal::printInfo() {
  std::cout << "Name: " << this->getName() << '\n'
            << "Position: " << this->getPos() << '\n'
            << "Worktime: " << this->getWorkTime() << '\n'
            << "Salary per hour: " << salaryPerHour << '\n'
            << "Payment (with bonuses): " << this->getPayment() << '\n';
}

void Personal::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(salaryPerHour, this->getWorkTime()));
}

Driver::Driver(int id, int salaryPerHour, std::string name)
    : Personal(id, salaryPerHour, std::move(name), "Driver") {}

int Driver::calcBonus() {
  int overtime = this->getWorkTime() - 40;
  if (overtime > 0) {
    return (salaryPerHour * overtime) * 1.5;
  } else {
    return 0;
  }
}

void Driver::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(salaryPerHour, this->getWorkTime()) + calcBonus());
}

Cleaner::Cleaner(int id, int salaryPerHour, std::string name)
    : Personal(id, salaryPerHour, std::move(name), "Cleaner") {}

int Cleaner::calcBonus() {
  int overtime = this->getWorkTime() - 40;
  if (overtime > 0) {
    return (salaryPerHour * overtime) * 1.3;
  } else {
    return 0;
  }
}

void Cleaner::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(salaryPerHour, this->getWorkTime()) + calcBonus());
}
