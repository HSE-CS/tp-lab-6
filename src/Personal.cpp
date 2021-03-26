// Copyright 2020 Uskova

#include "Personal.h"

Personal::Personal(int id, std::string name, Position pos, int wtime,
                   int salary)
    : Employee(id, name, pos, wtime) {
  this->salary = salary;
  this->payment = 0;
}

int Personal::calcBase(int salary, int wtime) {
    return salary * wtime;
}

Driver::Driver(int id, std::string name, Position pos, int wtime, int salary,
               int time)
    : Personal(id, name, pos, wtime, salary) {
  this->extraTime = 0;
  this->payment = 0;
  this->extraTime = time;
}

int Driver::calcBonus() {
    return this->salary * this->extraTime * 2;
}

void Driver::calc() {
  this->payment = (calcBase(this->salary, this->worktime) + calcBonus());
}

int Driver::getExtraTime() {
    return this->extraTime;
}

void Driver::printinfo() {
  std::cout << std::endl;
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Id: " << this->id << std::endl;
  std::cout << "Position: " << getStrPosition() << std::endl;
  std::cout << "Main worktime: " << this->worktime << std::endl;
  std::cout << "Extra hours: " << this->extraTime << std::endl;
  std::cout << "Salary per hour: " << this->salary << std::endl;
  std::cout << "Payment: " << this->payment << std::endl;
  std::cout << std::endl;
}

Cleaner::Cleaner(int id, std::string name, Position pos, int wtime, int salary)
    : Personal(id, name, pos, wtime, salary) {
  this->payment = 0;
}

void Cleaner::calc() {
  this->payment = calcBase(this->salary, this->worktime) + calcBonus();
}

int Cleaner::calcBonus() {
    return 0;
}

void Cleaner::printinfo() {
  std::cout << std::endl;
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Id: " << this->id << std::endl;
  std::cout << "Position: " << getStrPosition() << std::endl;
  std::cout << "Worktime: " << this->worktime << std::endl;
  std::cout << "Salary per hour: " << this->salary << std::endl;
  std::cout << "Payment: " << this->payment << std::endl;
  std::cout << std::endl;
}
