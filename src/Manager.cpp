// Copyright 2021 Vadukk
#include "Manager.h"

int ProjectManager::calcHeads() {
    int s = 0;
    for (auto i : project) {
        s += 145;
    }
    return s;
}
int ProjectManager::calc() {
    int s = 0;
    for (auto i : project)
        s += i->budget;
    return getPayment() * getWorkTime() + calcBudgetPart(part, s) +
        calcProAdditions() + calcHeads();
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return budget * part;
}

int ProjectManager::calcProAdditions() {
    return calcHeads();
}

void ProjectManager::printInfo() {
    std::cout << "ID : " << getId() << std::endl;
    std::cout << "Name : " << getName() << std::endl;
    std::cout << "Position : " << getPosition() << std::endl;
    std::cout << "Work time : " << getWorkTime() << std::endl;
    std::cout << "Projects: \n";
    for (auto i : project) {
        std::cout << i->name << "\n";
    }
}
