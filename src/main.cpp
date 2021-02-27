// Copyright 2021 GN
#include "Factory.h"
#include <iostream>
int main() {
    std::string name_ = "Ivanov Ivan";
    Project project_1;
    project_1.id = "project_1";
    project_1.budget = 2000000;
    SeniorManager pr(10, name_, &project_1);
    pr.printInfo();
    std::cout << std::endl;
    pr.setWorkTime(2);
    pr.addSubordinates();
    pr.addSubordinates();
    pr.calc();
    std::cout << pr.getPayment() << std::endl;
    name_ = "Peter Ivanov";
    Cleaner c(156, name_, 50);
    std::cout << c.getPos() << std::endl;
    c.setWorkTime(2);
    c.calc();
    std::cout << c.getPayment() << std::endl;
    name_ = "Inna Ivanova";
    Driver c1(157, name_, 60);
    c1.addBonus();
    c1.setWorkTime(2);
    c1.calc();
    std::cout << c1.getPayment() << std::endl;
    std::cout << c1.getPos() << std::endl;
}
