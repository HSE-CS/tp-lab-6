// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"
#include "Interfaces.h"
#include "Project.h"
#include <string>

class Engineer : public Personal, public IProjectBudget {
 protected:
    Project* project;
 public:
    Engineer(int id, std::string name, int salary, Project* project);
    int calcBudgetPart(float part, int budget) override;
    void calc() override;
    void printInfo() override;
    int calcBonus() override {
        return 0;
    }
    int calcProAdditions() override {
        return 0;
    }
};

class Programmer : public Engineer {
 public:
    Programmer(int id, std::string name, int salary, Project* project);
    int calcProAdditions() override;
    int calcBonus() override {
        return 0;
    }
};

class Tester : public Engineer {
 public:
    Tester(int id, std::string name, int salary, Project* project);
    int calcProAdditions() override;
    int calcBonus() override {
        return 0;
    }
};

class TeamLeader : public IHeading, public Programmer {
 public:
    TeamLeader(int id, std::string name, int salary, Project* project);
    void calc() override;
    int calcHeads() override;
    int calcBonus() override {
        return 0;
    }
};

#endif  // INCLUDE_ENGINEER_H_
