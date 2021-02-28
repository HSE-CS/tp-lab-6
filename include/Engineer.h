// Copyright 2021 Artyom Lavrov


#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Interfaces.h"
#include "Personal.h"


class Engineer : public ProjectBudget, public Personal {
protected:
    Project* project;

public:
    int calcBudgetPart(float part, int budget) override;
    int calcBonus() override;
    void calc() override;
};


class Programmer : public Engineer {
public:
    Programmer(std::string id,
        std::string name,
        POSITION position,
        int salary,
        Project* project);
    int calcProAdditions() override;
};


class Tester : public Engineer {
public:
    Tester(std::string id,
        std::string name,
        POSITION position,
        int salary,
        Project* project);
    int calcProAdditions() override;
};


class TeamLeader : public Programmer, public Heading {
public:
    TeamLeader(std::string id,
        std::string name,
        POSITION position,
        int salary,
        Project* project);
    int calcHeads() override;
    void calc() override;
};


#endif  // INCLUDE_ENGINEER_H_
