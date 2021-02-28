// Copyright 27.02.21 DenisKabanov

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include <string>
#include "Engineer.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 private:
  Project* projects;
  int bossOf = 0;
  int passivesalary = 75000;

 public:
  ProjectManager(int id, std::string name, Project* project)
      : Employee(id, name) {
    this->projects = project;
    this->position = projectManager;
  }
  int getSub();
  Project* getProject();
  void addSub(int count);
  virtual int calcHeads(int salaryForSub);
  virtual int calcProAdditions(int addCount, int addPrice);
  virtual int calcBudgetPart(float part, int budget);
  virtual void calc();
  virtual void printInfo();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;
  int bossOf = 0;
  int passivesalary = 100000;

 public:
  explicit SeniorManager(int id, std::string name, Project* project)
      : ProjectManager(id, name, project) {
    this->position = seniorManager;
  }
  int getSub();
  void addSub(int count);
  virtual int calcHeads(int salaryForSub);
  virtual int calcProAdditions(int addCount, int addPrice);
  virtual void calc();
  virtual void printInfo();
};

#endif  // INCLUDE_MANAGER_H_
