// Copyright 2021 Dev-will-work
#include "Personal.h"

Personal::Personal() {
}

Personal::~Personal() {
}

int Personal::calcBase(int salary, int wtime) {
  return wtime * salary;
}

int Personal::calcBonus() {
  return 0;
}

Driver::Driver(int salary, std::string fio, Position pos) {
  this->salary = salary;
  this->name = fio;
  this->position = pos;
  this->id = createId();
}

Driver::~Driver() {
}

void Driver::printInfo() {
  std::cout << "Driver "<< this->name << " :\n";
  std::cout << "Id: "<< this->id << "\n";
  std::cout << "Working hours: "<< this->worktime << "\n";
  std::cout << "Payment: "<< this->payment << "\n\n\n";
}

int Driver::calcBonus() {
  return 0.25 * worktime * salary;
}

void Driver::calc() {
  this->payment = calcBase(this->salary, this->worktime);
  this->payment += this->calcBonus();
}

Cleaner::Cleaner(int salary, std::string fio, Position pos) {
  this->salary = salary;
  this->name = fio;
  this->position = pos;
  this->id = createId();
}

Cleaner::~Cleaner() {
}

void Cleaner::calc() {
  this->payment = calcBase(this->salary, this->worktime);
}

void Cleaner::printInfo() {
  std::cout << "Cleaner "<< this->name << " :\n";
  std::cout << "Id: "<< this->id << "\n";
  std::cout << "Working hours: "<< this->worktime << "\n";
  std::cout << "Payment: "<< this->payment << "\n\n\n";
}














