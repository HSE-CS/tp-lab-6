// Copyright 2021 Kris

#ifndef MANAGER_INCLUDE_H_
#define MANAGER_INCLUDE_H_

#include "Employee.h"
#include "Personal.h"
#include "Interfaces.h"

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



#endif // !MANAGER_INCLUDE_H_
