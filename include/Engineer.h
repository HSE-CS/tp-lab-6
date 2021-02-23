//// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_ENGINEER_H
#define INCLUDE_ENGINEER_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include "Factory.h"
#include "Personal.h"
#include "Interfaces.h"

class Engineer : public Personal, public ProjectBudget {
 protected:
    Project *project;
    float part;

 public:
    Engineer(int id, const std::string name, std::string position,
             int salary, int worktime, Project *project, float part);
    int calc() override;
    void setProject(Project *p);
    Project *getProject();
    void printInfo() override;
    int calcBudgetPart(double part, int budget) override;
};

class Tester : public Engineer {
 protected:
    int calcProAdditions() override;

 public:
    Tester(int id, const std::string name, std::string position,
           int salary, int worktime, Project *project, float part)

           : Engineer(id, name, position, salary,
                      worktime, project, part) {}
};

class Programmer : public Engineer {
 protected:
    int calcProAdditions() override;

 public:
    Programmer(int id, const std::string name, std::string position,
               int salary, int worktime, Project *project, float part)

               : Engineer(id, name, position, salary,
                       worktime, project, part) {}
};

class TeamLeader : public Programmer, public Heading {
 protected:
    int calcHeads() override;

 public:
    TeamLeader(int id, const std::string name,
               std::string position, int salary,
               int worktime, Project * project,
               float part)
            : Programmer(id, name, position, salary,
                         worktime, project, part) {}
};

#endif  //  INCLUDE_ENGINEER_H
