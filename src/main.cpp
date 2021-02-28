// Copyright 2021 Sozinov Kirill

#include "Factory.h"
#include "Manager.h"
#include "Engineer.h"

int main()
{
    StaffFactory factory;
    std::vector<Employee*> staff = factory.makeStaff("Projects.txt", "Employees.txt");
    for (auto emp : staff) {
        emp->setWorkTime(std::rand() % 15);
    }
    for (auto emp : staff) {
        emp->calc();
    }
    for (auto emp : staff) {
        emp->printInfo();
    }
    return 0;
}


