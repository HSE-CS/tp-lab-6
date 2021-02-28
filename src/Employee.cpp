// Copyright 2021 Schenikova

#include "Employee.h"

void Employee::setWorkTime(unsigned int worktime) {
    this->worktime = worktime;
}

int Employee::getPayment() {
  calc();
  return payment;
}

void Employee::setId(int id) {
  this->id = id;
}

void Employee::setName(std::string name) {
  this->name = name;
}

void Employee::setPosition(Position position) {
  this->position = position;
}

