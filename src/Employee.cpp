// Copyright 2020 Konina Tatiana
#include "Employee.h"
#include <string>
Employee::Employee(unsigned int id, std::string name,
                    int worktime, int position) {
  this->id = id;
  this->name = name;
  this->position = position;
  setWorkTime(worktime);
  this->payment = 0;
}

void Employee::setWorkTime(int worktime) {
  this->worktime = worktime;
}


std::string Employee::getName() const {
  return this->name;
}
double Employee::getPay() const {
  return this->payment;
}
int Employee::getWorktime() const {
  return this->worktime;
}


