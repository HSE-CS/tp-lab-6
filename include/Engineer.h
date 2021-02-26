// Copyright 2021 JGMax

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"

class Engineer: public Personal, public ProjectBudget {
 protected:
    Project* project;
    double proAdditionK;
 public:
    Engineer(int id,
             std::string fullName,
             int workTime,
             Position position,
             int salary,
             Project* project);
    int calcBudgetPart() override;
    int calcProAdditions() override;
    void calc() override;
    void setProAddition(double proAddition);
    void printInfo() override;
};

class Programmer : public Engineer {
 public:
    Programmer(int id,
               std::string fullName,
               int workTime,
               Position position,
               int salary,
               Project* project);

    virtual void setProAddition();
    void calc() override;
};

class Tester : public Engineer {
 public:
    Tester(int id,
           std::string fullName,
           int workTime,
           Position position,
           int salary,
           Project* project);
    void setProAddition();
    void calc() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(int id,
               std::string fullName,
               int workTime,
               Position position,
               int salary,
               Project* project);
    int calcHeads() override;
    void setProAddition() override;
    void printInfo() override;
    void calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
