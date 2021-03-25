// Copyright 2021 dash
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include <memory>
#include <iostream>
#include <string> 

#include "Interfaces.h"
#include "Employee.h"

class ProjectManager : public Employee,
    public ProjectBudget,
    public Heading {
 public:
    ProjectManager(int id,
        std::string name,
        Position position,
        int worktime,
        int payment,
        Project project);
    int calcHeads() override;
    void calc() override;
    void print_Info() override;
    int calcProAdditions() override;
    int calcBudgetPart(double part, int budget) override;
 private:
    std::vector<Project*> projects;
    double part;
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(int id,
        std::string name,
        Position position,
        int worktime,
        int payment,
        Project project);
    void calc() override;
    void print_Info() override;
 private:
    std::vector<Project*> projects;
    double part;
};

#endif  // INCLUDE_MANAGER_H_
