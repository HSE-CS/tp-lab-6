// Copyright 2021 Danyaev Artem
#include "Manager.h"

ProjectManager::ProjectManager(unsigned int id_, const std::string& name_,
    Position pos, Project* project_)
    : Employee(id_, name_, pos) {
    projects.push_back(project_);
}

int ProjectManager::calcHeads() { return projects[0]->numOfWorkers * 300; }

int ProjectManager::calcProAdditions() { return 0; }

int ProjectManager::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * budget);
}

void ProjectManager::printInfo() {
    const char* positions[] = { "EMPLOYEE",      "PERSONAL",    "ENGINEER",
                               "CLEANER",       "DRIVER",      "PROGRAMMER",
                          "TESTER",        "TEAM_LEADER", "PROJECT_MANAGER",
                               "SENIOR_MANAGER" };
    std::cout << "Id: " << id << " Fio: " << name << std::endl
        << "Position: " << positions[position] << std::endl
        << "Projects: ";
    for (Project* p : projects) {
        std::cout << p->getName() << std::endl;
    }
    std::cout << "Worktime: " << worktime;
    std::cout << " Payment: " << payment << std::endl;
}

void ProjectManager::calc() {
    payment = calcHeads() + calcBudgetPart(1 / projects[0]->numOfWorkers,
        projects[0]->getBudget());
}

SeniorManager::SeniorManager(unsigned int id_, const std::string& name_,
    Position pos, const std::vector<Project*>& projects_)
    : ProjectManager(id_, name_, pos, projects_[0]) {
    projects = projects_;
}

int SeniorManager::calcHeads() {
    int res = 0;
    for (Project* p : projects) {
        res += p->numOfWorkers * 200;
    }
    return res;
}

void SeniorManager::calc() {
    payment = calcHeads();
    for (Project* p : projects) {
        payment += calcBudgetPart(1 / p->numOfWorkers, p->getBudget());
    }
}
