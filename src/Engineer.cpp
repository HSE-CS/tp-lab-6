// Copyright 2021 Danyaev Artem
#include "Engineer.h"

Engineer::Engineer(unsigned int id_, const std::string& name_, Position pos,
    int salary_, Project* project_)
    : Personal(id_, name_, pos, salary_), project(project_) {}

int Engineer::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * budget);
}

void Engineer::printInfo() {
    const char* positions[] = { "EMPLOYEE",      "PERSONAL",    "ENGINEER",
                               "CLEANER",       "DRIVER",      "PROGRAMMER",
                          "TESTER",        "TEAM_LEADER", "PROJECT_MANAGER",
                               "SENIOR_MANAGER" };
    std::cout << "Id: " << id << " Fio: " << name << std::endl
        << "Position: " << positions[position] << " Salary: " << salary
        << std::endl;
    std::cout << "Project: " << project->getName() << " Worktime: " << worktime
        << " Payment: " << payment << std::endl;
}

int Engineer::calcBonus() { return 0; }

void Engineer::calc() {
    payment = calcBase(salary, worktime) +
        calcBudgetPart(1 / project->numOfWorkers, project->getBudget()) +
        calcProAdditions();
}

Programmer::Programmer(unsigned int id_, const std::string& name_, Position pos,
    int salary_, Project* project_)
    : Engineer(id_, name_, pos, salary_, project_) {}

int Programmer::calcProAdditions() { return 1000; }

Tester::Tester(unsigned int id_, const std::string& name_, Position pos,
    int salary_, Project* project_)
    : Engineer(id_, name_, pos, salary_, project_) {}

int Tester::calcProAdditions() { return 500; }

TeamLeader::TeamLeader(unsigned int id_, const std::string& name_, Position pos,
    int salary_, Project* project_)
    : Programmer(id_, name_, pos, salary_, project_) {}

int TeamLeader::calcProAdditions() { return 0; }

int TeamLeader::calcHeads() { return project->numOfWorkers * 200; }
void TeamLeader::calc() {
    payment = calcBase(salary, worktime) +
        calcBudgetPart(1 / project->numOfWorkers, project->getBudget()) +
        calcHeads();
}
