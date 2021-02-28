// Copyright 2021 me

#include "..\include\Employee.h"


void Employee::setPayment(int pay) { payment = pay; }

void Employee::setWorkTime(int workTime) { worktime = workTime; }

int Employee::getWorkTime() { return worktime; }

int Employee::getPayment() {
  calc();
  return payment;
}

std::string Employee::getPosition() { 
    switch (position) {
    case static_cast<Position>(0):
        return std::string("engineer");
    case static_cast<Position>(1):
      return std::string("programmer");
    case static_cast<Position>(2):
      return std::string("tester");
    case static_cast<Position>(3):
      return std::string("team leader");
    case static_cast<Position>(4):
      return std::string("project manager");
    case static_cast<Position>(5):
      return std::string("senior manager");
    case static_cast<Position>(6):
      return std::string("driver");
    case static_cast<Position>(7):
      return std::string("cleaner");
  }
}

std::string Employee::getName() { return name; }

unsigned Employee::getId() { return id; }
