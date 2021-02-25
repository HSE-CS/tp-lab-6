// Copyright 2021 by Fatin Maxim
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Interfaces.h"
#include"Personal.h"
#include <string>

class Engineer : public ProjectBudget, public Project, public Personal{
 protected:
    Project project;
 public:
    Engineer(int id, std::string name, Position position,
        std::string project, int salary);
    int calcBudgetPart(double part, int budget);
    void calc();
    void printInfo();
    int calcProAdditions();
};

class Tester : public Engineer {
 public:
    Tester(int id, std::string name, Position position,
        std::string project, int salary);
    void calc();
    void printInfo();
    int calcProAdditions();
};

class Programmer : public Engineer {
 public:
    Programmer(int id, std::string name, Position position,
        std::string project, int salary);
    int calcProAdditions();
    void calc();
    void printInfo();
};

class TeamLead : public Programmer {
 public:
    TeamLead(int id, std::string name, Position position,
        std::string project, int salary);
    int calcProAdditions();
    void calc();
    void printInfo();
    int  calcHeads();
};

#endif  // INCLUDE_ENGINEER_H_
