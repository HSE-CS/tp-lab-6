// Copyright 2021 Khoroshavina Ekaterina
#include <iostream>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "Factory.h"

int main() {
    std::vector<Employee*> staff = makeStaff("data.csv");
    for (auto employee : staff) {
        employee->calc();
        employee->printInfo();
    }
    return 0;
}
