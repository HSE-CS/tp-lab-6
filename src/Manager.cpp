// Copyright 2021 valvarl

#include <sstream>
#include <iostream>
#include "../include/Manager.h"


int ProjectManager::calcHeads() {
    int sum = 0;
    for (auto p : projects) {
        sum += 75;
    }
    return sum;
}

void ProjectManager::calc() {
    int sum = 0;
    for (auto p : projects) sum += p->budget;
    payment = calcBudgetPart(part, sum) + calcProAdditions() + calcHeads();
}

ProjectManager::ProjectManager(
        int id, const std::string &name, Position position, int num_of_projects,
        const std::vector<Project *> &_projects, float part) :
               Employee(id, name, position), part(part) {
    for (int i = 0; i < num_of_projects; i++) projects.push_back(_projects[i]);
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return budget * part;
}

int ProjectManager::calcProAdditions() {
    int sum = 0;
    for (auto p : projects) sum += p->budget;
    return calcBudgetPart(part, sum) / 20;
}

SeniorManager::SeniorManager(
        int id, const std::string &name, Position position, int num_of_projects,
        const std::vector<Project *> &projects, float part) :
        ProjectManager(id, name, position, num_of_projects, projects, part) {}

void ProjectManager::printInfo() {
    std::stringbuf str;
    std::ostream stream(&str);
    stream << "Id: " << id << "\nName: " << name << "\nPosition: " <<
    getPosition() << "\nProjects: [";
    for (auto p: projects) {
        stream << p->name << ", ";
    }
    stream << "]\nWork time: " << workTime << "\nPayment: " << payment << "\n";
    std::cout << str.str() << std::endl;
}
