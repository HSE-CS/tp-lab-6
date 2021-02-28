// Copyright 2021 Islam Osmanov

#include "Manager.h"
#include "Interfaces.h"

ProjectManager::ProjectManager(int id,
                               std::string pos,
                               std::string name,
                               int employees,
                               Project *pr,
                               int salary) : Employee(id, name,pos, salary) {
    this->employees = employees;
    this->project = pr;
    setPosition(pos);
}

int ProjectManager::getNumEmployees() {
    return employees;
}

SeniorManager::SeniorManager(int id,
                             std::string pos,
                             std::string name,
                             std::vector<Project*> projects,
                             int employees,
                             int salary) : ProjectManager(id, pos, name,
                                                          employees, nullptr, salary) {
    setPosition(pos);
    this->projects = projects;
}

Project* ProjectManager::getProject() {
    return this->project;
}

int ProjectManager::calcHeads() {
    int heads = getNumEmployees() * 50;
    return heads;
}

void ProjectManager::printInfo() {
    std::cout << "--------------" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << getPosition() << " - position" << std::endl;
    std::cout << getPayment() << " - payment" << std::endl;
    std::cout << "--------------" << std::endl;
}

int ProjectManager::calcBudgetPart(double piece, int budget) {
    return static_cast<int>(budget / piece);;
}

void ProjectManager::calc() {
    int pay = calcBudgetPart(5, getProject()->getBudget()) + calcHeads();
    setPayment(pay);
}

int ProjectManager::calcProAdditions(int bonus) {
    return this->getNumEmployees() * bonus;
}

void SeniorManager::addProject(Project *project) {
    projects.push_back(project);
}

std::vector<Project*>& SeniorManager::getProjects() {
    return projects;
}


void SeniorManager::calc() {
    int sum = 0;
    for (auto i : getProjects()){
        sum += calcBudgetPart(5, i->getBudget());
    }
    sum = sum + calcHeads();
    setPayment(sum);
}