// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <string>
#include <vector>
#include <iostream>
#include "Employee.h"
#include "Interfaces.h"

class Project {
 public:
    unsigned int id;
    unsigned int budget;
    Project(unsigned int _id, unsigned int _budget);
    unsigned int programmers = 0;
    unsigned int testers = 0;
    float calcPart(POSITION _position);
};

class ProjectManager : public Employee,
public Heading, public ProjectBudget {
 protected:
    std::vector<Project*> projects;

 public:
    ProjectManager(unsigned int _id, std::string _name,
                  POSITION _position, std::vector<Project*> _projects);
    void calc() override;
    unsigned int calcBudgetPart(float _part, unsigned int _budget) override;
    unsigned int calcProAdditions() override;
    unsigned int calcHeads() override;
    void printInfo() override;
    std::vector<Project*> getProjects();
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(unsigned int _id, std::string _name,
                  POSITION _position, std::vector<Project*> _projects);
};

#endif  //  INCLUDE_MANAGER_H_
