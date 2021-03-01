// Copyright 2021 Egor Trukhin
#include "Personal.h"

#include <cmath>
#include <iomanip>
#include <iostream>

//===================================================================================
// Personal

Personal::Personal(uint32_t id, const std::string& name, uint32_t salary)
    : Employee(id, name) {
  this->salary = salary;
}

uint32_t Personal::calcBase(uint32_t salary, uint32_t worktime) {
  return salary * worktime;
}

void Personal::printInfo() {
  Employee::printId();
  if (this->position == position_t::DRIVER)
    std::cout << std::setw(20) << "Driver";
  else
    std::cout << std::setw(20) << "Cleaner";
  std::cout << " |";
  std::cout << std::setw(8) << std::to_string(this->salary) << " |";
  Employee::printInfo();
  std::cout << std::endl;
}

//===================================================================================
// Cleaner

Cleaner::Cleaner(uint32_t id, const std::string& name, uint32_t salary)
    : Personal(id, name, salary) {
  this->position = position_t::CLEANER;
}

uint32_t Cleaner::calcBonus() { return 0; }

void Cleaner::calc() { this->payment = calcBase(this->salary, this->worktime); }

//===================================================================================
// Driver

Driver::Driver(uint32_t id, const std::string& name, uint32_t salary)
    : Personal(id, name, salary) {
  this->position = position_t::DRIVER;
}

void Driver::calc() {
  this->payment = calcBase(this->salary, this->worktime) + calcBonus();
}

uint32_t Driver::calcBonus() {
  return static_cast<uint32_t>(this->worktime * 500);
}
