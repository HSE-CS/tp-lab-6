// Copyright 2021 Galex

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "../include/Personal.h"
#include "../include/Interfaces.h"
#include "../include/Project.h"

class Engineer : public Personal, public ProjectBudget {
 private:
  Project* project;

 public:
  double calcBudgetPart(double part, int budget) override;
  void calc() override;
  void setProject(Project* project);
  Project* getProject();
  double calcBonus() override;
  void printInfo() override;
};

class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, double salary, Project* project);
  void calcProAdditions() override;
};

class Tester : public Engineer {
 public:
  int errorsFound;
  Tester(int id, std::string name, double salary, Project* project);
  void calcProAdditions() override;
};

class TeamLeader : public Engineer, public Heading {
 public:
  double calcHeads() override;
  TeamLeader(int id, std::string name, double salary, Project* project);
  void calcProAdditions() override;
};
#endif  // INCLUDE_ENGINEER_H_
