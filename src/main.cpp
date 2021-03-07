// Copyright 2021 BL
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"
#include <iostream>

int main() {
    Project project;
    project.id = "project";
    project.budget = 2000000;

    SeniorManager mng(10, "Rebecca Burns", &project);
    mng.printInfo();
    std::cout << '\n';
    mng.setWorkTime(2);
    mng.addSubordinates();
    mng.addSubordinates();
    mng.calc();
    std::cout << mng.getPayment() << '\n';

    Cleaner clean(156, "Kelly Richards", 50);
    std::cout << clean.getPos() << '\n';
    clean.setWorkTime(2);
    clean.calc();
    std::cout << clean.getPayment() << '\n';

    Driver driv(157, "Douglas Smith", 60);
    driv.addBonus();
    driv.setWorkTime(2);
    driv.calc();
    std::cout << driv.getPayment() << '\n';
    std::cout << driv.getPos() << '\n';
}
