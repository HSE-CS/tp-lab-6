// Copyright 2021 Artyom Lavrov


#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include <string>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager :
    public Employee,
    public ProjectBudget,
    public Heading {
protected:
    std::vector<Project*> projects;
public:
    ProjectManager(std::string id,
        std::string name,
        POSITION position,
        std::vector<Project*> projects);
    const std::vector<Project*>& GetProjects() const;
    void SetProjects(const std::vector<Project*>& projects);
    int calcHeads() override;
    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    void calc() override;
    void printInfo() override;
};


class SeniorManager : public ProjectManager {
public:
    SeniorManager(std::string id,
        std::string name,
        POSITION position,
        std::vector<Project*> projects);
    void calc() override;
};


#endif  // INCLUDE_MANAGER_H_
