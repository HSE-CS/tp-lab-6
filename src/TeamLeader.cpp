// Copyright 2021
#include "TeamLeader.h"
#include <iostream>
#include <sstream>
#include <string>

int TeamLeader::calcHeads() {
    return project->getProgrammers() * 10;
}

void TeamLeader::calc() {
    payment = calcHeads() + Engineer::calcBudgetPart(0.3, project->getBudget()) + Personal::calcBase(worktime);
}

void TeamLeader::printInfo() {
    std::stringstream stream;
    stream << "Name: " << name
        << ", position: " << position
        << ", workTime: " << worktime
        << ", payment: " << payment
        << ", project name: " << project->getName()
        << ", number of programmers " << project->getProgrammers();
    std::cout << stream.str() << std::endl;
}
