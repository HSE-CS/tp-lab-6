// Copyright [2021] <Roman Balayan>

#include <iostream>

#include "Employee.h"
#include "Factory.h"

int main() {
    std::cout << "Test" << std::endl;
    Factory factory("data.txt");
    auto employees = factory.getEmployees();

    for (auto emp : employees) {
        emp->calc();
    }
    for (auto emp : employees) {
        emp->printInfo();
    }
    return 0;
}
