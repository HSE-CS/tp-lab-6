// Copyright 2021 Egor Trukhin
#include "Employee.h"

#include <iomanip>
#include <iostream>

Employee::Employee(uint32_t id, std::string& name) {
  this->id = id;
  this->name = name;
  this->worktime = 0;
  this->payment = 0;
}

void Employee::setWorkTime(uint32_t time) { this->worktime = time; }

uint32_t Employee::getPayment() { return this->payment; }

void Employee::printId() {
  std::cout << std::setw(3) << std::to_string(this->id) << " |";
  std::cout << std::setw(35) << this->name << " |";
}

void Employee::printInfo() {
  std::cout << std::setw(4) << std::to_string(this->worktime) << " |";
  std::cout << std::setw(8) << std::to_string(this->payment) << " |";
}
