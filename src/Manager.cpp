// Copyright 2021 Kris

#include "Manager.h"
#include <vector>

void ProjectManager::setsalary(int a) {
    salary = a;
}

ProjectManager::ProjectManager(int _id, std::string _name,
    std::string _pos, int _payment) :
    Employee(_id, _name, _pos, _payment) {
    salary = 0;
}

ProjectManager::ProjectManager(int _id, std::string _name,
    std::string _pos, int _payment, Project currentProject):
    Employee(_id, _name, _pos, _payment) {
    myProject = currentProject;
    salary = 0;
}

void ProjectManager::setProgect(int id_, int budget_) {
    Project(id_, budget_);
}

int ProjectManager::calcBudgetPart(double part, int budget) {
    return static_cast<int>(part * budget);
}

int ProjectManager::calcProAdditions() {
    return calcBudgetPart(0.15, myProject.getBudget());
}

int ProjectManager::calc() {
    setsalary(calcProAdditions() + calcHeads());
    return calcProAdditions() + calcHeads();
}

int ProjectManager::calcHeads() {
    return calcBudgetPart(0.05, myProject.getBudget());
}

SeniorManager::SeniorManager(int _id, std::string _name,
    std::string _pos, int _payment, std::vector<Project> _Projects):
    ProjectManager(_id, _name, _pos, _payment) {
    Projects = _Projects;
}

void SeniorManager::addProject(Project pr) {
    Projects.push_back(pr);
}

int SeniorManager::calcHeads() {
    int i = 0;
    for (Project myProject : Projects) {
        i = i + calcBudgetPart(0.15, myProject.getBudget());
    }
    return i;
}
int SeniorManager::calcProAdditions() {
    int i = 0;
    for (Project myProject : Projects) {
        i = i + calcBudgetPart(0.2, myProject.getBudget());
    }
    return i;
}

int SeniorManager::calc() {
    setsalary(calcProAdditions() + calcHeads());
    return calcProAdditions() + calcHeads();
}

int ProjectManager::getsalary() {
    return salary;
}

void ProjectManager::printInfo() {
    std::cout << std::setw(8) << getid() << std::setw(16) <<
        getname() << std::setw(16) << getposition() <<
        std::setw(4) << getworktime() << std::setw(5) <<
        getpayment() << std::setw(8) << getsalary() << std::endl;
}

void SeniorManager::printInfo() {
    std::cout << std::setw(8) << getid() << std::setw(16) <<
        getname() << std::setw(16) << getposition() <<
        std::setw(4) << getworktime() << std::setw(5) <<
        getpayment() << std::setw(8) << getsalary() << std::endl;
}
