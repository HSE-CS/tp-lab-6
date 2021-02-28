// Copyright 2021 TimurZaytsev
//

#include <iostream>

#include "Factory.h"
#include "Employee.h"


int main() {
    auto staff = StaffFactory::make_staff("staff.txt");

    for (auto e : staff) {
        e->worktime((unsigned)rand() % 96 + 1);
    }

    for (auto e : staff) {
        e->calc();
    }

    for (auto e : staff) {
        e->print_info();
        std::cout << std::endl;
    }

    return 0;
}
