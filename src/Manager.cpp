// Copyright 2021 Sozinov Kirill

#include "Manager.h"

ProjectManager::ProjectManager(int _id, std::string _name,
    std::string _position, std::vector<Project> _projects)
    : Employee(_id, _name, _position), projects(_projects) {}

float ProjectManager::calcBudgetPart(float part, int budget) {
    return budget * part;
}

int ProjectManager::calcHeads() {
    int sum = 0;
    for (auto project : projects) {
        sum += 3500 * project.getTeamSize();
    }
    return sum;
}

void ProjectManager::calc() {
    double sum = 0;
    for (auto project : projects) {
        sum += calcBudgetPart(1 / project.getTeamSize(), project.budget);
    }
    payment = calcHeads() + sum;
}

void ProjectManager::printInfo() {
    std::cout << id << ": " << name << ", position: " <<
        position << ", managing projects: ";
    for (auto project : projects) {
        std::cout << project.getId() << ", ";
    }
    std::cout << '\n' << "total payment: " << payment << std::endl;
}

SeniorManager::SeniorManager(int _id, std::string _name,
    std::string _position, std::vector<Project> _projects)
    : ProjectManager(_id, _name, _position, _projects) {}

float SeniorManager::calcBudgetPart(float part, int budget) {
    return budget * part;
}

int SeniorManager::calcHeads() {
    int sum = 0;
    for (auto project : projects) {
        sum += 4000 * project.getTeamSize();
    }
    return sum;
}

void SeniorManager::calc() {
    double sum = 0;
    for (auto project : projects) {
        sum += calcBudgetPart(1 / project.getTeamSize(), project.getBudget());
    }
    payment = calcHeads() + sum;
}
