// Copyright 2021
#include "SeniorManager.h"
#include <iostream>
#include <sstream>
#include <string>

void SeniorManager::calc() {
    double paym = 0.0;
    int members = 0;
    for (int i = 0; i < projects.size(); i++) {
        paym += projects[i]->getBudget() * 0.4;
        members += projects[i]->getMember();
    }
    payment += (paym + members * 5);
}

void SeniorManager::printInfo() {
    std::stringstream stream;
    stream << "Name: " << name
        << ", position: " << position
        << ", worktime " << worktime
        << ", payment: " << payment
        << ", number of projects: " << projects.size();
    std::cout << stream.str() << std::endl;
}
