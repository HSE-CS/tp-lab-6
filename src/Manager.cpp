// Copyright 2021 asma
#include "Manager.h"

ProjectManager::ProjectManager(int _id, std::string _name,
    Position _position, Project* _project, double _part) {
    id = _id;
    name = _name;
    position = _position;
    project = _project;
    part = _part;
    worktime = 0;
    payment = 0;
}

SeniorManager::SeniorManager(int _id, std::string _name,
    Position _position, std::vector<Project*> _projects) {
    id = _id;
    name = _name;
    position = _position;
    projects = _projects;
    worktime = 0;
    payment = 0;
}

int ProjectManager::CalcProAdditions() const {
    return 0;
}

int ProjectManager::CalcBudgetPart() const {
    return part * project->budget;
}

int ProjectManager::CalcHeads() const {
    return 5000;
}

void ProjectManager::Calc() {
    payment = CalcBudgetPart() + CalcHeads();
}

int SeniorManager::CalcProAdditions() const {
    return CalcHeads() * projects.size();
}

int SeniorManager::CalcBudgetPart() const {
    int total = 0;
    for (auto proj : projects) {
        total = proj->budget;
    }
    return 0.1 * total;
}

void SeniorManager::Calc() {
    payment = CalcProAdditions() + CalcBudgetPart();
}

std::string ProjectManager::GetPosition() const {
    return "Project Manager";
}

std::string SeniorManager::GetPosition() const {
    return "Senior Manager";
}

void ProjectManager::PrintInfo() const {
    std::cout << "Name - " << name << '\n';
    std::cout << "Position - " << GetPosition() << '\n';
    std::cout << "Payment - " << payment << '\n';
}

void ProjectManager::SetProject(Project* _project) {
    project = _project;
}

void ProjectManager::SetPart(double _part) {
    part = _part;
}

void SeniorManager::AppendProject(Project* project) {
    projects.push_back(project);
}
