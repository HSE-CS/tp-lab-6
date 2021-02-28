//  Copyright 2021 Nikita Naumov

#include "Manager.h"

Manager::Manager(unsigned int id, const std::string& name) : Employee(id, name) {
    this->id = id;
    this->name = name;
    this->worktime = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
}
void Manager::setProject(Project* link) {
    this->linkToProject = link;
}
unsigned Manager::calcHeads() {
    return ((this->linkToProject)->getNumberOfMembers() * 1759 / 4);
}

unsigned Manager::calcBudgetPart() {
    return ((this->linkToProject)->getProjectBudget()/this->linkToProject->getNumberOfMembers());
}
unsigned Manager::calcProAdditions() {
    return (5873 * rand()%100 / 3000);
}
void Manager::calc() {
    this->payment = calcHeads() + calcBudgetPart() + calcProAdditions();
}

SeniorManager::SeniorManager(unsigned id, std::string name) : Manager(id, name){
    this->id = id;
    this->name = name;
    this->projects.clear();
    this->worktime = 0;
    this->linkToProject = nullptr;
    this->projects.clear();
    this->payment = 0;
}
SeniorManager::~SeniorManager() {
    this->projects.clear();
}

unsigned SeniorManager::calcHeads() {
    int headsSalary = 0;
    for (size_t i = 0; i < this->projects.size(); ++i) {
        headsSalary += this->projects[i]->getNumberOfMembers() * 1759 / 10;
    }
    return headsSalary;
}
void SeniorManager::calc() {
    this->payment = calcHeads() + calcBudgetPart() + calcProAdditions();
}
