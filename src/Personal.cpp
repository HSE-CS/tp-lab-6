// Copyright 2020 GHA Test Team
#include "Personal.h"
#include <iostream>


void Personal::initializeParamsByZero() {
  id = worktime = payment = salary = 0;
  name = "";
}

int Personal::calcBase(int salary, int wtime) const {
  return salary * wtime;
}

void Personal::printInfo() const {
  std::cout << "Position: " << getPosition() << std::endl;
  std::cout << "Id: " << id << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Work time: " << worktime << std::endl;
  std::cout << "Payment: " << payment << std::endl;
}

int Cleaner::calcBonus() const {
  return 0;
}

void Cleaner::calc() {
  payment = calcBase(salary, worktime) + calcBonus();
}

Cleaner::Cleaner() {
  initializeParamsByZero();
  position = Position::CLEANER;
}

Cleaner::Cleaner(int id, std::string name, int salary) {
  this->id = id;
  this->name = name;
  this->salary = salary;
  worktime, payment = 0;
  position = Position::CLEANER;
}

int Driver::calcBonus() const {
  return 200 * worktime;
}

void Driver::calc() {
  payment = calcBase(salary, worktime) + calcBonus();
}

void Driver::printInfo() const {
  Personal::printInfo();
  std::cout << "Bonus: " << calcBonus() << std::endl;
}

Driver::Driver() {
  initializeParamsByZero();
  position = Position::DRIVER;
}

Driver::Driver(int id, std::string name, int salary) {
  this->id = id;
  this->name = name;
  this->salary = salary;
  worktime, payment = 0;
  position = Position::DRIVER;
}
