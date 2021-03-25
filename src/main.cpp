// Copyright 2021 dash
#include <iostream>
#include <random>
#include <vector>
#include "Employee.h"
#include "Factory.h"
#include "Manager.h"
#include "Engineer.h"
#include "Personal.h"
#include "Interfaces.h"

int main() {
    Factory f;
    std::vector<Employee*> employees = f.createemployees
    ("Projects.txt", "People.txt");

    std::random_device rd;
    for (auto& emp : employees) {
        emp->set_Worktime(std::rand() % 50);
    }

    for (auto& emp : employees) {
        emp->calc();
    }

    for (auto& emp : employees) {
        emp->print_Info();
    }

     return 0;
}
