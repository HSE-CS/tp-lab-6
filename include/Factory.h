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

      if (position == "Pesonal")
        employee = new Personal(id, name, position, worktime, payment);
      else if (position == "Engineer")
        employee = new Engineer(payment, project);
      else if (position == "Cleaner")
        employee = new Cleaner(payment);
      else if (position == "Driver")
        employee = new Driver(payment);
      else if (position == "Programmer")
        employee = new Programmer(payment, project);
      else if (position == "Tester")
        employee = new Tester(payment, project);
      else if (position == "Team Lead")
        employee = new TeamLeader(payment, project);
      else if (position == "Project Manager")
        employee = new ProjectManager(project);
      else if (position == "Senior Manager")
        employee = new SeniorManager(project, projects);
      else
        employee = new Employee();

      employees.push_back(employee);
    }
    file.close();
    return std::vector<Employee *>();
  }
};

#endif  // INCLUDE_FACTORY_H_
