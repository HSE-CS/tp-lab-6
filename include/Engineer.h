// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Personal.h"
#include "Manager.h"


class Project;

class Engineer: public Personal {
 protected:
    Project* currentproject;

 public:
    Engineer(std::string ID, std::string name,
             std::string position, int salary, Project* project)
    : Personal(ID, name, position, salary) {
        currentproject = project;
        this->position = position;
    }
    void calc();
    void printInfo();
    Project* returnProject();
    virtual int calcBudgetPart();
    virtual int calcProAdditions();
};

class Programmer: public Engineer {
 protected:
    int hourspercode = 0;

 public:
    Programmer(std::string ID, std::string name,
               std::string position, int salary, Project* project)
    : Engineer(ID, name, position, salary, project) {
        this->position = position;
    }
    void spendHours(int number);
    int calcProAdditions();
};

class Tester: public Engineer {
 protected:
    int errorsfound = 0;

 public:
    Tester(std::string ID, std::string name, int salary, Project* project)
    : Engineer(ID, name, "tester", salary, project) {
        position = "tester";
    }
    void errors(int number);
    int calcProAdditions();
};

class TeamLeader: public Programmer, public Heading {
 public:
    TeamLeader(std::string ID, std::string name, int salary, Project* project)
    : Programmer(ID, name, "leader", salary, project) {
        position = "leader";
    }
    void calc();
    void printInfo();
    int calcHeads();
};

#endif   // INCLUDE_ENGINEER_H_
