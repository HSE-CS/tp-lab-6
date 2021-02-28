// Copyright 27.02.21 DenisKabanov

#include "Employee.h"

Employee::Employee(unsigned int id, std::string name) {
  this->id = id;
  this->name = name;
}

void Employee::setWorkTime(int worktime) {
  this->worktime = worktime;
}

void Employee::setPayment(int payment) {
  this->payment = payment; 
}

int Employee::getID() {
  return this->id;
}

std::string Employee::getName() {
  return this->name;
}


int Employee::getWorkTime() {
  return this->worktime;
}

int Employee::getPayment() {
  return this->payment;
}

post Employee::getPos() {
  return this->position;
}