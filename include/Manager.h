// Copyright 2021 Sozinov Kirill

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Interfaces.h"
#include "Engineer.h"
#include <vector>

class Project;

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 protected:
     std::vector<Project> projects;
 public:
     ProjectManager(int _id, std::string _name, std::string _position, std::vector<Project> _projects);
     int calcHeads() override;
     void calc() override;
     float calcBudgetPart(float part, int budget) override;
     void printInfo() override;
     // int calcProAdditions() override;
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(int _id, std::string _name, std::string _position, std::vector<Project> _projects);
    int calcHeads() override;
    void calc() override;
    float calcBudgetPart(float part, int budget) override;
};

#endif  // INCLUDE_MANAGER_H_
