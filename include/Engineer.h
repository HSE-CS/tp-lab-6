// Copyright 2021 dmitrycvetkov2000
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"

#include "Project.h"

#include <string>

class Engineer : public Personal, public ProjectBudget {
 public:
    virtual ~Engineer() = default;

    int calcBonus() const override;
    int calcBudget(float part) const override;
    int calcProAdditions() const override;
    void calc() override;
    void printInfo() const override;

 protected:
    Engineer(int id,
        const std::string& name,
        int salary,
        Position position,
        Project* project,
        float part);

    Project* project;
    float part;
};

class Programmer : public Engineer {
 public:
    Programmer(int id,
        const std::string& name,
        int salary,
        Project* project,
        float part);

    int calcBonus() const override;
    int calcBudget(float part) const override;
    void calc() override;
    void printInfo() const override;
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(int id,
        const std::string& name,
        int salary,
        Project* project,
        float part);

    int calcBonus() const override;
    int calcHeads() const override;
    void printInfo() const override;
};

class Tester : public Engineer {
 public:
    Tester(int id,
        const std::string& name,
        int salary,
        Project* project,
        float part);

    int calcBonus() const override;
    int calcBudget(float part) const override;
    void printInfo() const override;
};


#endif  // INCLUDE_ENGINEER_H_
