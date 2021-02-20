// Copyright 2021 Arina Simonova

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#pragma once

#include "Employee.h"
#include "Interfaces.h"
#include <vector>
#include <string>

class Project {
 private:
  int id;
  int budget;
 public:
  Project();
  Project(int _id, int _budget);
  int GetId();
  int GetBudget();
  void setID(int _id);
  void setBudget(int _budget);
};

class ProjectManager : public Employee, IProjectBudget, IHeading {
 private:
  Project myProject;
 public:
  ProjectManager(int _id, string _name, string _pos, int _workTime,
    int _payment, int _salary, Project _myProject);
  ProjectManager(int _id, string _name, string _pos, int _workTime,
    int _payment, int _salary);
  int CalcBidgetPart(float part, int budget);
  int calcProAdditions();
  int calcHeads();
  int GetSalary();
  int Calc();
  void PrintInfo();
};

class SeniorManager : public ProjectManager {
 private:
  vector<Project> Projects;
 public:
  SeniorManager(int _id, string _name, string _pos, int _workTime,
    int _payment, int _salary, vector<Project> _Projects);
  int calcHeads();
  int calcProAdditions();
  void PrintInfo();
};

#endif  // INCLUDE_MANAGER_H_
