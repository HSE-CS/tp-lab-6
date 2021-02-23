//// Copyright 2021 Dmitry Vargin

#include "Manager.h"

int ProjManager::calc() {
    int salary = calcProAdditions() +
    calcBudgetPart(0.2, (int) getProject()->getBudget()) +
    calcHeads();
    this->setSalary(salary);
    return salary;
}

int ProjManager::calcBudgetPart(double p, int budget) {
    return floor(p * budget);
}

int ProjManager::calcProAdditions() {
    if (this->getWorktime() > 50) {
        return (int) (this->calcHeads() * 0.3);
    } else {
        return 0;
    }
}

int ProjManager::calcHeads() {
    return floor(getProject()->getBudget() * 0.1);
}

Project *ProjManager::getProject() {
    return project;
}

void ProjManager::printInfo() {
    std::cout << "ID: " << std::to_string(getId()) << std::endl;
    std::cout << "NAME: " << getName() << std::endl;
    std::cout << "POSITION: " << getPosition() << std::endl;
    std::cout << "WORK TIME: " << this->getWorktime() << std::endl;

    std::cout << "SALARY: " +
    std::to_string(getSalary()) << std::endl;

    std::cout << "PROJECT:  ID: " +
    std::to_string(getProject()->getId()) << std::endl;
}

///////////////////////////

int SeniorManager::calc() {
    int budgetPart = 0;
    for (auto &project : projects) {
        budgetPart += calcBudgetPart(
                0.2, (int) project->getBudget());
    }
    int salary = this->calcProAdditions()
            + budgetPart + calcHeads();
    setSalary(salary);
    return salary;
}

int SeniorManager::calcBudgetPart(double p, int budget) {
    return floor(p * budget);
}

int SeniorManager::calcProAdditions() {
    int wt = this->getWorktime();
    int salHeads = calcHeads();
    if (wt > 50) {
        return (int) (salHeads * 0.35);
    } else {
        return 0;
    }
}

int SeniorManager::calcHeads() {
    int budgHeads = 0;
    for (auto &pr : projects) {
        budgHeads += floor(pr->getBudget() * 0.1);
    }
    return budgHeads;
}

void SeniorManager::printInfo() {
    std::cout << "ID: " <<
    std::to_string(this->getId()) << std::endl;

    std::cout << "NAME: " << this->getName() << std::endl;
    std::cout << "POSITION: " + this->getPosition() << std::endl;
    std::cout << "WORK TIME: " << this->getWorktime() << std::endl;

    std::cout << "SALARY: " +
    std::to_string(this->getSalary()) << std::endl;

    std::cout << "PROJECTS:" << std::endl;
    std::string s;
    for (auto &project : projects) {
        s += " id: " + std::to_string(project->getId()) + "\n";
    }
    std::cout << "\n";
}
