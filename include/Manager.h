//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Project.h"
#include "Interfaces.h"

class Project;

class Manager : public Employee, public ProjectBudget, public Heading {
 protected:
    Project* linkToProject;
 public:
    Manager(unsigned id, const std::string& name);
    unsigned calcHeads() override;
    void calc() override;
    unsigned calcBudgetPart() override;
    unsigned calcProAdditions() override;
    void setProject(Project* link);
};

class SeniorManager : public Manager {
 protected:
    std::vector <Project*> projects;
 public:
    SeniorManager(unsigned id, std::string name);
    ~SeniorManager();
    unsigned calcHeads() override;
    void calc() override;
};

#endif  //  INCLUDE_MANAGER_H_
