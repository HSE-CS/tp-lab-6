// Copyright 2021 alexgiving

#include "Employee.h"

// Set functions

void Employee::setId(size_t _id) {
  this->id = _id;
}

void Employee::setName(std::string _name) {
  this->name = std::move(_name);
}

void Employee::setPosition(size_t _position) {
  this->position = _position;
}

void Employee::setPayment(size_t _payment) {
  this->payment = _payment;
}

void Employee::setWorkTime(size_t _worktime) {
  this->worktime = _worktime;
}

// Get functions

size_t Employee::getId() const {
  return this->id;
}

std::string Employee::getName() {
  return this->name;
}

std::string Employee::getPosition() const {
  if (this->position == 0) return std::string("TEAM_LEADER");
  else if (this->position == 1) return std::string("SENIOR_MANAGER");
  else if (this->position == 2) return std::string("PROJECT_MANAGER");
  else if (this->position == 3) return std::string("PROGRAMMER");
  else if (this->position == 4) return std::string("TESTER");
  else if (this->position == 5) return std::string("ENGINEER");
  else if (this->position == 6) return std::string("DRIVER");
  else if (this->position == 7) return std::string("CLEANER");
  return std::string("NULL");
}

size_t Employee::getWorktime() const {
  return this->worktime;
}

size_t Employee::getPayment() const {
  return this->payment;
}
