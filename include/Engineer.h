// Copyright 2021
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <string>
#include "ProjectBudget.h"
#include "Personal.h"
#include "Project.h"

class Engineer : public Personal, ProjectBudget {

protected:
    Project* project;
public:
    Engineer(int id, std::string name,
        std::string position, double salary, Project * project)
        :Personal(id, name, position, salary) 
    {
        this->project = project;
    };
    double calcBudgetPart(double part, double budget) override;
    void printInfo() override;
};
#endif // !INCLUDE_ENGINEER_H_
