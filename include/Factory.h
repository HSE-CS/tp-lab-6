// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <vector>

#include "Engineer.h"
#include "Manager.h"

class Factory {
 private:
  std::vector<project_t*> projects;
  std::vector<Employee*> staff;

  void createProjects(const std::vector<std::string>&);
  void createStaff(const std::vector<std::string>&);

 public:
  Factory(const char* filename_staff, const char* filename_projects);
  std::vector<Employee*>& getStaff();
};

#endif  // INCLUDE_FACTORY_H_
