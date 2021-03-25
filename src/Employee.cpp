// Copyright 2021 Shatilov Victor

#include "Employee.h"

#include <utility>
#include <iostream>

Employee::Employee(int id, std::string  name,
                   int workTime, Positions position)
        : id(id),
        workTime(workTime), name(std::move(name)), position(position),
        payment(0) {
}

std::string Employee::getPositionAsStr() {
    const char* positions[] = {
            "EMPLOYEE",
            "PERSONAL",
            "ENGINEER",
            "CLEANER",
            "DRIVER",
            "PROGRAMMER",
            "TESTER",
            "TEAM_LEADER",
            "PROJECT_MANAGER",
            "SENIOR_MANAGER" };
    return positions[position];
}

Positions Employee::getPositionAsEnum(std::string p) {
    const char* positions[] = {
            "EMPLOYEE",
            "PERSONAL",
            "ENGINEER",
            "CLEANER",
            "DRIVER",
            "PROGRAMMER",
            "TESTER",
            "TEAM_LEADER",
            "PROJECT_MANAGER",
            "SENIOR_MANAGER" };
    for (int i = 0; i < sizeof(positions)/sizeof(positions[0]); i++)
        if (positions[i] == p)
            return (Positions) i;
    return EMPLOYEE;
}

int Employee::calc() {
    return 0;
}

void Employee::printInfo() {
    std::cout << name << " on " << this->getPositionAsStr() << std::endl;
    std::cout << "With payment: " << payment << std::endl;
    std::cout << "Work time: " << workTime <<std::endl;
}

void Employee::setWorkTime(int wt) {
    workTime = wt;
}

Project::Project(int id, const std::string& name,
                 int budget,  int countWorkers)
        : id(id), name(std::move(name)),
        budget(budget), countWorkers(countWorkers) {}

std::string Project::getName() { return name; }
int Project::getBudget() const { return budget; }
int Project::getCountWorkers() const { return countWorkers; }

