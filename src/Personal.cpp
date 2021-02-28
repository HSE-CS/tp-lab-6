// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#include <utility>
#include "Personal.h"
const char *enum_print[] = {"cleaner",
                            "driver",
                            "tester",
                            "programmer",
                            "team_leader",
                            "project_manager",
                            "senior_manager"};
Personal::Personal(int id, std::string name,
                   int workTime, int salary, Positions position)
    : Employee(id, std::move(name), workTime, position) {
  this->salary = salary;
}

int Personal::calcBase(int salaryValue, int workTimeValue) {
  return workTimeValue * salaryValue;
}
int Personal::calcBonus(int bonus) {
  return bonus * this->salary;
}

void Personal::printInfo() {
  std::cout << enum_print[this->position] << std::endl;
  std::cout << this->name << std::endl;
  std::cout << "Work time = " << this->workTime << std::endl;
  std::cout << "Payment = " << this->payment << std::endl;
}

Driver::Driver(int id, std::string name,
               int workTime, int salary, Positions position) :
    Personal(id, std::move(name), workTime, salary, position) {
}

int Driver::calc() {
  return this->payment = calcBase(salary, workTime) + calcBonus();
}
int Driver::calcBonus(int bonus) {
  return bonus * salary;
}

int Cleaner::calc() {
  return this->payment = calcBase(salary, workTime);
}
Cleaner::Cleaner(int id, std::string name,
                 int workTime, int salary, Positions position)
    : Personal(id, std::move(name), workTime, salary, position) {
}



