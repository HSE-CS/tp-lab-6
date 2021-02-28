// Copyright 2020 GHA Test Team
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <string>
#include "Employee.h"
#include "Personal.h"
#include "Interfaces.h"


class Engineer : public ProjectBudget, public Personal {
 protected:
  Project* project = nullptr;
  void InitializeByFourParams(int id, std::string name,
    int salary, Project* project);

 public:
  int calcBonus() const;
  int calcBudgetPart(float part, int budget) const;
  void calc();
  void printInfo() const override;
};


class Programmer : public Engineer {
 public:
  Programmer();
  Programmer(int id, std::string name, int salary, Project* project);
  int calcProAdditions() const;
};


class Tester : public Engineer {
 public:
  Tester();
  Tester(int id, std::string name, int salary, Project* project);
  int calcProAdditions() const;
};


class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader();
  TeamLeader(int id, std::string name, int salary, Project* project);
  int calcHeads() const;
  void calc();
};
#endif  // INCLUDE_ENGINEER_H_
