// Copyright 2021 Igumnova Natasha
#include "Manager.h"
#include <fstream>
#include <string>
#include <cmath>

int ProjectManager::calcHeads() {
    return static_cast<int>(this->project[0].budget * 0.01);
}

int ProjectManager::calc() {
    return getPayment() * getWorktime() + calcProAdditions();
}
int ProjectManager::calcBudgetPart(float part, int budget) {
    return part * budget;
}
int ProjectManager::calcProAdditions() {
    return ProjectManager::calcBudgetPart(0.2, project[0].budget);
}
int SeniorManager::calc() {
    return ProjectManager::calc();
}

void ProjectManager::printInfo() {
    std::string res;
    std::cout << project[0].id;
    res = "id " + std::to_string(getId())
        + "\nname " + getName() + "\nposition " + getPosition()
        + "\npayment " + std::to_string(getPayment())
        + "\nsalary " + std::to_string(calc())
        + "\nProject id " + std::to_string(project[0].id)
        + "\nProject budget " + std::to_string(project[0].budget);
    std::cout << res << std::endl;
}
void SeniorManager::printInfo() {
    std::string res;
    res = "id " + std::to_string(getId())
        + "\nname " + getName() + "\nposition " + getPosition()
        + "\npayment " + std::to_string(getPayment())
        + "\nsalary " + std::to_string(calc());
    std::cout << res << std::endl;
}
