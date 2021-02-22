// Copyright 2021 LongaBonga
#include "Personal.h"

int Personal::calcBase(int payment, int wtime) { return payment * wtime; }

int Personal::calcBonus() { return 0; }

int Personal::getSalary() { return salary; }

int Personal::calc() {
  salary = calcBase(payment, worktime) + calcBonus();
  return salary;
}
void Personal::printInfo() {
  std::cout << "Employee fields: \n";
  std::cout << "\t"
            << "Id: " << getId() << '\n';
  std::cout << "\t"
            << "Name: " << getName() << '\n';
  std::cout << "\t"
            << "Position: " << getPosition() << '\n';
  std::cout << "\t"
            << "Work time: " << getWorktime() << '\n';
  std::cout << "\t"
            << "Salary: " << getSalary() << '\n';
}

int Driver::calcBonus() {
  if (getWorktime() > 42)
    return payment * 1.5;
  else
    return 0;
}
