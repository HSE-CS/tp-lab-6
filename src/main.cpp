// Copyright 2021 Bekina Svetlana
#include "Employee.h"
#include "Factory.h"
#include <ctime>

int main() {
    StaffFactory file;
    std::vector<Employee*> staff = file.makeStaff();

    srand(time(0));
	int seed = 54321;
    for (Employee* emp : staff) {
        emp->setWorkTime(20 + rand_r(&seed) % 40);
    }

    for (Employee* emp : staff) {
        emp->calc();
    }

    for (Employee* emp : staff) {
        emp->printInfo();
    }
    return 0;
}
