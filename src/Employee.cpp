#include "Employee.h"

#include <iostream>

void Employee::printInfo() {
  std::cout << "NAME: " << name << std::endl
            << "WORKTIME: " << worktime << std::endl
            << "PAYMENT: " << payment << std::endl;
}

Employee::Employee(const uint32_t& id, const std::string& firstname,
                   const std::string& surname) {
  this->id = id;
  this->name = firstname + " " + surname;
}
