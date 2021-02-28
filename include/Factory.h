// Copyright 2020 GHA Test Team
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Employee.h"
#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"


class StaffFactory {
 private:
  std::string file_name;
  std::vector<std::string> data;
  void readData();
 public:
  StaffFactory();
  explicit StaffFactory(std::string file_name);
  static Project* createProject(std::vector<std::string> project_tokens);
  static Project* createProject(std::string name, int budget, int workers_num);
  std::vector<Employee*> makeStaff();
};
#endif  // INCLUDE_FACTORY_H_
