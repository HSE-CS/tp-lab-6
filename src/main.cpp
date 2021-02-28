// Copyright 2021 me

#include "../include/Employee.h"
#include "../include/Engineer.h"
#include "../include/Factory.h"
#include "../include/Manager.h"
#include "../include/Personal.h"


int main() {
      std::string pathToProjects = "../tp-lab-6/src/Projects.json";
      std::vector<Project*> Projects(makeProjects(pathToProjects));
      std::string pathToEmployees = "../tp-lab-6/src/Employees.json";
      std::vector<Employee*> Company(makeStaff(pathToEmployees, Projects));
      for (auto a : Company) {
        a->printInfo();
      }
    return 0;
}
