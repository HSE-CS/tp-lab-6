// Copyright 2021 dmitrycvetkov2000
#include "Manager.h"

#include <cmath>
#include <iostream>
#include <numeric>
#include <string>

ProjectManager::ProjectManager(int id,
    const std::string& name,
    Project* project,
    float part) : Employee(id, name, Position::ProjectManager), part(part) {
    projects.insert(project);
    this->part = part;
}

ProjectManager::ProjectManager(int id,
    const std::string& name) : Employee(id, name, Position::ProjectManager) {
}

int ProjectManager::calcBudget(float part) const {
    return projects.begin().operator*()->budget * part;
}

int ProjectManager::calcProAdditions() const {
    return 0;
}

int ProjectManager::calcHeads() const {
    return projects.begin().operator*()->budget * 0.1;
}

void ProjectManager::calc() {
    payment = calcBudget(part) + calcHeads();
}

void ProjectManager::printInfo() const {
    std::cout << "Project manager " << name << std::endl;
    std::cout << "Worktime: " << worktime << std::endl;
    std::cout << "Project payment: " << calcBudget(part) << std::endl;
    std::cout << "Head payment: " << calcHeads() << std::endl;
    std::cout << "Total payment: " << payment << std::endl;
}

SeniorManager::SeniorManager(int id,
    const std::string& name,
    std::unordered_set<Project*>&& projects) : ProjectManager(id, name) {
    position = Position::SeniorManager;
    this->projects = std::move(projects);
    part = 0.12;
}

int SeniorManager::calcBudget(float part) const {
    return std::accumulate(std::begin(projects),
        std::end(projects), 0.0, [&part](int lhs, Project* p) {
            return lhs + std::floor(p->budget * part);
        });
}

int SeniorManager::calcProAdditions() const {
    return 0;
}

int SeniorManager::calcHeads() const {
    return std::accumulate(std::begin(projects),
        std::end(projects), 0.0, [](int lhs, Project* p) {
            return lhs + std::floor(p->budget * 0.12);
        });
}

void SeniorManager::calc() {
    payment = calcBudget(part) + calcHeads();
}

void SeniorManager::printInfo() const {
    std::cout << "Senior manager " << name << std::endl;
    std::cout << "Worktime: " << worktime << std::endl;
    std::cout << "Project payment: " << calcBudget(part) << std::endl;
    std::cout << "Head payment: " << calcHeads() << std::endl;
    std::cout << "Total payment: " << payment << std::endl;
}
