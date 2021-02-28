// Copyright 2021 MalininDmitry
#include <iostream>
#include <string>
#include "Employee.h"
#include "Factory.h"


int main() {
    std::vector<Employee*> staff = StaffFactory::makeStaff();

    for ( Employee* emp : staff ) {
        emp->setWorkTime(std::rand() % 40 + 1);
    }

    for ( Employee* emp : staff ) {
        emp->calc();
    }

    for ( Employee* emp : staff ) {
        emp->printInfo();
    }

    return 0;
}
