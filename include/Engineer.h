// Copyright 2021 Pavlova D.

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include "Manager.h"
#include "Personal.h"
#include <string>

class Engineer : public Personal, public IProjectBudget {
 public:
  Project *myProject;
  float part;

  Engineer(int id, std::string name, Position position, int salary,
           Project *myProject, float part)
      : Personal(id, name, position, salary), myProject(myProject), part(part) {
  }

  int calcBudgetPart(float _part, int budget) override;
  void calc() override;
};

class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, Position position, int salary,
             Project *myProject, float part)
      : Engineer(id, name, position, salary, myProject, part){}

  int calcProAdditions() override;
  int calcBonus() override;
};

class TeamLeader : public Programmer, public IHeading {
 public:
  TeamLeader(int id, std::string name, Position position, int salary,
             Project *myProject, float part)
      : Programmer(id, name, position, salary, myProject, part){}

  int calcHeads() override;
  int calcBonus() override;
};

class Tester : public Programmer {
 public:
  Tester(int id, std::string name, Position position, int salary,
         Project *myProject, float part)
      : Programmer(id, name, position, salary, myProject, part){}

  int calcProAdditions() override;
  int calcBonus() override;
  void calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
