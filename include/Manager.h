//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Project.h"
#include "Interfaces.h"
#include <vector>
#include <string>

class Project;

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
    Project* linkToProject;
 public:
    ProjectManager(unsigned id, const std::string& name);
    unsigned calcHeads() override;
    void calc() override;
    unsigned calcBudgetPart() override;
    unsigned calcProAdditions() override;
    void setProject(Project* link);
    void printInfo() override;
};

class SeniorManager : public ProjectManager {
 protected:
    std::vector <Project*> projects;
 public:
    SeniorManager(unsigned id, std::string name);
    ~SeniorManager();
    unsigned getProjQuantity();
    void setProject(Project*);
    unsigned calcHeads() override;
    void calc() override;
    void printInfo() override;
};

#endif  //  INCLUDE_MANAGER_H_
