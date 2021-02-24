//// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

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
    Engineer(int id, int worktime, int payment, int salary,
             const std::string name, std::string position,
             Project *project, float part) : Personal(
                     id, worktime, payment, salary, name,
                     position),
                     project(project),
                     part(part) {};
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
    Tester(int id, int worktime, int payment, int salary,
           const std::string name, std::string position,
           Project *project, float part)

           : Engineer(id, worktime, payment,salary, name,
                      position, project, part) {};
};

class Programmer : public Engineer {
 protected:
    int calcProAdditions() override;

 public:
    Programmer(int id, int worktime, int payment, int salary,
               const std::string name, std::string position,
               Project *project, float part)

            : Engineer(id, worktime, payment, salary, name,
                       position, project, part) {};
};

class TeamLeader : public Programmer, public Heading {
 protected:
    int calcHeads() override;

 public:
    TeamLeader(int id, int worktime, int payment, int salary,
               const std::string name, std::string position,
               Project *project, float part)
            : Programmer(id, worktime, payment, salary,
                         name, position, project, part) {};
};

#endif  // INCLUDE_ENGINEER_H_
