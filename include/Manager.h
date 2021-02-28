// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class Project {
 private:
  int id;
  double budget;
  int numOfStaff;

 public:
  Project(int id, double budget);
  int getId();
  double getBudget();
  int getStaffNum();
  void updateStaffNum();
};

class ProjectManager : public Employee, public Heading {
 private:
  std::vector <Project*> projects;

 public:
  ProjectManager(int id, std::string name, std::string position, 
   double payment, std::vector <Project*> newProjects);
  double getCurrentBudget();  // instead of getSalary() 
  virtual double calcHeads();
  virtual double calc();
  virtual void printInfo();

 protected:
  std::vector <Project*> getProjects();
};

class SeniorManager : public ProjectManager {
 private:
  int numOfProjects;

 public:
  SeniorManager(int id, std::string name, std::string position, 
   double payment, std::vector <Project*> newProjects);
  int getNumOfProjects();
  void addNewProject(Project* newProject);
  virtual double calcHeads();
  virtual double calc();
  virtual void printInfo();
};

#endif  // INCLUDE_MANAGER_H_
