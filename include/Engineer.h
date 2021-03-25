// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_


#include "Personal.h"

class Engineer : public Personal, public ProjectBudget {
 protected:
    Project *project = nullptr;
    int bonus = 0;
    int calcBudgetPart() override;
    int calcProAdditions() override;
 public:
    Engineer(int id, std::string name,
             int workTime, int salary, Positions position, Project *p);
    int calc() override;
    void printInfo() override;
};

class Tester : public Engineer {
 private:
    int bonus = 4;
 public:
    Tester(int id, const std::string& name,
           int workTime, int salary, Positions position, Project *p);
};

class Programmer : public Engineer {
private:
    int bonus = 5;
public:
    Programmer( int id, const std::string& name,
                int workTime, int salary, Positions position, Project *p);
};

class TeamLeader : public Programmer, public Heading {
private:
     int calcHeads() override;
public:
    TeamLeader( int id, const std::string& name,
                int workTime, int salary, Positions position, Project *p);
    int calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
