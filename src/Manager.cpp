// Copyright 2021 Shatilov Victor

#include <iostream>
#include "Manager.h"

ProjectManager::ProjectManager(int id, const std::string& name,
                               int workTime, Positions position,
                               std::vector <Project *> p)
        : Employee(id, name, workTime, position) {
    this->payment = payment;
    projects = std::move(p);
}

 int ProjectManager::calcHeads() {
    int count_all_workers = 0;
    for (auto p : projects)
        if (p)
            count_all_workers += p->getCountWorkers();
    return count_all_workers;
}

int ProjectManager::calcProAdditions() {
    return bonus;
}

int ProjectManager::calcBudgetPart() {
    int res = 0;
    if (!projects.empty()) {
        for ( auto p: projects )
            res += static_cast<int>(
                    (1.0f / p->getCountWorkers()) * p->getBudget());
        return res;
    } else
        return 0;
}

int ProjectManager::calc() {
    return payment = calcHeads() * calcProAdditions() + calcBudgetPart();
}

void ProjectManager::printInfo() {
    std::cout << name << " on " << this->getPositionAsStr() << std::endl;

    for (auto p : projects)
        if (p)
            std::cout << p->getName() << " with "
                      << p->getCountWorkers() << " workers." << std::endl;

    std::cout << "Payment: " << payment << std::endl;
}

SeniorManager::SeniorManager(int id, const std::string& name,
int workTime, Positions position, std::vector<Project *> p)
        : ProjectManager(id, name, workTime, position, std::move(p)) {
}
