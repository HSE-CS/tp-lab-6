// Copyright 2021 Bekina Svetlana
#include "Manager.h"

ProjectManager::ProjectManager() {}

int ProjectManager::calcHeads() {
    return 20000;
}

void ProjectManager::calc() {
    int bonus = 0;
    for (auto pr : projects) {
        bonus += pr.budget * getWorkTime() * 0.01;
    };
    setPayment(calcHeads() + bonus);
}

void ProjectManager::printInfo() {
    std::cout << "\nName: " << getName() << "\t" << getId() << std::endl;
    std::cout << "\nWork time: " << getWorkTime() << std::endl;
    std::cout << "\nPayment: " << getPayment() << std::endl;
    for (auto pr : projects) {
        std::cout << "\nProject: " << pr.name << "\tBudget: " << pr.budget << std::endl;
    };
}

int ProjectManager::calcBugetPart(float part, int budget) {
    return part * budget;
}

int ProjectManager::calcProAdditins() {
    return 10000;
}

std::vector<Project> ProjectManager::getProjects() {
    return projects;
}

SeniorManager::SeniorManager() {}

void SeniorManager::calc() {
    int bonus = 0;
    for (auto pr : getProjects()) {
        bonus += pr.budget * getWorkTime() * 0.02;
    };
    setPayment(calcHeads() + bonus);
}

