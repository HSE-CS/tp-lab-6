// Copyright 2020 Polina Lukicheva
#include "Employee.h"

Employee::Employee(int id, std::string name, std::string position,
  int workTime, int payment) {
  this->id = id;
  this->name = name;
  this->position = position;
  this->workTime = workTime;
  this->payment = payment;
}

void Employee::setWorkTime(int workTime) {
  this->workTime = workTime;
}

std::string Employee::getPosition() const {
  return position;
}

int Employee::getWorkTime() const {
  return workTime;
}

int Employee::getId() const {
  return id;
}

std::string Employee::getName() const {
  return name;
}

int Employee::getPayment() const {
  return payment;
}
