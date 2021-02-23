//// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include "Interfaces.h"
#include "Employee.h"

class Project;

class ProjManager : public Employee, Heading, ProjectBudget {
public:
    explicit ProjManager(int id, const std::string &name,
                         const std::string &position,
                         Project *project)

                         : Employee(id, name, position),
                         project(project) {}

    ProjManager(int id, const std::string &name,
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

class SeniorManager : public ProjManager {
public:
    explicit SeniorManager(int id, const std::string &name,
                           const std::string &position,
                           std::vector<Project *> projects)

                           : ProjManager(id, name, position),
                            projects(std::move(projects)) {}
    int calc() override;
    int calcBudgetPart(double p, int budget) override;
    int calcProAdditions() override;
    int calcHeads() override;
    void printInfo() override;
private:
    std::vector<Project *> projects;
};

#endif  //  INCLUDE_MANAGER_H_

