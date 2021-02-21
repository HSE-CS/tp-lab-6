//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_ENGINEER_H
#define TP_LAB_6_ENGINEER_H

#include <vector>
#include "Personal.h"
#include "Interfaces.h"

class Project;

class Engineer : public Personal, public IProjectBudget {
protected:
    Project* project;
    float part;
public:
    Engineer(int id, const std::string &name, Position position, int salary,
             Project *project, float part);

    int calcBudgetPart(float part, int budget) override;
};

class Tester : public Engineer {
public:
    Tester(int id, const std::string &name, Position position, int salary,
           Project *project, float part);
protected:
    int calcProAdditions() override;
    void calc() override;
};

class Programmer : public Engineer {
public:
    Programmer(int id, const std::string &name, Position position, int salary,
               Project *project, float part);
protected:
    int calcProAdditions() override;
    void calc() override;
};

class TeamLeader : public Programmer, public IHeading {
public:
    TeamLeader(int id, const std::string &name, Position position, int salary,
               Project *project, float part);
protected:
    int calcHeads() override;
    void calc() override;
};


#endif //TP_LAB_6_ENGINEER_H
