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
      for (auto emp : Company) {
        emp->setWorkTime(std::rand() % 100 + 100);
      }
      for (auto emp : Company) {
       emp->calc();
      }
      for (auto emp : Company) {
        emp->printInfo();
      }
    return 0;
}
