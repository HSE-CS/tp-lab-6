// Copyright 2021 BekusovMikhail

#include "Manager.h"

#include <utility>
#include <iostream>

ProjectManager::ProjectManager(std::string id, std::string name,
                               Position position,
                               std::vector<Project *> projects) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->position = position;
    this->projects = std::move(projects);
    this->payment = 0;
}

void ProjectManager::setProjects(std::vector<Project *> projects) {
    this->projects = std::move(projects);
}

std::vector<Project *> &ProjectManager::getProjects() {
    return this->projects;
}

int ProjectManager::calcHeads() {
    this->payment += 10000;
    return 10000;
}

void ProjectManager::calc() {
    this->calcHeads();
    this->payment += this->calcBudgetPart
            (static_cast<float>(0.15),
             this->projects[0]->getBudget());
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * static_cast<float>(budget));
}

int ProjectManager::calcProAdditions() {
    return 0;
}

void ProjectManager::printInfo() {
    std::cout << this->name << "(" <<
              this->position << "). Payment: " << this->payment << std::endl;
}

SeniorManager::SeniorManager(std::string id, std::string name,
                             Position position,
                             std::vector<Project *> projects)
        : ProjectManager(id, name, position, projects) {
}

void SeniorManager::calc() {
    this->payment = 0;
    for (int i = 0; i < projects.size(); ++i) {
        this->calcHeads();
        this->payment += this->calcBudgetPart(static_cast<float>(0.25),
                                              this->projects[i]->getBudget());
    }
}
