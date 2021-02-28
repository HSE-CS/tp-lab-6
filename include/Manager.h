// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"

class Project {
 protected:
    int ID;
    int budget = 0;
    int time = 0;

 public:
    Project(int ID, int budget) {
        this->ID = ID;
        this->budget = budget;
    }
    int returnBudget() {
        return budget;
    }
    int returnTime() {
        return time;
    }
};

class ProjectManager: public Employee, public Heading, public ProjectBudget {
 private:
    Project* projectname;

 public:
    ProjectManager(int ID, std::string name, Project* project) : Employee(ID, name) {
        position = "manager";
        projectname = project;
    }
    void calc() {}
    virtual int calcHeads();
};

class SeniorManager: public ProjectManager {
 private:
    std::vector <Project*> projectname;

 public:
    SeniorManager(int ID, std::string name, Project* project) : ProjectManager(ID, name, project) {
        projectname.push_back(project);
        position = "senior";
    }
    void addProject(Project* newproj) {
        projectname.push_back(newproj);
    }
    void calc() {}
};

#endif   // INCLUDE_MANAGER_H_
