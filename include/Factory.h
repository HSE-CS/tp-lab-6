//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"
#include "Project.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Engineer.h"
#include "Programmer.h"
#include "Tester.h"
#include "TeamLeader.h"
#include "Manager.h"
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "json.hpp"

class StaffFactory {
 private:
  Project* temp_proj;
  Employee* temp_employee;
  std::vector<Project*> MakeProjects;
  std::map<std::string, int> project_json;
  std::vector<Employee*> MakeStaff;
  std::map<std::string, std::string> staff;

 public:
  void readProjectFile();
  void readStaffFile();
  Project* parseProjects(std::map<std::string, int> inf_project);
  Employee* parseStaff(std::map<std::string, std::string> inf_staff);
  std::vector<Employee*> getStaff();
};

#endif  // INCLUDE_FACTORY_H_

