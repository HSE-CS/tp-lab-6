// Copyright 2021 asma
#pragma once
#ifndef ENGINEER_H_
#define ENGINEER_H_

#include "Interfaces.h"
#include "Personal.h"
#include "Project.h"
#include <string>


class Engineer : public ProjectBudjet, public Personal {
 protected:
    double part;
    Project* project;
 public:
    Engineer() {}
    Engineer(int, std::string, Position, int, Project*, double);
    int CalcBudgetPart() const;
    void Calc();
    int CalcProAdditions() const;
    std::string GetPosition() const;
};

class Programmer : public Engineer {
 public:
    Programmer() {}
    Programmer(int, std::string, Position, int, Project*, double);
    std::string GetPosition() const;
    void Calc();
};

class Tester : public Engineer {
 public:
    Tester(int, std::string, Position, int, Project*, double);
    std::string GetPosition() const;
    void Calc();
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(int, std::string, Position, int, Project*, double);
    std::string GetPosition() const;
    int CalcHeads() const;
    void Calc();
};


#endif  // ENGINEER_H_
