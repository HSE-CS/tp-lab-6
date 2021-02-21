//
// Created by Valera on 20.02.2021.
//

#include "../include/Manager.h"


int ProjectManager::calcHeads() {
    return 0;
}

void ProjectManager::calc() {

}

ProjectManager::
ProjectManager(int id, const std::string &name, Position position,
               const std::vector<Project *> &_projects, float part) :
               Employee(id, name, position), part(part) {
    for (int i = 0; i < num_of_projects; i++) projects.push_back(_projects[i]);
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return 0;
}

int ProjectManager::calcProAdditions() {
    return 0;
}

void SeniorManager::calc() {
    ProjectManager::calc();
}

int SeniorManager::calcProAdditions() {
    return ProjectManager::calcProAdditions();
}

SeniorManager::SeniorManager(int id, const std::string &name, Position position,
                             const std::vector<Project *> &projects, float part)
        : ProjectManager(id, name, position, projects, part) {}
