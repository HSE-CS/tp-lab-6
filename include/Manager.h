// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include <string>
#include "Interfaces.h"
#include "Employee.h"

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
    std::vector<Project *> projects;
 public:
    ProjectManager(std::string id, std::string name, Position position,
                   std::vector<Project *> projects);

    void setProjects(std::vector<Project *> projects);

    std::vector<Project *> &getProjects();

    int calcHeads() override;

    void calc() override;

    int calcBudgetPart(float part, int budget) override;

    int calcProAdditions() override;

    void printInfo() override;
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(std::string id, std::string name, Position position,
                  std::vector<Project *> projects);

    void calc() override;
};

#endif  // INCLUDE_MANAGER_H_
