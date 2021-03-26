// Copyright 2021 Arina Simonova

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#pragma once

#include "Personal.h"
#include "Manager.h"
#include "Interfaces.h"
#include <string>

class Engineer : public Personal, IProjectBudget {
 private:
  Project myProject;
 public:
  Engineer(int _id, std::string _name, std::string _pos, int _workTime,
    int _payment, int _salary, Project _myProject);
  Project GetProject();
  friend void Project::setID(int _id);
  int CalcBidgetPart(float part, int budget);
  int calcProAdditions();
  int Calc();
  void PrintInfo();
};

class Programmer : public Engineer {
 public:
  Programmer(int _id, std::string _name, std::string _pos, int _workTime,
    int _payment, int _salary, Project _myProject);
  int calcProAdditions();
  int Calc();
};

class Tester : public Engineer {
 public:
  Tester(int _id, std::string _name, std::string _pos, int _workTime,
    int _payment, int _salary, Project _myProject);
  int calcProAdditions();
  int Calc();
};

class TeamLead : public Programmer, IHeading {
 public:
  TeamLead(int _id, std::string _name, std::string _pos, int _workTime,
    int _payment, int _salary, Project _myProject);
  int calcHeads();
  int Calc();
};

#endif  // INCLUDE_ENGINEER_H_
