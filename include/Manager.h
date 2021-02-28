// Copyright 2021 Kris

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Personal.h"
#include "Interfaces.h"
#include <string>
#include <vector>

class ProjectManager : public Employee{
 private:
    Project myProject;
    int salary;
 public:
    ProjectManager(int _id, std::string _name,
        std::string _pos, int _payment, Project currentProject);
    ProjectManager(int _id, std::string _name,
        std::string _pos, int _payment);
    void setProgect(int id_, int budget_);
    int calcBudgetPart(double part, int budget);
    int calcProAdditions();
    int calcHeads();
    int calc();
    void setsalary(int a);
    int getsalary();
    void printInfo();
};

class SeniorManager : public ProjectManager {
 private:
    std::vector<Project> Projects;
 public:
    SeniorManager(int _id, std::string _name, std::string _pos,
        int _payment, std::vector<Project> _Projects);
    void addProject(Project pr);
    int calcHeads();
    int calcProAdditions();
    int calc();
    void printInfo();
};



#endif  // INCLUDE_MANAGER_H_
