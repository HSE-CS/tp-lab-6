// Copyright 2021 Dev-will-work
#include "Employee.h"

Employee::Employee() {
}

Employee::~Employee() {
}

void Employee::setWorkTime(int wtime) {
  this->worktime = wtime;
}

uint64_t Employee::createId() {
  static uint64_t s_id = 0;
  return s_id++;
}

Position Employee::getPosition() {
  return this->position;
}

int Employee::getPayment() {
  return this->payment;
}

void Employee::setSubordCount(size_t subord_count) {
  this->subordinates_count = subord_count;
}
