// Copyright 2021
#ifndef INCLUDE_PROJECTMANAGER_H_
#define INCLUDE_PROJECTMANAGER_H_
#include <vector>
#include <string>
#include "ProjectBudget.h"
#include "Project.h"
#include "Employee.h"
#include "Heading.h"

class ProjectManager : public ProjectBudget, public Employee, public Heading {
 private:
    Project* project;
 public:
    ProjectManager(int id, std::string name,
        std::string position) :
        Employee(id, name, position) {}
    ProjectManager(int id, std::string name,
        std::string position, Project * project)
        : Employee(id, name, position) {
        this->project = project;
    }
    double calcBudgetPart(double part, double budget) override;
    void calc() override;
    void printInfo() override;
    int calcHeads() override;
    double calcProAdditions() override;
};
#endif  // INCLUDE_PROJECTMANAGER_H_
