// Copyright 2021 Danyaev Artem
#include "Factory.h"
#include <iostream>

int main() {
    std::vector<Employee*> staff =
        Factory::makeStaff("projects.txt", "employees.txt");

    for (Employee* emp : staff) {
        emp->setWorkTime(std::rand() % 50);
    }

    for (Employee* emp : staff) {
        emp->calc();
    }

    for (Employee* emp : staff) {
        emp->printInfo();
    }

    return 0;
}
