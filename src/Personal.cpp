// Copyright 2021 Andrey Bakurskii

#include "Personal.h"

#include <string>
#include <iostream>

int Personal::calc() {
  return calcBase(getPayment(), getWorktime()) + calcBonus();
}

int Personal::calcBase(int p, int wt) { return p * wt; }

int Personal::calcBonus() {
  int p = getPayment();
  int wt = getWorktime();

  if (wt > 40) {
    int salary = static_cast<int>(p * wt * 0.3);
    return salary;
  }
  return 0;
}

void Personal::printInfo() {
  std::string info = "";

  info += "ID: " + std::to_string(getId()) + "\n";
  info += "Name: " + getName() + "\n";
  info += "Position: " + getPosition() + "\n";
  info += "Payment (per 1 hours): " + std::to_string(getPayment()) + "\n";
  info += "Worktime: " + std::to_string(getWorktime()) + "\n";
  info += "Salary: " + std::to_string(calc()) + "\n";

  std::cout << info;
}

int Cleaner::calc() {
    return Personal::calcBase(getPayment(), getWorktime()) + calcBonus();
}

int Cleaner::calcBonus() { return 0; }

void Cleaner::printInfo() {
  std::string info = "";

  info += "ID: " + std::to_string(getId()) + "\n";
  info += "Name: " + getName() + "\n";
  info += "Position: " + getPosition() + "\n";
  info += "Payment (per 1 hours): " + std::to_string(getPayment()) + "\n";
  info += "Worktime: " + std::to_string(getWorktime()) + "\n";
  info += "Salary: " + std::to_string(calc()) + "\n";

  std::cout << info;
}

int Driver::calc() {
  return Personal::calcBase(getPayment(), getWorktime()) + calcBonus();
}

int Driver::calcBonus() {
  int p = getPayment();
  int wt = getWorktime();

  if (wt > 40) {
    int salary = static_cast<int>(p * wt * 0.2);
    return salary;
  }
  return 0;
}

void Driver::printInfo() {
  std::string info = "";

  info += "ID: " + std::to_string(getId()) + "\n";
  info += "Name: " + getName() + "\n";
  info += "Position: " + getPosition() + "\n";
  info += "Payment (per 1 hours): " + std::to_string(getPayment()) + "\n";
  info += "Worktime: " + std::to_string(getWorktime()) + "\n";
  info += "Salary: " + std::to_string(calc()) + "\n";

  std::cout << info;
}
