// Copyright 2021 Stifeev Nikita

#include "Manager.h"

ProjectManager::ProjectManager(int id, std::string name) :
    Employee(id, name) {
    this->position = PROJECT_MANAGER;
    this->projects = new std::vector<Project*>;
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return static_cast<float>(part * static_cast<float>(budget));
}

int ProjectManager::calcHeads() {
    return projects->size() * 75000;
}

void ProjectManager::calc() {
    this->payment = calcHeads() +
        calcBudgetPart(0.1, projects->at(0)->getBudget());
}

void ProjectManager::printInfo() {
    std::cout << "#" << this->id << ". " << posToString(this->position)
        << " " << this->name << " [manager staff]" << std::endl;
    std::cout << "number of projects: " << this->projects->size()
        << ". earned: " << this->payment << std::endl << std::endl;
}

SeniorManager::SeniorManager(int id, std::string name) :
    ProjectManager(id, name) {
    this->position = SENIOR_MANAGER;
}

void SeniorManager::calc() {
    int sum = 0;
    for (int i = 0; i < projects->size(); i++) {
        sum += calcBudgetPart(0.1, projects->at(0)->getBudget());
    }
    this->payment = calcHeads() + sum;
}
