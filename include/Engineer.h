// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Employee.h"
#include "Personal.h"
#include "Manager.h"

class Project;

class Engineer: public ProjectBudget, public Personal {
 private:
    Project* currentproject;

 public:
    Engineer(int ID, std::string name, int salary, Project* project) : Personal(ID, name, salary) {
        currentproject = project;
    }
    void calc() {
        payment = salary * worktime + calcBudgetPart(worktime/(currentproject->returnTime()), currentproject->returnBudget());
    }
    virtual int calcBudgetPart(float part, int budget);
};

class Programmer: public Engineer {
 public:
    Programmer(int ID, std::string name, int salary, Project* project) : Engineer(ID, name, salary, project) {
        position = "programmer";
    }
    virtual int calcProAdditions();
};

class Tester: public Engineer {
 public:
    Tester(int ID, std::string name, int salary, Project* project) : Engineer(ID, name, salary, project) {
        position = "tester";
    }
    virtual int calcProAdditions();
};

class TeamLeader: public Programmer, public Heading {
 public:
    TeamLeader(int ID, std::string name, int salary, Project* project) : Programmer(ID, name, salary, project) {
        position = "leader";
    }
    void calc() {}
    virtual int calcHeads();
};

#endif   // INCLUDE_ENGINEER_H_
