//
// Created by Valera on 20.02.2021.
//

#include "../include/Manager.h"

#include <utility>

int ProjectManager::calcHeads() {
    return 0;
}

void ProjectManager::calc() {

}

ProjectManager::
ProjectManager(int id, const std::string &name, Position position,
               const std::vector<Project *> &_projects, float part) :
               Employee(id, name, position), part(part) {
    for (int i = 0; i < num_of_projects; i++) projects.push_back(projects[i]);
}

void SeniorManager::calc() {
    ProjectManager::calc();
}
