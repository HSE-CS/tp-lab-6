// Copyright 2021 BekusovMikhail

#include <ctime>
#include <iostream>
#include "Factory.h"

int main() {
    srand(time(0));
    Factory factory = Factory();
    auto staff = factory.makeStaff();
    for (auto worker: staff) {
        worker->setWorkTime(rand() % 50);
        worker->calc();
        worker->printInfo();
    }
    return 0;
}
