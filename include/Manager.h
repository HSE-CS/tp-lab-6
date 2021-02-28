// Copyright 2021 dmitrycvetkov2000
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Interfaces.h"
#include "Employee.h"
#include "Project.h"

#include <unordered_set>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
public:
    ProjectManager(int id,
        const std::string& name);
    ProjectManager(int id,
        const std::string& name,
        Project* project,
        float part);

    int calcBudget(float part) const override;
    int calcProAdditions() const override;
    int calcHeads() const override;
    void calc() override;

    void printInfo() const override;

protected:
    std::unordered_set<Project*> projects;
    float part;
};

class SeniorManager : public ProjectManager {
public:
    SeniorManager(int id,
        const std::string& name,
        std::unordered_set<Project*> &&projects);

    int calcBudget(float part) const override;
    int calcProAdditions() const override;
    int calcHeads() const override;
    void calc() override;

    void printInfo() const override;
};


#endif  // INCLUDE_MANAGER_H_