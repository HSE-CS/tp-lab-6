// Copyright 2021 Shatilov Victor

#include "Factory.h"
int main() {
    std::vector < Employee * > staff = Factory::makeStaff();
    for (auto emp : staff) {
        emp->calc();
    }
    for (auto emp : staff) {
        emp->printInfo();
    }
}
