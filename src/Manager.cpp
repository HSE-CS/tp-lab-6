//// Copyright 2021 Dmitry Vargin

#include "Manager.h"

int ProjectManager::calc() {
    int salary = calcProAdditions() +
    calcBudgetPart(0.2, static_cast<int>(
            getProject()->getBudget())) +
    calcHeads();
    this->setSalary(salary);
    return salary;
}

int ProjectManager::calcBudgetPart(double p, int budget) {
    return floor(p * budget);
}

int ProjectManager::calcProAdditions() {
    if (this->getWorktime() > 50) {
        return static_cast<int>((this->calcHeads() * 0.3));
    } else {
        return 0;
    }
}

int ProjectManager::calcHeads() {
    return floor(getProject()->getBudget() * 0.1);
}

Project *ProjectManager::getProject() {
    return project;
}

void ProjectManager::printInfo() {
    std::cout << "ID: " << std::to_string(getId()) << std::endl;
    std::cout << "NAME: " << getName() << std::endl;
    std::cout << "POSITION: " << getPosition() << std::endl;
    std::cout << "WORK TIME: " << this->getWorktime() << std::endl;

    std::cout << "SALARY: " +
    std::to_string(getSalary()) << std::endl;

    std::cout << "PROJECT:\n ID: " +
    std::to_string(getProject()->getId()) << "\n\n";
}

///////////////////////////

std::vector<Project *> SeniorManager::getProjects() {
    return this->projects;
}

int SeniorManager::calc() {
    int budgetPart = 0;
    for (auto &project : projects) {
        budgetPart += calcBudgetPart(
                0.2, static_cast<int>(project->getBudget()));
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
        return static_cast<int>((salHeads * 0.35));
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
    for (auto &project : projects) {
        std::cout << " ID: " + std::to_string(project->getId()) + "\n";
    }
    std::cout << "\n";
}
