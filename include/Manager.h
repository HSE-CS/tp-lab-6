// Copyright 2021 by Fatin Maxim
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Interfaces.h"
#include <iostream>
#include <string>

class ProjectManager : public Employee, public ProjectBudget,
    public Project, public Heading{
 protected:
    Project project;
 public:
    ProjectManager(int id, std::string name,
        Position position, std::string project);
    int calcHeads();
    void calc();
    int calcProAdditions();
    int calcBudgetPart(double part, int budget);
    void printInfo();
};

class SeniorManager : public ProjectManager{
 protected:
    Project project;
 public:
    SeniorManager(int id, std::string name, Position position,
        std::string project);
    void calc();
    int calcBudgetPart(double part, int budget);
};

#endif  // INCLUDE_MANAGER_H_
