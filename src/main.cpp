// Copyright 2021 dmitrycvetkov2000
#include "Factory.h"

#include <ctime>
#include <iostream>
#include <vector>

int main() {
    std::srand(time(nullptr));

    std::vector<Employee*> staff =
        StaffFactory().makeStaff("./staff.txt",
            "./projects.txt");
    for (Employee *emp : staff) {
        emp->setWorkTime(160 + std::rand() % 15);
    }
    for (Employee *emp : staff) {
        emp->calc();
    }
    for (Employee *emp : staff) {
        emp->printInfo();
        std::cout << std::endl;
    }
    return 0;
}
