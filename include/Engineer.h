// Copyright 2021 MalininDmitry

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <string>
#include "Factory.h"
#include "Personal.h"
#include "Interfaces.h"

class Engineer : public IProjectBudget, public Personal {
 protected:
    Project* project;
    float part;
 public:
    Engineer(unsigned int id, std::string name,
             std::string position, unsigned int payment,
             Project* project, float part);
    int calcBudgetPart(float part, int budget) override;
    void printInfo() override;
};

class Tester : public Engineer {
 public:
    Tester(unsigned int id, std::string name,
           std::string position, unsigned int payment,
           Project* project, float part);
    int calcProAdditions() override;
    void calc() override;
};

class Programmer : public Engineer {
 public:
    Programmer(unsigned int id, std::string name,
               std::string position, unsigned int payment,
               Project* project, float part);
    int calcProAdditions() override;
    void calc() override;
};

class TeamLeader : public Engineer, public IHeading {
 public:
    TeamLeader(unsigned int id, std::string name,
               std::string position, unsigned int payment,
               Project* project, float part);
    int calcProAdditions() override;
    int calcHeads() override;
    void calc() override;
};

#endif  // INCLUDE_ENGINEER_H_

