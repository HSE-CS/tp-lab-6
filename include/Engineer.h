// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_ENGINEER_H
#define INCLUDE_ENGINEER_H
#include <string>
#include "Personal.h"

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
  Project* getProject();
  virtual int calcBudgetPart(float part, int budget);
  virtual void calc();
  virtual void printInfo();
};

class Programmer : public Engineer {
public:
  Programmer(int id, std::string name, int salary, Project* project)
    : Engineer(id, name, salary, project) {
    pos = PROGRAMMER;
  }
  virtual int calcProAdditions();
};

class Tester : public Engineer {
 private:
  int errorsFound = 0;
 public:
  Tester(int id, std::string name, int salary, Project* project)
    : Engineer(id, name, salary, project) {
    pos = TESTER;
  }
  void incErrorsFound();
  int getErrorsFound();
  virtual int calcProAdditions();
};

class TeamLeader : public Programmer, public Heading {
 private:
  int subordinates = 0;
 public:
  TeamLeader(int id, std::string name, int salary, Project* project, int sub)
    : Programmer(id, name, salary, project) {
    pos = TEAMLEADER;
    this->subordinates = sub;
  }
  int getSubbordinates();
  virtual int calcHeads();
  virtual void calc();
};

#endif  // INCLUDE_ENGINEER_H_
