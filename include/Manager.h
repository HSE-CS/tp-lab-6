// Copyright 2021 Vadukk
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Factory.h"
#include "Interfaces.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
    std::vector<Project*> project;
    float part;

 public:
    ProjectManager(int id, const std::string name, std::string position,
        int numProjects, int payment, int worktime,
        const std::vector<Project*>& projects)
        : Employee(id, name, position, payment, worktime) {
        for (int i = 0; i < numProjects; i++) project.push_back(projects[i]);
    }
    void printInfo();
    int calcBudgetPart(float part, int budget);
    int calcProAdditions();
    int calcHeads();
    int calc();
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(int id, std::string name, std::string position,
        int numProjects, int worktime, int payment,
        const std::vector<Project*>& project)
        : ProjectManager(id, name, position, numProjects, payment, worktime,
            project) {}
};
#endif  // INCLUDE_MANAGER_H_