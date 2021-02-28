// Copyright 2021 mkhorosh

#include <iostream>
#include "Employee.h"

Employee::Employee(std::string id, std::string name, Position position, int work_time, int payment) {
  this->id = id;
  this->name = name;
  this->position = position;
  this->work_time = work_time;
  this->payment = payment;
}

std::string Employee::getId() const {
  return id;
}

std::string Employee::getName() const {
  return name;
}

Position Employee::getPosition() const {
  return position;
}

int Employee::getWorkTime() const {
  return work_time;
}

int Employee::getPayment() const {
  return payment;
}

void Employee::setWorkTime(int time) {
  work_time = time;
}

void Employee::calc() {
  payment = work_time/**salary*/;
}

void Employee::printInfo() {
  std::cout << "id: " << getId() << "\n"
            << "name: " << getName() << "\nposition: " << getPosition()
            << "\nwork_time: " << getWorkTime() << "\npayment: " << getPayment()
            << std::endl;
}
