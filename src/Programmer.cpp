// Copyright 2021
#include "Programmer.h"
#include <iostream>
#include <sstream>
#include <string>

double Programmer::calcBonus() {
    return 0.0;
}

double Programmer::calcProAdditions() {
    return std::rand() % 1000;
}

void Programmer::calc() {
    payment = Engineer::calcBudgetPart(0.1, project->getBudget()) + Personal::calcBase(worktime) + calcProAdditions();
}
