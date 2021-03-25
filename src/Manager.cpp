// Copyright 2021 dash
#include "Manager.h"

ProjectManager::ProjectManager(int id,
    std::string name,
    Position position,
    int worktime,
    int payment,
    Project project)
    : Employee(id, name, position)
    , projects(projects) {
}


SeniorManager::SeniorManager(int id,
    std::string name,
    Position position,
    int worktime,
    int payment,
    Project project)
    : ProjectManager(id, name, position, worktime, payment, project) {
}


int ProjectManager::calcHeads() {
    return 1000;
}

int ProjectManager::calcProAdditions() {
    return 1000;
}

int ProjectManager::calcBudgetPart(double part, int budget) {
    return budget*part;
}

void ProjectManager::calc() {
    payment = calcHeads();
    for (const auto& project : projects) {
        payment += calcBudgetPart(part, project->budget);
    }
}

void ProjectManager::print_Info() {
    std::cout << get_Name() + " " + std::to_string(get_Id());
}


void SeniorManager::calc() {
    payment = calcHeads();
    for (const auto& project : projects) {
        payment += calcBudgetPart(part, project->budget);
    }
}

void SeniorManager::print_Info() {
    std::cout << get_Name() + " " + std::to_string(get_Id());
}
