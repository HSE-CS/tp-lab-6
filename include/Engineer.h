// Copyright 2021 Lab_6 TiNa
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include "Interfaces.h"
#include "Personal.h"
#include "Factory.h"
#include <iostream>
#include <string>

//class Project;

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project* project;
  float contrib;

 public:
  Engineer(int id, std::string name, std::string position, int worktime,
           int payment, Project* projectIn, float contribIn)
      : Personal(id, name, position, salary, worktime, payment),
        project(projectIn),
        contrib(contribIn) {}

  float calcBudgetPart(float contrib, int budget) override;
  void printInfo();
};

class Programmer : public Engineer {
 protected:
  int calcProAdditions() override;
  int calc() override;

 public:
  Programmer(int id, std::string name, std::string position, int worktime,
             int payment, Project* project, float contrib)
      : Engineer(id, name, position, worktime, payment, project, contrib) {}
  void printInfo() override;
};

class Tester : public Engineer {
 protected:
  int calcProAdditions() override;
  int calc() override;

 public:
     Tester(int id, std::string name, std::string position, int worktime,
         int payment, Project* project, float contrib)
      : Engineer(id, name, position, worktime, payment, project, contrib) {}
};

class TeamLeader : public Programmer, public Heading {
  int calcHeads() override;
  int calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
