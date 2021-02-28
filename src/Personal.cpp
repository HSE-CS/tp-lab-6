// Copyright 2021 ArinaMonicheva

#include "Personal.h"

Personal::Personal(int id, std::string name, std::string position,
 double payment) : Employee(id, name, position, payment) {
  salary = 0;
}

double Personal::calcBase() {
  salary = getWorkTime() * getPayment();
  return salary;
}

double Personal::getSalary() {
  return salary;
}

Driver::Driver(int id, std::string name, std::string position,
 double payment) : Personal(id, name, position, payment) {
}

double Driver::calcBonus() {
  if (getWorkTime() >= 24.0) {
    return getWorkTime() * 0.25 * getPayment();
  }
  return 0;
}

double Driver::calc() {
  return calcBase() + calcBonus();
}

void Driver::printInfo() {
  std::string info;
  info = std::to_string(getId()) + " " +
    getName() + "\nPosition: " + getPosition() +
    "\nPayment: " + std::to_string(getPayment()) +
    "\nFixed salary: " + std::to_string(getSalary()) +
    "\nCurrent bonus: " + std::to_string(calcBonus()) +
    " (current work time: " + std::to_string(getWorkTime()) + ")";
  std::cout << info << std::endl;
}

Cleaner::Cleaner(int id, std::string name, std::string position,
 double payment) : Personal(id, name, position, payment) {
}

double Cleaner::calc() {
  return calcBase();
}

void Cleaner::printInfo() {
  std::string info;
  info = std::to_string(getId()) + " " +
    getName() + "\nPosition: " + getPosition() +
    "\nPayment: " + std::to_string(getPayment()) +
    "\nSalary: " + std::to_string(getSalary()) +
    " (current work time: " + std::to_string(getWorkTime()) + ")";
  std::cout << info << std::endl;
}

double Cleaner::calcBonus() {
  return 0;
}
