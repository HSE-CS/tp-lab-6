// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Personal.h"
#include "Interfaces.h"

class Engineer : public Personal, public ProjectBudget {
protected:
    Project *project;

public:
    int calcBudgetPart(float part, int budget) override;

    void calc() override;

    int calcBonus() override;
};


class Tester : public Engineer {
public:
    Tester(std::string id, std::string name, Position position,
           int salary, Project *project);

    int calcProAdditions() override;
};


class Programmer : public Engineer {
public:
    Programmer(std::string id, std::string name, Position position,
               int salary, Project *project);

    int calcProAdditions() override;
};


class TeamLeader : public Programmer, public Heading {
public:
    TeamLeader(std::string id, std::string name, Position position,
               int salary, Project *project);

    void calc() override;

    int calcHeads() override;
};


#endif //INCLUDE_ENGINEER_H_
