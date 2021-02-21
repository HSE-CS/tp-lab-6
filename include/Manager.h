// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Factory.h"
#include "Interfaces.h"
#include "Employee.h"

class Project {
private:
    int id;
    double budget;
public:
    Project(int id, double budget);
    int getId();
    double getBudget();
};

class ProjectManager : public Employee, IHeading, IProjectBudget {
private:
    Project* project = nullptr;
public:
    ProjectManager(int id, const std::string& name,
        const std::string& position, double payment,
        Project* project)
        : Employee(id, name, position, payment),
        project(project) {}
    ProjectManager(int id, const std::string& name,
        const std::string& position, double payment)
        : Employee(id, name, position, payment) {}
    double calc() override;
    double calcHeads() override;
    Project* getProject();
    void printInfo() override;
    double calcBudgetPart(double part, double budget) override;
    double calcProAdditions() override;
};

class SeniorManager : public ProjectManager {
private:
    std::vector<Project*> projects;
public:
    explicit SeniorManager(int id,
        const std::string& name,
        const std::string& position, double payment,
        std::vector<Project*> projects)
        : ProjectManager(id, name, position, payment),
        projects(std::move(projects)) {}
    double calc() override;
    double calcBudgetPart(double part, double budget) override;
    double calcProAdditions() override;
    double calcHeads() override;
    std::string getProjects();
    void printInfo() override;
};

#endif  //  INCLUDE_MANAGER_H_