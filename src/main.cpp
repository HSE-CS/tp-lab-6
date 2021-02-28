// Copyright 2021 Kuznetsov Mikhail

#include <vector>
#include <random>
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

int main() {
    StaffFactory factory;
    std::vector<Employee*> staff =
    factory.makeStaff("../data/Projects.txt", "../data/Employees.txt");
    for (auto e : staff) {
      e->setWorktime(std::rand() % 36 + 20);
      //  setting worktime in interval [20, 55]
    }

    for (auto e : staff) {
      e->calc();
      //  calculating income for every employee
    }

    for (auto e : staff) {
      e->printInfo();
      //  print information about employees
    }

    return 0;
}
