// Copyright 2021 Dev-will-work
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <iostream>
#include <string>
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

class Engineer : public ProjectBudget, public Personal {
 public:
  Engineer();
  virtual ~Engineer();
  virtual int calcBudgetPart(float part, int budget);
  virtual void calc();

 protected:
  Project project;

 private:
};

class Programmer : public Engineer {
 public:
  Programmer(Project, int, std::string, Position);
  virtual ~Programmer();
  virtual int calcProAdditions();
  virtual void printInfo();
  // virtual int calcBudgetPart(float part, int budget);
  // virtual int calcBonus();
  // virtual int calcBase(int salary, int wtime);


 private:
};

class Tester : public Engineer {
 public:
  Tester(Project, int, std::string, Position);
  virtual ~Tester();
  virtual int calcProAdditions();
  virtual void printInfo();
  // virtual int calcBudgetPart(float part, int budget);
  // virtual int calcBonus();
  // virtual int calcBase(int salary, int wtime);

 private:
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(Project, int, std::string, Position);
  virtual ~TeamLeader();
  virtual Project getProject();
  virtual int calcHeads();
  virtual void calc();
  void printInfo();
};

#endif  // INCLUDE_ENGINEER_H_
