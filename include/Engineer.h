// Copyright DB 2021
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <string>
#include <vector>
#include "Personal.h"
#include "Interfaces.h"

class Project;

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project* project;
  double part;

 public:
  Engineer(int id, const std::string &name, const Position position,
           int salary, float part, Project *project)
      : Personal(id, name, position, salary), part(part), project(project) {}
  int calcBudgetPart(float part,
                              int budget) override;
  void printInfo() override;
};

class Programmer : public Engineer {
 protected:
  int calcProAdditions() override;
  void calc() override;

 public:
  Programmer(int id, const std::string &name, Position position,
             int salary, float part, Project *project)
      : Engineer(id, name, position, salary, part, project) {}
};

class TeamLeader : public Programmer, public Heading {
 private:
  void calc() override;
  int calcHeads() override;

 public:
  TeamLeader(int id, const std::string &name, Position position,
             int salary, float part, Project *project)
      : Programmer(id, name, position, salary, part, project) {}
};

class Tester : public Engineer {
 private:
  int calcProAdditions() override;
  void calc() override;

 public:
  Tester(int id, const std::string &name, Position position,
         int salary, float part, Project *project)
      : 
      Engineer(id, name, position, salary, part, project) {}
};

#endif  // INCLUDE_ENGINEER_H_