// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"
#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Factory {
 public:
  explicit Factory(std::string path2projects, std::string path2employees);
  std::vector<Project*> projects;
  std::vector<Emploeey*> employees;

  void makeStaff();
  void makeProjects();

 private:
  std::string path2projects;
  std::string path2employees;

  Project* getProject(int id_project);
};

#endif  // INCLUDE_FACTORY_H_
