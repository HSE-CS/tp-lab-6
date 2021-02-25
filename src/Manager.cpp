#include "Manager.h"
#include <string>

ProjectManager::ProjectManager(int id, std::string name, Position position,
    std::string project) : Employee(id, name, position) {
    this->project.id = project;
    this->project.budget = 300000;
}

int ProjectManager::calcHeads() {
    return 200;
}

int ProjectManager::calcProAdditions() {
    return 5000;
}

std::string PositionStriing[] = {
    "Project Manager", "Senior Manager"
};

void ProjectManager::printInfo() {
    std::cout << "id " << this->Employee::id << std::endl;
    std::cout << "name " << this->name << std::endl;
    std::cout << "position " << PositionStriing[int(this->position) - 2] << std::endl;
    std::cout << "work time " << this->worktime << std::endl;
    std::cout << "payment " << this->payment << std::endl;
    std::cout << "project " << this->project.id << std::endl;
    std::cout << std::endl;
}

int ProjectManager::calcBudgetPart(double part, int budget) {
    return int(part * budget);
}

void ProjectManager::calc() {
    this->payment = this->worktime * calcHeads() + calcProAdditions() + 
        calcBudgetPart(0.2, this->project.budget);
}

SeniorManager::SeniorManager(int id, std::string name, Position position, std::string project) :
    ProjectManager(id, name, position, project) {
    this->project.id = project;
    this->project.budget = 200000;
}

void SeniorManager::calc() {
    int t = this->worktime * calcBudgetPart(0.005, this->project.budget);
    this->payment = t + calcProAdditions();
}

int SeniorManager::calcBudgetPart(double part, int budget) {
    return int(part * budget);
}
