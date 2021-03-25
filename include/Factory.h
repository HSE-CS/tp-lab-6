// Copyright 2021 dash
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <fstream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Manager.h"
#include "Engineer.h"
#include "Personal.h"
#include "Interfaces.h"

class Employee;
class Project;
class Programmer;
class Tester;
class Engineer;
class TeamLeader;
class Driver;
class Cleaner;
class ProjectManager;
class SeniorManager;

class Factory {
 private:
    std::vector<Employee*> employees;

 public:
    std::vector<Employee*> 
        createemployees(std::string prfile, 
            std::string employeesfile);
};

#endif  // INCLUDE_FACTORY_H_
