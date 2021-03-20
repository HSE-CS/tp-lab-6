// Copyright 2021 Stifeev Nikita

#include <time.h>
#include <iostream>
#include <vector>
#include "Project.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"
#include "Factory.h"

int main() {
    std::vector<Employee*> staff;
    staff = Factory::makeStaff("projects staff.txt");
    srand(time(NULL));
    for (Employee* emp : staff) {
        emp->setWorkTime(40 + std::rand() % 101);
    }
    for (Employee* emp : staff) {
        emp->calc();
    }
    for (Employee* emp : staff) {
        emp->printInfo();
    }
    return 0;
}
