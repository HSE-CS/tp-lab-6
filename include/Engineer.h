// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Interfaces.h"
#include "Personal.h"
#include "Manager.h"
#include <string>

class Engineer : public Personal, public IProjectBudget {
 private:
  Project* project;
 public:
  Engineer(std::string id,
    std::string name,
    double salary,
    Position position,
    Project* project)
    : Personal(id, name, salary, position), project(project) {}
  int calcBudgetPart(float part, int budget) override;
  void calc() override;
  int calcBonus() override;
  void printInfo() override;
};

class Tester : public Engineer {
 public:
  Tester(std::string id,
    std::string name,
    double salary,
    Position position,
    Project* project)
    : Engineer(id, name, salary, position, project) {}
  int calcProAdditions() override;
};

class Programmer : public Engineer {
 public:
  Programmer(std::string id,
    std::string name,
    double salary,
    Position position,
    Project* project)
    : Engineer(id, name, salary, position, project) {}
  int calcProAdditions() override;
};

class TeamLeader : public Programmer, public IHeading {
 public:
  TeamLeader(std::string id,
    std::string name,
    double salary,
    Position position,
    Project* project)
    : Programmer(id, name, salary, position, project) {}
  int calcHeads() override;
  void calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
