// Copyright 2021 GN
#include "Factory.h"
#include "Engineer.h"
#include <iostream>
Project* Engineer::getProject() {
    return project;
}
int Engineer::calcBudgetPart(float part_, int budget_) {
    return static_cast<int>(part_ * budget_);
}
void Engineer::calc() {
    setPayment(calcBase(getSalary(), getWorkTime())
        + calcBudgetPart(0.01, getProject()->budget) + calcProAdditions());
}
int Programmer::calcProAdditions() {
    if (bonus == 1) { return 10000; }
    return 0;
}
int Tester::calcProAdditions() {
    return getErrorsNumber() * 100;
}
int Tester::getErrorsNumber() {
    return errors;
}
int TeamLeader::getSubordinates() {
    return subordinates;
}
void TeamLeader::calc() {
    setPayment(calcBase(getSalary(), getWorkTime()) +
        calcBudgetPart(0.02, getProject()->budget) + calcHeads());
}
int TeamLeader::calcHeads() {
    return getSubordinates() * 1000;
}
void Engineer::printInfo() {
    std::cout << getName() + " " + std::to_string(getID())
        + " " + getProject()->id;
}
