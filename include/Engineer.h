// Copyright 2021 Ksuvot
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Personal.h"
#include "Interfaces.h"

struct Project {
  int id;
  int budget;
};

class Engineer : public ProjectBudget, public Personal {
 private:
  Project* project;
 public:
  Engineer(int id, std::string name, int salary, Project* project)
      : Personal(id, name, salary) {
    this->project = project;
  }
  virtual void calc();
  Project* getProject();
  virtual int calcBudgetPart(float part, int budget);
};

class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, int salary, Project* project)
    : Engineer(id, name, salary, project) {
    setPosition(programmer);
  }
  virtual int calcProAdditions();
};

class Tester : public Engineer {
 public:
  Tester(int id, std::string name, int salary, Project* project)
      : Engineer(id, name, salary, project) {
    setPosition(tester);
  }
  virtual int calcProAdditions();
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, std::string name, int salary,
             Project* project, int sub)
      : Programmer(id, name, salary, project) {
    setPosition(teamleader);
  }
  virtual int calcHeads();
  virtual void calc();
};

#endif  // INCLUDE_ENGINEER_H_
