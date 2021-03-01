// Copyright 2021 Ryzhova Irina

#include "Employee.h"

Employee::Employee(int payment, std::string name,
                   std::string position, int id) {
  this->id = id;
  this->name = name;
  this->position = position;
  this->payment = payment;
}

void Employee::setWorktime(int worktime) {
  this->worktime = worktime;
}

int Employee::getId() {
  return id;
}

std::string Employee::getName() {
  return name;
}

int Employee::getPayment() {
  return payment;
}

int Employee::getWorktime() {
  return worktime;
}

std::string Employee::getPosition() {
  return position;
}
