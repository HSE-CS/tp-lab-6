// Copyright 2021 me

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include<string>
#include "Personal.h"
#include "Interfaces.h"
#include "Factory.h"

class Project;

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project *project;


 public:
  Engineer(unsigned _id, std::string _name, Position _position, int _salary,
           Project* _project):
    Personal(_id, _name, _position, _salary), project(_project) {}
  int calcBudgetPart(float part, int budget) override;
  int getProgectBudget();
  int getProjectState();
  int getProjectTesters();
  int calcProAdditions() override;
  void calc() override;
  void printInfo() override;
};

class Tester : public Engineer {
 public:
  Tester(unsigned _id, std::string _name, Position _position, int _salary,
         Project* _project)
      : Engineer(_id, _name, _position, _salary, _project) {}
  void calc() override;
  void printInfo() override;
};

class Programmer : public Engineer {
 public:
  Programmer(unsigned _id, std::string _name, Position _position, int _salary,
             Project* _project)
      : Engineer(_id, _name, _position, _salary, _project) {}
  void calc() override;
  void printInfo() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(unsigned _id, std::string _name, Position _position, int _salary,
         Project* _project)
      : Programmer(_id, _name, _position, _salary, _project) {}
  int calcHeads() override;
  void calc() override;
  void printInfo() override;
};

#endif  // INCLUDE_ENGINEER_H_
