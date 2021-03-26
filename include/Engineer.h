// Copyright 2021 Ziganshin Nikita

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Interfaces.h"
#include "Personal.h"
#include "Manager.h"
#include <string>

class Engineer : public ProjectBudget, public Personal {
 protected:
    Project project;
 public:
    Engineer(unsigned int id, std::string name, unsigned int salary);
    unsigned int calcBudgetPart(float part) override = 0;
    void calc() override;
    unsigned int calcProAdditions() override = 0;
    unsigned int calcBonus() override = 0;
    void printInfo() override = 0;
};

class Programmer : public Engineer {
 public:
    Programmer(unsigned int id, std::string name,
               unsigned int salary, Project project);
    Programmer(unsigned int id, std::string name, unsigned int salary);
    unsigned int calcBudgetPart(float part) override;
    unsigned int calcProAdditions() override;
    unsigned int calcBonus() override;
    void printInfo() override;
};

class Tester : public Engineer {
 public:
    Tester(unsigned int id, std::string name,
           unsigned int salary, Project project);
    unsigned int calcBudgetPart(float part) override;
    unsigned int calcProAdditions() override;
    unsigned int calcBonus() override;
    void printInfo() override;
    Tester(unsigned int id, std::string name, unsigned int salary);
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(unsigned int id, std::string name,
               unsigned int salary, Project project);
    TeamLeader(unsigned int id, std::string name, unsigned int salary);
    unsigned int calcHeads() override;
    unsigned int calcBudgetPart(float part) override;
    unsigned int calcProAdditions() override;
    unsigned int calcBonus() override;
    void calc() override;
    void printInfo() override;
};

#endif  // INCLUDE_ENGINEER_H_
