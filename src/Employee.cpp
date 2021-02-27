// Copyright 2021 Pavlova D.

#include "Employee.h"

int Employee::getId() const { return this->id; }

std::string Employee::getName() { return this->name; }

Position Employee::getPosition() { return this->position; }

void Employee::setWorkTime(int wTime) { this->worktime = wTime; }

void Employee::calc() { payment = worktime * salary; }

void Employee::printInfo() {
  std::cout << "id: " << getId() << "\n"
            << "name: " << getName() << "\nPosition: " << getPosition()
            << "\nWorktime: " << worktime << "\nPayment: " << payment
            << std::endl;
}
