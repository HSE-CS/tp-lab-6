// Copyright 2021 alexgiving

#include "Employee.h"

// Set functions

void Employee::setId(size_t _id) {
  this->id = _id;
}

void Employee::setName(std::string _name) {
  this->name = std::move(_name);
}

void Employee::setPosition(std::string _position) {
  this->position = std::move(_position);
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

std::string Employee::getPosition() {
  return this->position;
}

size_t Employee::getWorktime() const {
  return this->worktime;
}

size_t Employee::getPayment() const {
  return this->payment;
}
