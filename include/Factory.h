// Copyright 2021 me

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include<string>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"
#include "Engineer.h"
#include "Manager.h"

std::vector<Project*> makeProjects(std::string path = "");
std::vector<Employee*> makeStaff(std::string path,
                                 std::vector<Project*> projectsList);

class ProjectManager;
class Engineer;

class Project {
  friend ProjectManager;
  friend Engineer;
 private:
  unsigned id;
  int budget;
  std::vector<Engineer*> workers;
  std::vector<Engineer*> testers;

 public:
  Project(unsigned _id, int _budget) : id(_id), budget(_budget) {}
  unsigned getProjectID();
  int getTesters();
  int getWorkers();
  int getBudget();
  void addTester(Engineer* tester);
  void addWorker(Engineer* worker);
};

#endif  // INCLUDE_FACTORY_H_
