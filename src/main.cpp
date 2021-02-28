// Copyright 2021 Nikolaev Ivan

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "Factory.h"

int main() {
    setlocale(LC_ALL, "");
    Factory factory;
    std::vector<Employee*> staff = factory.makeStaff();
    for (auto e : staff) {
        e->setWorktime(40);
    }
    for (auto e : staff) {
        e->calc();
    }
    for (auto e : staff) {
        e->printInfo();
    }

    Tester tester(15, "Pavel", TESTER, 50, 800, new Project(1, 100000));
    tester.calc();
    printf("%d", tester.getPayment());
    return 0;
}