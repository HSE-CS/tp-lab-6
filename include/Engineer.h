// Copyright 2021 dash
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"
#include "Interfaces.h"
#include <string>

class Project;
class ProjectBudget;
class Heading;
class WorkBaseTime;

class Engineer : public Personal, public ProjectBudget {
public:
    Engineer(int id,
        std::string name,
        Position position,
        int worktime,
        int salary,
        int payment,
        Project* project);

        int calcBudgetPart(double part, int budget);
        virtual int calcBonus() override;
        void calc();
        Project* get_Project();
        void print_Info();
        virtual int calcProAdditions() override;
        Project* project;
};


class Programmer : public Engineer {
public:
    Programmer(int id,
        std::string name,
        Position position,
        int worktime,
        int salary,
        int payment,
        Project* project);
    virtual int calcProAdditions() override;
    void calc();
    void print_Info();
    void add_Bonus();
    virtual int calcBonus() override;
private:
    bool bonus;
};

class Tester : public Engineer {
public:
    Tester(int id,
        std::string name,
        Position position,
        int worktime,
        int salary,
        int payment,
        Project* project);
    virtual int calcProAdditions() override;
    void calc();
    void print_Info();
    virtual int calcBonus() override;
    virtual int calcBudgetPart(double part, int budget) override;
};

class TeamLeader : public Programmer, public Heading {
public:
    TeamLeader(int id,
        std::string name,
        Position position,
        int worktime,
        int salary,
        int payment,
        Project* project);
    virtual int calcHeads() override;
    void calc();
    void print_Info();
};

#endif  // INCLUDE_ENGINEER_H_