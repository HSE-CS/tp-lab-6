// Copyright 2021 BekusovMikhail

#include <ctime>
#include <iostream>
#include "Factory.h"

int main() {
    unsigned int rrr = 1;
    Factory factory = Factory();
    auto staff = factory.makeStaff();
    for (auto worker : staff) {
        worker->setWorkTime(rand_r(&rrr) % 50);
        worker->calc();
        worker->printInfo();
    }

    return 0;
}
