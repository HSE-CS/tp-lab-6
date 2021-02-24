// Copyright 2021 Smirnov Grigory
#include "Employee.h"
#include "Personal.h"

int Personal::getSalary() {
  return salary;
}

int Personal::calcBase(int salary, int wtime) {
  return salary * wtime;
}

void Cleaner::calc() {
  setPayment(calcBase(getSalary(), getWorkTime()));
}

int Driver::calcBonus() {
  if (getWorkTime() > 100)
    return 5000;
  else
    return 0;
}

void Driver::calc() {
  setPayment(calcBase(getSalary(), getWorkTime()) 
    + calcBonus());
}

void Personal::printInfo() {
  std::cout << getName() +" " + std::to_string(getId())
    + " " + std::to_string(getPayment());
}

int Personal::calcBonus() {
  return 0;
}
