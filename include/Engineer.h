// Copyright 27.02.21 DenisKabanov

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"

struct Project {
  std::string id;
  int budget;
};

class Engineer : public ProjectBudget, public Personal {
 private:
  Project* projects;

 public:
  explicit Engineer(int id, std::string name, int salary, Project* projects)
      : Personal(id, name, salary) {
    this->projects = projects;
  }
  Project* getProject();
  virtual int calcProAdditions(int addCount, int addPrice);
  virtual int calcBudgetPart(float Part, int Budget);
  virtual void calc();
  virtual void printInfo();
};

class Programmer : public Engineer {
 public:
  explicit Programmer(int id, std::string name, int salary, Project* projects)
      : Engineer(id, name, salary, projects) {
    this->position = programmer;
  }
  virtual int calcProAdditions(int addCount, int addPrice);
  virtual void calc();
};

class Tester : public Engineer {
 private:
  int errorsCount = 0;

 public:
  explicit Tester(int id, std::string name, int salary, Project* projects)
      : Engineer(id, name, salary, projects) {
    this->position = tester;
  }
  void setErrors(int error);
  int getErrors();
  virtual int calcProAdditions(int addCount, int addPrice);
  virtual void calc();
  virtual void printInfo();
};

class TeamLeader : public Programmer, public Heading {
 private:
  int bossOf = 0;

 public:
  explicit TeamLeader(int id, std::string name, int salary, Project* projects)
      : Programmer(id, name, salary, projects) {
    this->position = teamLeader;
  }
  void addSub(int count);
  int getSub();
  virtual int calcHeads(int salaryForSub);
  virtual int calcProAdditions(int addCount, int addPrice);
  virtual void calc();
};

#endif  // INCLUDE_ENGINEER_H_