// Copyright 2021 LongaBonga

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Interfaces.h"
#include "Personal.h"
#include "Project.h"
#include "headers.h"

class Project;

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project *project;
  float part;

 public:
  Engineer(int id, const std::string name, std::string position, int salary,
           int worktime, Project *_project, float part)
      : Personal(id, name, position, salary, worktime),
        project(_project),
        part(part) {}

  void printInfo() override;
  int calcBudgetPart(float part, int budget) override;
};

class Tester : public Engineer {
 public:
  Tester(int id, const std::string name, std::string position, int salary,
         int worktime, Project *project, float part)
      : Engineer(id, name, position, salary, worktime, project, part) {}

 protected:
  int calcProAdditions() override;
  int calc() override;
};

class Programmer : public Engineer {
 public:
  Programmer(int id, const std::string name, std::string position, int salary,
             int worktime, Project *project, float part)
      : Engineer(id, name, position, salary, worktime, project, part) {}

 protected:
  int calcProAdditions() override;
  int calc() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, const std::string name, std::string position, int salary,
             int worktime, Project *project, float part)
      : Programmer(id, name, position, salary, worktime, project, part) {}

 protected:
  int calcHeads() override;
  int calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
