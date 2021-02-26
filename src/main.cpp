// Copyright 2021 JGMax

#include <iostream>
#include "Engineer.h"
#include "Factory.h"

int main() {
    std::vector<Employee*> staff = StaffFactory::makeStuff("staff.txt");

    for (auto employee : staff) {
        employee->printInfo();
        std::cout << "<---------->" << std::endl;
    }

    return 0;
}
