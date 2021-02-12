// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "Manager.h"

class Factory {
 public:
  static std::vector<Employee *> makeStaff(char *filepath) {
    setlocale(LC_ALL, "rus");
    std::ifstream file(filepath);
    std::string string;
    getline(file, string);
    std::vector<Employee *> employees;
    while (getline(file, string)) {
      printf("%s\n", string.c_str());
      int id;
      std::string name;
      std::string position;
      int payment;
      auto *project = new Project(12, 12);
      std::vector<Project *> projects;
      projects.push_back(project);

      Employee *employee;

//      if (position == "Personal")
//        employee = new Personal(id, name, position, payment);
//      else if (position == "Engineer")
//        employee = new Engineer(id, name, position, payment);
//      else if (position == "Cleaner")
//        employee = new Cleaner(id, name, position, payment);
//      else if (position == "Driver")
//        employee = new Driver(id, name, position, payment);
//      else if (position == "Programmer")
//        employee = new Programmer(id, name, position, payment);
//      else if (position == "Tester")
//        employee = new Tester(id, name, position, payment);
//      else if (position == "Team Lead")
//        employee = new TeamLeader(id, name, position, payment);
//      else if (position == "Project Manager")
//        employee = new ProjectManager(id, name, position, payment);
//      else if (position == "Senior Manager")
//        employee = new SeniorManager(id, name, position, payment);

      employees.push_back(employee);
    }
    file.close();
    return std::vector<Employee *>();
  }
};

#endif  // INCLUDE_FACTORY_H_
