// Copyright 2021 Islam Osmanov

#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "Interfaces.h"
#include "Factory.h"
int main() {
    Employee* employee = new Cleaner(1, 750, "cleaner", "Islam");
    std::string name = employee->getName();
    employee->setWorkTime(45);
    Factory fc;
    Project* pro = new Project(1, 500000);
    std::vector<Employee*> emp = fc.create_staff("employees.csv");
    int size_project = emp.size() - 1;
    pro->addWorkers(size_project);
    for(auto empl : emp) {
       empl->calc();
       empl->printInfo();
    }
}
