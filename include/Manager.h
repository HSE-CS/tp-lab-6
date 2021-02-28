// Copyright 2021 Islam Osmanov

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Engineer.h"
#include "Interfaces.h"
#include "Employee.h"


class ProjectManager : public Employee, public ProjectBudget, public Heading {
 private:
    int employees = 0;
    Project* project;
 public:
    ProjectManager(int id, std::string pos, std::string name,
                   int employees, Project* pr, int salary);
    void calc();
    int calcHeads();
    int getNumEmployees();
    Project* getProject();
    int calcBudgetPart(double piece, int budget);
    void printInfo();
    int calcProAdditions(int bonus);
};

class SeniorManager : public ProjectManager {
 private:
    std::vector<Project*> projects;
 public:
    SeniorManager(int id, std::string pos, std::string name,
                  std::vector<Project*> projects, int employees, int salary);
    void calc();
    std::vector<Project*> &getProjects();
    void addProject(Project* project);
};
#endif  // INCLUDE_MANAGER_H_
