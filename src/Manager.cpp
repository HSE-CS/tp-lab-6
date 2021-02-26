// Copyright 2021 JGMax

#include <iostream>
#include <utility>
#include "Manager.h"

ProjectManager::ProjectManager(const int id,
                               const std::string fullName,
                               const int workTime,
                               const Position position,
                               Project *project) : Employee(id,
                                                            fullName,
                                                            workTime,
                                                            position) {
    projects.push_back(project);
    if (project) {
        project->addHead();
    }
    calc();
}

int ProjectManager::calcHeads() {
    if (projects[0]) {
        return projects[0]->getWorkers();
    }
    return 0;
}

int ProjectManager::calcBudgetPart() {
    if (projects[0]) {
        return projects[0]->getBudget() /
        (projects[0]->getWorkers() + projects[0]->getHeads());
    } else {
        return 0;
    }
}

int ProjectManager::calcProAdditions() {
    double addition = calcHeads() * 0.01;
    if (addition > 1) {
        addition = 1;
    }
    return calcBudgetPart() * addition;
}

void ProjectManager::calc() {
    payment = calcBudgetPart() + calcProAdditions();
}

void ProjectManager::printInfo() {
    calc();
    std::cout << this->getFullName() << "\t" <<
    this->getPosition() << std::endl;
    std::cout << "Payment:\t" << this->getPayment() << std::endl;
    std::cout << "WorkTime:\t" << this->getWorkTime() << std::endl;
    std::cout << "Subordinates number:\t" << calcHeads() << std::endl;
    std::cout << "Projects names:" << std::endl;
    if (projects[0]) {
        std::cout << "\t" << projects[0]->getTitle() << std::endl;
    }
}


SeniorManager::SeniorManager(const int id,
                             const std::string fullName,
                             const int workTime,
                             const Position position,
                             std::vector<Project*> projects) :
                             ProjectManager(id,
                                            fullName,
                                            workTime,
                                            position,
                                            nullptr) {
    this->projects = std::move(projects);
    for (auto & project : this->projects) {
        if (project) {
            project->addHead();
        }
    }
    calc();
}

int SeniorManager::calcBudgetPart() {
    double allParts = 0;
    for (auto & project : projects) {
        if (project) {
            allParts += project->getBudget() *
                        (project->getBudget() / project->getWorkers());
        }
    }
    return allParts;
}

int SeniorManager::calcProAdditions() {
    double allHeads = calcHeads();
    allHeads *= 0.01;
    if (allHeads > 1) {
        allHeads = 1;
    }
    return calcBudgetPart() * allHeads;
}

void SeniorManager::calc() {
    payment = calcBudgetPart() + calcProAdditions();
}

void SeniorManager::printInfo() {
    ProjectManager::printInfo();
    for (auto & project : projects) {
        if (project != projects[0])
        std::cout << "\t" << project->getTitle() << std::endl;
    }
}

int SeniorManager::calcHeads() {
    double allHeads = 0;
    for (auto & project : projects) {
        if (project) {
            allHeads += project->getWorkers();
        }
    }
    return allHeads;
}

