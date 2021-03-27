// Copyright 2021 by Liza
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Personal.h"
#include "Interfaces.h"
#include <string>
#include <vector>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 private:
Project hisProject;
int salary;
 public:
ProjectManager(int _id, std::string _name, std::string _position, int _payment, Project currentProject);
ProjectManager(int _id, std::string _name, std::string _position, int _payment);
int calcBudgetPart(float part, int budget);
int calcProAdditions();
void setProgect(int _id, int _budget);
int calc();
int calcHeads();
void setsalary(int a);
int getsalary();
void printInfo();};

class SeniorManager : public ProjectManager {
 private:
std::vector<Project> Projects;
 public:
SeniorManager(int _id, std::string _name, std::string _position,
int payment, std::vector<Project> Projects);
void addProject(Project projject);
int calcBudgetPart(float part, int budget);
int calcProAdditions();
int calcHeads();
int calc();
void printInfo();};

#endif  // INCLUDE_MANAGER_H_
