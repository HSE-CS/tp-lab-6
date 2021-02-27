#pragma once

#include "Personal.h"
#include "Interfaces.h"

class Engineer : public Personal, public IProjectBudget {
public:
    Engineer(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary,
        std::shared_ptr<Project> project);
    virtual int calcBudgetPart(float part, int budget) override;
    virtual void calc() override;
protected:
    std::shared_ptr<Project> project;
};

class Programmer : public Engineer {
public:
    Programmer(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary,
        std::shared_ptr<Project> project);
    virtual int calcProAdditions() override;
    virtual void printInfo() override;
};

class Tester : public Engineer {
public:
    Tester(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary,
        std::shared_ptr<Project> project);
    virtual int calcProAdditions() override;
    virtual void printInfo() override;
};

class TeamLeader : public Programmer, public IHeading {
public:
    virtual int calcHeads() override;
    virtual void calc() override;
};