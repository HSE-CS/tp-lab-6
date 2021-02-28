// Copyright 2021 mkhorosh
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include "Interfaces.h"
#include "Personal.h"
#include "Factory.h"
#include <string>

class Engineer : public ProjectBudget, public Personal {
 protected:
  Project *current_project;
  float part;

 public:
  Engineer(std::string id, std::string name, Position position, int salary,
           Project *current_project, float part)
      : Personal(id, name, position, salary, payment),
      current_project(current_project), part(part) {
  }
  int calcBudgetPart(float current_part, int budget) override;
  void calc() override;
};

class Programmer : public Engineer {
 public:
  Programmer(std::string id, std::string name, Position position, int salary,
             Project *current_project, float part)
      : Engineer(id, name, position, salary, current_project, part) {}
  int calcProAdditions() override;
  int calcBonus() override;
};

class Tester : public Engineer {
 public:
  Tester(std::string id, std::string name, Position position, int salary,
         Project *current_project, float part)
      : Engineer(id, name, position, salary, current_project, part) {}
  int calcProAdditions() override;
  int calcBonus() override;
  void calc() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(std::string id, std::string name, Position position,
             int salary, Project *current_project, float part)
      : Programmer(id, name, position, salary, current_project, part) {}
  int calcHeads() override;
  int calcBonus() override;
};

#endif  // INCLUDE_ENGINEER_H_
