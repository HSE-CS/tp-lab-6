// Copyright 2021 TimurZaytsev
//

#include "Personal.h"

#include <iostream>

Personal::Personal(int id, int HourSalary, std::string name, std::string pos)
    : Employee(id, std::move(name), std::move(pos)),
      HourSalary{HourSalary} {}

int Personal::calcBase(int HourSalary, int worktime) {
  return HourSalary * worktime;
}

int Personal::calcBonus() { return 0; }

void Personal::printInfo() {
  std::cout << "Name: " << this->getName() << '\n'
            << "Position: " << this->getPos() << '\n'
            << "Worktime: " << this->getWorkTime() << '\n'
            << "Salary per hour: " << HourSalary << '\n'
            << "Payment (with bonuses): " << this->getPayment() << '\n';
}

void Personal::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(HourSalary, this->getWorkTime()));
}

Driver::Driver(int id, int HourSalary, std::string name)
    : Personal(id, HourSalary, std::move(name), "Driver") {}

int Driver::calcBonus() {
  int overtime = this->getWorkTime() - 40;
  if (overtime > 0) {
    return (HourSalary * overtime) * 1.5;
  } else {
    return 0;
  }
}

void Driver::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(HourSalary, this->getWorkTime()) + calcBonus());
}

Cleaner::Cleaner(int id, int HourSalary, std::string name)
    : Personal(id, HourSalary, std::move(name), "Cleaner") {}

int Cleaner::calcBonus() {
  int overtime = this->getWorkTime() - 40;
  if (overtime > 0) {
    return (HourSalary * overtime) * 1.3;
  } else {
    return 0;
  }
}

void Cleaner::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(HourSalary, this->getWorkTime()) + calcBonus());
}