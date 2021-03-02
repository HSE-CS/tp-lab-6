// Copyright 2021 Shirokov Alexander
#include <utility>
#include <iostream> 
#include "Personal.h"

Personal::Personal(int id, int salaryPerHour, std::string name, Position position) 
: Employee(id, std::move(name), position), salaryPerHour{ salaryPerHour } {}

int Personal::calcBase(int salaryPerHour, int workTime) {
  return salaryPerHour * workTime;
}

int Personal::calcBonus() {
  return 0;
}

void Personal::calc() {
  this->payment = this->payment + calcBase(salaryPerHour, workTime);
}

void Personal::printInfo() {
  std::cout << this->id << " " << this->name << " " << this->payment << " " 
  << this->salaryPerHour << " " 
  << static_cast<std::underlying_type<Position>::type>(this->position);
}

Cleaner::Cleaner(int id, int salaryPerHour, std::string name, Position position)
: Personal(id, salaryPerHour, std::move(name), position) {}

void Cleaner::calc() {
  this->payment = calcBase(this->salaryPerHour, this->workTime);
}

int Cleaner::calcBonus() {
  return 200;
}

Driver::Driver(int id, int salaryPerHour, std::string name, Position position) 
  : Personal(id, salaryPerHour, std::move(name), position) {}

void Driver::calc() {
  this->payment = calcBase(this->salaryPerHour, this->workTime) + calcBonus();
}

int Driver::calcBonus() {
  return 300;
}
