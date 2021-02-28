// Copyright 2021
#include "Engineer.h"
#include <iostream>
#include <sstream>
#include <string>


double Engineer::calcBudgetPart(double part, double budget) {
    return part * budget;
}

void Engineer::printInfo() {
    std::stringstream stream;
    stream << "Name: " << name
        << ", position: " << position
        << ", workTime: " << worktime
        << ", payment: " << payment
        << ", project name: " << project->getName();
    std::cout << stream.str() << std::endl;
}
