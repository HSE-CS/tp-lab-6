// Copyright DB 2021
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include <vector>
#include "Interfaces.h"
#include "Personal.h"

class Project;

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project *project;
  float part;

 public:
  Engineer(int id, const std::string &name, Position position, int salary,
           Project *project, float part);
  void printInfo() override;
  int calcBudgetPart(float part, int budget) override;
};

class Tester : public Engineer {
 public:
  Tester(int id, const std::string &name, Position position, int salary,
         Project *project, float part);

 protected:
  int calcProAdditions() override;
  void calc() override;
};

class Programmer : public Engineer {
 public:
  Programmer(int id, const std::string &name, Position position, int salary,
             Project *project, float part);

 protected:
  int calcProAdditions() override;
  void calc() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, const std::string &name, Position position, int salary,
             Project *project, float part);

 protected:
  int calcHeads() override;
  void calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
