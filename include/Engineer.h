// Copyright 2021 by Bodrov Egor
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <utility>
#include <string>

#include "Employee.h"
#include "Interfaces.h"
#include "Personal.h"

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project* project;
  float partition;

 public:
  Engineer(int id, int salaryPerHour, std::string name, std::string pos,
           Project* project, float part);

  int calcBudgetPart(float part, int budget) override;
  void calc() override;
};

class Programmer : public Engineer {
 public:
  Programmer(int id, int salaryPerHour, std::string name, std::string pos,
             Project* project, float part);

  int calcProAdditions() override;
  void calc() override;
};

class Tester : public Engineer {
 public:
  Tester(int id, int salaryPerHour, std::string name, Project* project,
         float part);

  int calcProAdditions() override;
  void calc() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, int salaryPerHour, std::string name, Project* project,
             float part);

  int calcHeads() override;
  void calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
