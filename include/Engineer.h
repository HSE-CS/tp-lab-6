// Copyright 2020 Golovanov
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Factory.h"
#include "Interfaces.h"
#include "Personal.h"

class Project;

class Engineer : public Personal, public ProjectBudget {
 protected:
    Project* project;
    float part;

 public:
    Engineer(int id, const std::string name, std::string position, int salary,
        int worktime, Project* _project, float part)
        : Personal(id, name, position, salary, worktime),
        project(_project),
        part(part) {}

    void printInfo();
    float getPart();
    int calcBudgetPart(float part, int budget);
};

class Tester : public Engineer {
 public:
    Tester(int id, const std::string name, std::string position, int salary,
        int worktime, Project* project, float part)
        : Engineer(id, name, position, salary, worktime, project, part) {}
    int calcProAdditions();
    int calc();
};

class Programmer : public Engineer {
 public:
    Programmer(int id, const std::string name, std::string position, int salary,
        int worktime, Project* project, float part)
        : Engineer(id, name, position, salary, worktime, project, part) {}
    int calcProAdditions();
    int calc();
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(int id, const std::string name, std::string position, int salary,
        int worktime, Project* project, float part)
        : Programmer(id, name, position, salary, worktime, project, part) {}
    int calcHeads();
    int calc();
};

#endif  // INCLUDE_ENGINEER_H_
