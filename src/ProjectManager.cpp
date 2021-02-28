// Copyright 2021
#include "ProjectManager.h"
#include <iostream>
#include <sstream>
#include <string>

double ProjectManager::calcBudgetPart(double part, double budget) {
    return part *  budget;
}

void ProjectManager::calc() {
    payment = calcBudgetPart(0.4, project->getBudget()) + calcHeads();
}

void ProjectManager::printInfo() {
    std::stringstream stream;
    stream << "Name: " << name
        << ", position: " << position
        << ", worktime " << worktime
        << ", payment: " << payment
        << ", project name: " <<
        project->getName() << ", members: "
        << project->getMember();
    std::cout << stream.str() << std::endl;
}

int ProjectManager::calcHeads() {
    return project->getMember() * 13;
}

double ProjectManager::calcProAdditions() {
    return 0.0;
}
