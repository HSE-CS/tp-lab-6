// Copyright 2021 by Fatin Maxim
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Interfaces.h"
#include"Personal.h"

class Engineer : public ProjectBudget, public Project, public Personal{
 protected:
    Project project;
 public:
    Engineer(unsigned int id, std::string name, Position position,
        std::string project, unsigned int salary);
    unsigned int calcBudgetPart(double part, unsigned int budget);
    void calc();
    void printInfo();
    unsigned int calcProAdditions();
};

class Tester : public Engineer {
 public:
    Tester(unsigned int id, std::string name, Position position,
        std::string project, unsigned int salary);
    void calc();
    void printInfo();
    unsigned int calcProAdditions();
};

class Programmer : public Engineer {
 public:
    Programmer(unsigned int id, std::string name, Position position,
        std::string project, unsigned int salary);
    unsigned int calcProAdditions();
    void calc();
    void printInfo();
};

class TeamLead : public Programmer {
 public:
    TeamLead(unsigned int id, std::string name, Position position,
        std::string project, unsigned int salary);
    unsigned int calcProAdditions();
    void calc();
    void printInfo();
    unsigned int  calcHeads();
};

#endif // INCLUDE_ENGINEER_H_
