// Copyright 2021 asma
#pragma once
#ifndef MANAGER_H_
#define MANAGER_H_

#include "Interfaces.h"
#include "Employee.h"
#include "Project.h"
#include <string>
#include <vector>


class ProjectManager : public Employee, public Heading, public ProjectBudjet {
 protected:
    Project* project;
    double part;
 public:
    ProjectManager() {}
    ProjectManager(int, std::string, Position, Project*, double);
    void Calc();
    int CalcHeads() const;
    void PrintInfo() const;
    int CalcBudgetPart() const;
    std::string GetPosition() const;
    int CalcProAdditions() const;
    void SetPart(double);
    void SetProject(Project*);
};

class SeniorManager : public ProjectManager {
 protected:
    std::vector<Project*> projects;
 public:
    SeniorManager(int, std::string, Position, std::vector<Project*>);
    void Calc();
    std::string GetPosition() const;
    int CalcBudgetPart() const;
    int CalcProAdditions() const;
    void AppendProject(Project*);
};

#endif  // MANAGER_H_
