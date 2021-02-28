// Copyright 2021 Schenikova

#include "Employee.h"

void Employee::setWorkTime(unsigned int worktime) {
    this->worktime = worktime;
}

int Employee::getPayment() {
  calc();
  return payment;
}

