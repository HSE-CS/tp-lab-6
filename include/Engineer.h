// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

class Engineer : public Personal, public ProjectBudget {
 private:
  Project *project;
  virtual double calcBonus();

 public:
  Engineer(int id, std::string name, std::string position, 
   double payment, Project* newProject);
  Project* getProject();
  virtual double calcBudgetPart(double part);

};

class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, std::string position, 
   double payment, Project* newProject);
  virtual double calcProAdditions();
  virtual double calc();
  virtual void printInfo();
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, std::string name, std::string position, 
   double payment, Project* newProject);
  virtual double calcHeads();
  virtual double calc();
  virtual void printInfo();
};

class Tester : public Engineer {
 public:
  Tester(int id, std::string name, std::string position, 
   double payment, Project* newProject);
  virtual double calcProAdditions();
  virtual double calc();
  virtual void printInfo();
};

#endif  // INCLUDE_ENGINEER_H_
