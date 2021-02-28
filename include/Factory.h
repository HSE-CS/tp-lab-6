//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Engineer.h"
#include "Manager.h"

class Factory {
 private:
  std::string employeesFileName;
  std::string projectsFileName;
  std::vector<Employee*> employees;
  std::vector<Project*> projects;

 public:
  Factory(std::string employeesFileName,
         std::string projectsFileName);
  Employee* getEmployee(unsigned index);
  Project* getProject(unsigned index);
  unsigned getProjectsSize() const;
  unsigned getEmployeesSize() const;
  void readStaff();
  void calcAll();
  void printStaffInfo();
};

#endif  // INCLUDE_FACTORY_H_
