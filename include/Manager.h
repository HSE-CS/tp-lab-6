// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class Project {
 protected:
    std::string title;
    int budget = 0;
    int time = 0;
    int numofPeople = 0;

 public:
    Project(std::string name, int budget) {
        this->title = name;
        this->budget = budget;
    }
    void addPerson();
    std::string returnName();
    int returnPeoplesNumber();
    int returnBudget();
    int returnTime();
};

class ProjectManager: public Employee, public Heading, public Project {
 private:
    Project* projectname;

 public:
    ProjectManager(std::string ID, std::string
                   name, std::string position, Project* project)
    : Employee(ID, name, position), Project(*project) {
        this->position = position;
        projectname = project;
    }
    void calc();
    void printInfo();
    int calcBudgetPart();
    virtual int calcHeads();
};

class SeniorManager: public ProjectManager {
 private:
    std::vector <Project*> projectnames;

 public:
    SeniorManager(std::string ID, std::string name, Project* project)
    : ProjectManager(ID, name, "senior", project) {
        projectnames.push_back(project);
        position = "senior";
    }
    int calcBudgetPart();
    void addProject(Project* newproj);
    void printInfo();
    void calc();
};

#endif   // INCLUDE_MANAGER_H_
