// Copyright 2021 me

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_


#include<vector>
#include<string>
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"

class Project;

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 private:
  Project* proj;
 public:
  ProjectManager(unsigned _id, std::string _name, Position _position,
                 Project* _proj)
      : Employee(_id, _name, _position), proj(_proj){}
  int calcHeads() override;
  int calcProAdditions() override;
  int calcBudgetPart(float part, int budget) override;
  void calc() override;
  void printInfo() override;
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> progectList;

 public:
  SeniorManager(unsigned _id, std::string _name, Position _position)
      : ProjectManager(_id, _name, _position, nullptr){}
  ~SeniorManager() { progectList.clear(); }
  void addProject(Project* _proj);
  void calc();
  void printInfo() override;
};

#endif  // INCLUDE_MANAGER_H_
