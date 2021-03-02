// Copyright 2020 Polina Lukicheva
#include "Factory.h"

#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iostream>
#include "Manager.h"
#include "Employee.h"
#include "Engineer.h"

std::vector<Employee*> readData(std::string fileName) {
  std::ifstream file(fileName);
  if (file.is_open()) {
    std::vector<Employee*> employee;
    std::string b = "";
    if (file.good()) {
      getline(file, b, '\n');
    }
    while (file.good()) {
      b = "";
      std::string id, name, worktime, position, salary;
      getline(file, id, ';');
      getline(file, name, ';');
      getline(file, position, ';');
      getline(file, worktime, ';');
      getline(file, salary, '\n');

      if (position == "cleaner") {
        employee.push_back(new Cleaner(stoi(id), name, position,
          stoi(worktime), stoi(salary)));
      } else if (position == "driver") {
        employee.push_back(new Driver(stoi(id), name, position,
          stoi(worktime), stoi(salary)));
      } else if (position == "tester") {
        employee.push_back(new Tester(stoi(id), name, position,
          stoi(worktime), stoi(salary), nullptr));
      } else if (position == "programmer") {
        employee.push_back(new Programmer(stoi(id), name, position,
          stoi(worktime), stoi(salary), nullptr));
      } else if (position == "teamleader") {
        employee.push_back(new TeamLeader(stoi(id), name, position,
          stoi(worktime), stoi(salary), nullptr));
      } else if (position == "project manager") {
        std::vector <Project*> pr;
        employee.push_back(new ProjectManager(stoi(id), name, position,
          stoi(worktime), stoi(salary), pr));
      } else if (position == "senior manager") {
        std::vector <Project*> pr;
        employee.push_back(new SeniorManager(stoi(id), name, position,
          stoi(worktime), stoi(salary), pr));
      }
    }
    return employee;
  }
}
