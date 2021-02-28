// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"
class ProjectManager : public Employee, public Heading, public ProjectBudget {
 protected:
  Project *project = nullptr;
 public:
  ProjectManager(int id, std::string name,
                 int workTime, Positions position, Project *project);
  void printInfo() override;
  int calcBudgetPart() override;
  int calcProAdditions(int bonus = 100) override;
  int calcHeads() override;
  int calc() override;
};
class SeniorManager : public ProjectManager {
 private:
  std::vector<Project *> projects;
 public:
  SeniorManager(int id, const std::string &name,
                int workTime, Positions position, std::vector<Project *> pr);
  int calc() override;
};

#endif  // INCLUDE_MANAGER_H_



