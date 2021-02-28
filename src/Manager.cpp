// Copyright 2021 MalininDmitry
#include <iostream>
#include "Manager.h"

ProjectManager::ProjectManager(int id, std::string name,
                std::string position,
                int numProjects,
                const std::vector<Project *> &projects,
                float part,
                int salary) : Employee(id,
                                    name,
                                    position,
                                    salary),
part(part) {
    for (int i = 0; i < numProjects; i++) {
        this->projects.push_back(projects[i]);
    }
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return budget / part;
}

int ProjectManager::calcHeads() {
    int s = 0;
    for (int i = 0; i < projects.size(); i++)
        s += 100;
    return s;
}

void ProjectManager::calc() {
    int s = 0;
    for (auto p : projects)
        s += p->budget;
    payment = salary*worktime +
    calcBudgetPart(part, s) + calcProAdditions()
    + calcHeads();
}

int ProjectManager::calcProAdditions() {
    int s = 0;
    for (int i = 0; i < projects.size(); i++)
        s +=  projects[i]->budget;
    return calcBudgetPart(part, s) / 15;
}

SeniorManager::SeniorManager(int id, std::string name, std::string position,
        int numProjects, const std::vector<Project *> &projects,
        float part, int salary) : ProjectManager(id, name, position,
        numProjects, projects, part, salary) {}

void ProjectManager::printInfo() {
    std::cout << "Information : " << std::endl;
    std::cout << "id : " << this->id << std::endl;
    std::cout << "name : " << this->name << std::endl;
    std::cout << "position : " << this->position << std::endl;
    std::cout << "worktime : " << this->worktime << std::endl;
    std::cout << "worktime : " << this->payment << std::endl;
    std::cout << "projects : " << std::endl;
    for (auto p : projects)
        std::cout << p->GetId() << std::endl;
}
