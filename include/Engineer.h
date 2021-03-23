// Copyright 2021 Vadukk
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include "Interfaces.h"

class Project;

class Engineer : public Personal, public ProjectBudget {
 private:
    Project *project;
    float part;
 public:
    Engineer(int id, const std::string name, std::string position, int salary,
        int worktime, Project* project, float part)
        : Personal(id, name, position, salary, worktime),
        project(project), part(part) {}
    int calcBudgetPart(float part, int budget);
    int calc();
    double getPart();
    void printInfo();
};

class Tester : public Engineer {
 public:
    Tester(int id, std::string name, std::string position, int salary,
        int worktime, Project* project, float part)
        : Engineer(id, name, position, salary, worktime, project, part) {}
    int calcProAdditions();
    int calc();
    void printInfo();
};

class Programmer : public Engineer {
 public:
    Programmer(int id, std::string name, std::string position, int salary,
        int worktime, Project* project, float part)
        : Engineer(id, name, position, salary, worktime, project, part) {}
    int calcProAdditions();
    int calc();
    void printInfo();
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(int id, const std::string name, std::string position, int salary,
        int worktime, Project* project, float part)
        : Programmer(id, name, position, salary, worktime, project, part) {}
    int calcHeads();
    int calc();
    void printInfo();
};
#endif  // INCLUDE_ENGINEER_H_
