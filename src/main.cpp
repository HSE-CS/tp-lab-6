// Copyright 2021 by Fatin Maxim
#include <iostream>
#include <string>
#include <vector>
#include "Factory.h"
#include "Personal.h"
#include "Interfaces.h"

int main() {
    std::vector<Employee*> staff = makeStaff();
    for (auto emp : staff) {
        emp->setWorkTime(10);
    }
    for (auto emp : staff) {
        emp->calc();
    }
    for (auto emp : staff) {
        emp->printInfo();
    }
}
