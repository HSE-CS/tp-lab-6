// Copyright [2021] <Roman Balayan>

#pragma once

#include <string>
#include <memory>

#include "Personal.h"
#include "Interfaces.h"

class Engineer :  public Personal,  public IProjectBudget {
 public:
    Engineer(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary,
        std::shared_ptr<Project> project);
    int calcBudgetPart(float part, int budget) override;
    void calc() override;
 protected:
    std::shared_ptr<Project> project;
};

class Programmer :  public Engineer {
 public:
    Programmer(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary,
        std::shared_ptr<Project> project);
    int calcProAdditions() override;
    void printInfo() override;
};

class Tester :  public Engineer {
 public:
    Tester(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary,
        std::shared_ptr<Project> project);
    int calcProAdditions() override;
    void printInfo() override;
};

class TeamLeader :  public Programmer,  public IHeading {
 public:
    int calcHeads() override;
    void calc() override;
};
