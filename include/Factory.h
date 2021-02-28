// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <fstream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Engineer.h"
#include "Interfaces.h"
#include "Manager.h"

class Employee;
class Project;

class Factory {
 private:
  std::vector<Employee *> staff;

 public:
  std::vector<Employee *> makeStaff(std::string _project_filename,
                                    std::string _staff_filename);
};

#endif  // INCLUDE_FACTORY_H_
