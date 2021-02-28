#include "Manager.h"
#include <iostream>

Project::Project(int id, int budget) {
    this->id = id;
    this->budget = budget;
}

void ProjectManager::calc() {
    this->setPayment(calcHeads() + calcBudgetPart(0.10f, projects[0]->budget)
        + calcProAdditions());
}
void ProjectManager::printInfo() {
    std::cout << "id: " << getId() << "\name: " << getName() <<
        "\nPosition: " << positionToString() << "\Project: " <<
        projects[0]->id << "\nWorktime: " << worktime << "\Payment: " <<
        payment << std::endl;
    std::cout << "=====================================" << std::endl;
}

int ProjectManager::calcHeads() {
    int bonus = 0;
    for (auto project : projects) {
        bonus += 35000;
    }
    return bonus;
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return floor(part * budget);
}

int ProjectManager::calcProAdditions() {
    return 35000;
}

ProjectManager::ProjectManager(int id, std::string name, Position position,
    int worktime, std::vector <Project*> projects) :
    Employee(id, name, position, worktime) {
    this->projects = projects;
}

void SeniorManager::calc() {
    int budgetParts = 0;
    for (int i = 0; i < projects.size(); i++) {
        budgetParts += calcBudgetPart(0.05f, projects[i]->budget);
    }
    this->setPayment(calcHeads() + budgetParts + calcProAdditions());
}
SeniorManager::SeniorManager(int id, std::string name, Position position,
    int worktime, std::vector <Project*> projects) : ProjectManager(id, name,
        position, worktime, projects) {
}