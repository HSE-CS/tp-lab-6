// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <string>
#include <vector>
#include "Factory.h"
#include "Personal.h"
#include "Manager.h"

class Engineer : public Personal, IProjectBudget {
private:
    Project* project;
public:
    explicit Engineer(int id, std::string name,
        std::string position, double payment,
        Project* project)
        : Personal(id, name, position, payment),
        project(project) {}
    Project* getProject();
    double calc() override;
    double calcBonus() override;
    double calcBase(double payment, int time) override;
    double calcBudgetPart(double part, double budget) override;
    double calcProAdditions() override;
    void printInfo() override;
};

class Programmer : public Engineer {
public:
    Programmer(int id, std::string name,
        std::string position, double payment,
        Project* project)
        : Engineer(id, name, position, payment,
            project) {}
    double calc() override;
    double calcBonus() override;
    double calcBase(double payment, int time) override;
    double calcBudgetPart(double part, double budget) override;
    double calcProAdditions() override;
    void printInfo() override;
};

class Tester : public Engineer {
private:
    int mistakes_counter = 0;
public:
    Tester(int id, std::string name,
        std::string position, double payment,
        Project* project)
        : Engineer(id, name, position, payment,
            project) {}
    double calc() override;
    double calcBonus() override;
    double calcBase(double payment, int time) override;
    double calcBudgetPart(double part, double budget) override;
    double calcProAdditions() override;
    void printInfo() override;
};

class TeamLeader : public Programmer, IHeading {
public:
    TeamLeader(int id, std::string name,
        std::string position, double payment,
        Project* project)
        : Programmer(id, name, position, payment,
            project) {}
    double calc() override;
    double calcBonus() override;
    double calcBase(double payment, int time) override;
    double calcBudgetPart(double part, double budget) override;
    double calcProAdditions() override;
    double calcHeads() override;
    void printInfo() override;
};

#endif  //  INCLUDE_ENGINEER_H_
