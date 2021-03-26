// Copyright 2020 Uskova
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>

#include "Interfaces.h"
#include "Personal.h"
#include "Project.h"

class Project;  // ????

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project* project;

 public:
  Engineer(int, std::string, Position, int, int, Project*);
  int calcBudgetPart(float, int) override;
  void calc() override;
  void setProject(Project* pr);
  Project* getProject();
  std::string getProjectName();
  int calcBonus() override;
  virtual void printinfo() = 0;
  int getSalary();
};

class Programmer : public Engineer {
 private:
  int coef;

 public:
  Programmer(int, std::string, Position, int, int, int, Project*);
  void printinfo() override;
  int calcProAdditions() override;
  int getCoef();
};

class Tester : public Engineer {
 private:
  int numFoundMistakes;

 public:
  Tester(int, std::string, Position, int, int, int, Project*);
  void printinfo() override;
  int calcProAdditions() override;
  int getCoef();
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int, std::string, Position, int, int, Project*);
  int calcHeads() override;
  void calc() override;
  void printinfo() override;
  void addProject(Project*);
};

#endif  // INCLUDE_ENGINEER_H_
