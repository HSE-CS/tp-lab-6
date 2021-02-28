// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include "Personal.h"
#include "Manager.h"
#include <string>

class Engineer : public Personal, public ProjectBudget {
 public:
    void calc() override;
    void printInfo() override;
    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    int calcBonus() override;
    Engineer(int id, std::string name, Position position,
        int worktime, int salary, Project* project);
 protected:
     Project* project;
};

class Programmer : public Engineer {
 public:
    int calcProAdditions() override;
    Programmer(int id, std::string name, Position position,
        int worktime, int salary, Project* project);
    void giveBonus();
    bool getBonus();
 private:
     bool bonus;
};

class Tester : public Engineer {
 public:
    int calcProAdditions() override;
    Tester(int id, std::string name, Position position,
        int worktime, int salary, Project* project);
    void addMistakes(int mistakes = 1);
    int getMistakes();
 private:
     int mistakes = 0;
};

class TeamLeader : public Programmer, public Heading {
 public:
    void calc() override;
    int calcHeads() override;
    TeamLeader(int id, std::string name, Position position,
        int worktime, int salary, Project* project);
};

#endif  // INCLUDE_ENGINEER_H_
