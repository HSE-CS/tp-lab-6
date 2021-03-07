// Copyright 2021 Dumarevskaya
#include "Employee.h"
#include <iostream>

void Employee::setWorkTime(int wtime) {
  worktime = wtime;
}

Position Employee::getPosition() {
  return position;
}

std::string Employee::getId() {
  return id;
}

std::string Employee::getName() {
  return name;
}

void Employee::printInfo() {
  std::cout << "id: " << getId() << "\nname: "
    << getName() << "\nPosition: " << getPosition()
    << "\nWorktime: " << worktime << "\nPayment: " << payment
    << std::endl;
}