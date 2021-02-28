// Copyright 2021 ArinaMonicheva

#include "Employee.h"

Employee::Employee(int id, std::string name,
 std::string position, double payment) {
  this->id = id;
  this->name = name;
  this->position = position;
  this->payment = payment;
  this->workTime = 0;
}

int Employee::getId() {
  return id;
}

std::string Employee::getName() {
  return name;
}

std::string Employee::getPosition() {
  return position;
}

double Employee::getWorkTime() {
  return workTime;
}

double Employee::getPayment() {
  return payment;
}

void Employee::updateWorkTime(double currentTime) {
  workTime += currentTime;
}
