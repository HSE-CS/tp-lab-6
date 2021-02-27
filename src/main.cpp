// Copyright 2021 Andrey Bakurskii


#include <string>
#include <iostream>

#include "Personal.h"
#include "Employee.h"
#include "Factory.h"
#include "Manager.h"
#include "Engineer.h"


int main() {
  Factory factory(
      std::string("projects_data.txt"),
      std::string("employees.txt"));

  factory.makeProjects();
  factory.makeStaff();

  for (size_t i = 0; i < factory.employees.size(); i++) {
    std::cout << i << " "
              << factory.employees[i]->getPosition() << " "
              << factory.employees[i]->calc() << "\n";
  }
  return 0;
}
