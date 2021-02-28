// Copyright 2021 Islam Osmanov

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <iostream>
#include <vector>
#include <string>
#include "Manager.h"
#include "Personal.h"
#include "Factory.h"

class Engineer : public Personal, public ProjectBudget {
 private:
    Project* project;
 public:
    virtual void calc();
    void printInfo();
    virtual int calcBudgetPart(double piece, int budget);
    Project* getProject();
    Engineer(int id, std::string pos, std::string name,
             int payment, Project *project1);
};

class Tester : public Engineer{
 private:
    int mistakes_num = 0;
 public:
    virtual int calcProAdditions(int bonus);
    void addErrors();
    int getErrorsNum();
    Tester(int id, std::string pos, std::string name,
               int payment, Project *project1);
};

class Programmer : public Engineer {
 public:
    virtual int calcProAdditions(int bonus);
    Programmer(int id, std::string pos, std::string name,
             int payment, Project *project1);
};

class TeamLeader : public Heading, public Programmer {
 private:
    int programmers_num = 0;
 public:
    int getProgrammers();
    virtual void calc();
    virtual int calcHeads();
    TeamLeader(int id, std::string pos, std::string name,
               int payment,
               int programmers, Project *project1);
};

#endif  // INCLUDE_ENGINEER_H_
