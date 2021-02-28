// Copyright 2020 S. BOR
#include "Employee.h"

unsigned Employee::getPayment() {
  calc();
  return payment;
}

void Employee::setWorkTime(unsigned worktime) {
  this->worktime = worktime;
}
