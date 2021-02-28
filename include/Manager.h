// Copyright 2020 GHA Test Team
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <string>
#include "Employee.h"
#include "Interfaces.h"


class ProjectManager :
  public Employee, public ProjectBudget, public Heading {
protected:
  int projects_num = 0;
  Project** projects = nullptr;
  void initializeParamsByZero();
  void deleteParams();

public:
  ProjectManager();
  ProjectManager(int id, std::string name, Project* project);
  ~ProjectManager();
  void printInfo() const;
  int calcHeads() const;
  int calcBudgetPart(float part, int budget) const;
  int calcProAdditions() const;
  void calc();
};


class SeniorManager : public ProjectManager {
public:
  SeniorManager();
  SeniorManager(int id, std::string name, Project** projects,
    int projects_num);
  ~SeniorManager();
  int calcProAdditions() const override;
  int calcBudgetPart(float part) const;
  void printInfo() const override;
  void calc();
};
#endif  // INCLUDE_MANAGER_H_
