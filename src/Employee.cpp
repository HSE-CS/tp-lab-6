// Copyright 2021 Ksuvot
#include "Employee.h"

int Employee::getId() {
  return id;
}

int Employee::getPayment() {
  return payment;
}

int Employee::getWorktime() {
  return worktime;
}

Position Employee::getPosition() {
  return position;
}

std::string Employee::getName() {
  return name;
}

void Employee::setId(int id) {
  this->id = id;
}

void Employee::setPayment(int payment) {
  this->payment = payment;
}

void Employee::setWorktime(int worktime) {
  this->worktime = worktime;
}

void Employee::setName(std::string name) {
  this->name = name;
}

void Employee::setPosition(Position position) {
  this->position = position;
}
