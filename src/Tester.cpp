// Copyright 2021
#include "Tester.h"
#include <iostream>

double Tester::calcProAdditions() {
    return std::rand() % 1000;
}

void Tester::calc() {
    payment = Engineer::calcBudgetPart(0.2, project->getBudget()) +
        Personal::calcBase(worktime) + calcProAdditions();
}

double Tester::calcBonus() {
    return 0.0;
}
