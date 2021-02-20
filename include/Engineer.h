//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_ENGINEER_H
#define TP_LAB_6_ENGINEER_H

#include "Personal.h"
#include "Interfaces.h"

class Engineer : public Personal, public IProjectBudget {
public:
    int calcBudgetPart(float part, int budget) override;
};

class Tester : public Engineer {
public:
    int calcProAdditions() override;
    void calc() override;
};

class Programmer : public Engineer {
public:
    int calcProAdditions() override;
    void calc() override;
};

class TeamLeader : public Programmer, public IHeading {
public:
    int calcHeads() override;
    void calc() override;
};


#endif //TP_LAB_6_ENGINEER_H
