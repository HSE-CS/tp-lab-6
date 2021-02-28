// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Personal.h"
#include "Project.h"
#include "Interfaces.h"

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project* project;
  float part;
 public:
  Engineer(unsigned int id, std::string name,
           int worktime, double salary, int position, Project* pr);
  void calc();
  int calcBudgetPart();
  int calcProAdditions(int bonus = 0);
  void setProject(Project * project);
  void printInfo();
};

class Programmer : public Engineer {
 protected:
  int bonus;
 public:
  Programmer(unsigned int id, std::string name,
    int worktime, double salary, int position, Project* pr);
  void calc();
};

class Tester : public Engineer {
 protected:
  int bonus;
 public:
  Tester(unsigned int id, std::string name,
    int worktime, double salary, int position, Project* pr);
  void calc();
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(unsigned int id, std::string name,
    int worktime, double salary, int position, Project* pr);
  int calcHeads();
  void calc();
};

#endif  // INCLUDE_ENGINEER_H_



