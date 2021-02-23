//// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include "Factory.h"
#include "Interfaces.h"
#include "Employee.h"

class ProjectManager : public Employee, Heading, ProjectBudget {
public:
    explicit ProjectManager(int id, const std::string &name,
                         const std::string &position,
                         Project *project)

                         : Employee(id, name, position),
                         project(project) {}

    ProjectManager(int id, const std::string &name,
                const std::string &position)
            : Employee(id, name, position) {}
    int calc() override;
    int calcBudgetPart(double p, int budget) override;
    int calcProAdditions() override;
    int calcHeads() override;
    Project *getProject();
    void printInfo() override;

private:
    Project *project = nullptr;
};

class SeniorManager : public ProjectManager {
public:
    explicit SeniorManager(int id, const std::string &name,
                           const std::string &position,
                           std::vector<Project *> projects)

                           : ProjectManager(id, name, position),
                            projects(std::move(projects)) {};
    std::vector<Project *> getProjects();
    int calc() override;
    int calcBudgetPart(double p, int budget) override;
    int calcProAdditions() override;
    int calcHeads() override;
    void printInfo() override;
private:
    std::vector<Project *> projects;
};

#endif  //  INCLUDE_MANAGER_H_

