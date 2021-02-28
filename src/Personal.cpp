// Copyright 2020 me

#include "..\include\Personal.h"


int Personal::getSalary() { return salary; }

int Personal::calcBase(int salary, int wtime) { return salary * wtime; }

void Personal::printInfo() {
  std::cout << "Employee:\n";
  std::cout << "\tName: " << getName() << "\n";
  std::cout << "\tId: " << getId() << "\n";
  std::cout << "\tPosition: " << getPosition() << "\n";
  std::cout << "\tWork time: " << getWorkTime() << "\n";
  std::cout << "\tSalary: " << getSalary() << "\n";
  std::cout << "\tPayment: " << getPayment() << "\n";
}

int Personal::calcBonus() { return 0; }

int Driver::calcBonus() { return 2 * getSalary() * extraWorkTime; }

void Driver::calc() {
  setPayment(calcBase(getSalary(), getWorkTime()) + calcBonus());
}

void Driver::printInfo() {
  Personal::printInfo();
  std::cout << "\tExtra work time: " << extraWorkTime << "\n";
  std::cout << "\tBonus payment(included in payment): "
      << calcBonus() << "\n";
}

void Cleaner::calc() { setPayment(calcBase(getSalary(), getWorkTime())); }
