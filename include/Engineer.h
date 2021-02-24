// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include "Interfaces.h"
struct Project {
    int id;
    int budget;
};
class Engineer: public Personal, public ProjectBudget{
 private:
    Project project;

 public:
    Engineer(int id, std::string name, std::string pos,
         int worktime, int payment, Project project_)
        :Personal(id, name, pos, worktime, payment), project{project_} {};
    Project getProject();
    int calcBudgetPart(float part, int budget) override;
    int calc() override;
    void printInfo() override;
};

class Tester: public Engineer {
 public:
    Tester(int id, std::string name, std::string pos,
         int worktime, int payment, Project project_)
        :Engineer(id, name, pos, worktime, payment, project_) {}
    int calcAdditions();
    int calcBonus() override;
    int calcProAdditions() override;
    int calc() override;
    void printInfo() override;
};

class Programmer: public Engineer {
 public:
    Programmer(int id, std::string name,
         std::string pos, int worktime, int payment, Project project_)
        :Engineer(id, name, pos, worktime, payment, project_) {}
    int calcProAdditions() override;
    int calcBonus() override;
    int calc() override;
    void printInfo() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(int id, std::string name, std::string pos, int worktime,
         int payment, Project project_)
        :Programmer(id, name, pos, worktime, payment, project_) {}
    int calcHeads();
    int calc() override;
    int calcBonus() override;
    void printInfo() override;
};
#endif  // INCLUDE_ENGINEER_H_
