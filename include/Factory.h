// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include "Employee.h"
#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"
#include <vector>
#include <set>

class Factory {
 public:
     std::vector<Employee*> makeStaff();
     std::vector<Project*> getProjects();
     void addProject(Project* project);
 private:
     std::vector<Project*> projects;
};

#endif  // INCLUDE_FACTORY_H_
