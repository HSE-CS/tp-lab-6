// Copyright 2020 Konina Tatiana

#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iostream>
#include "Factory.h"
#include "Manager.h"
#include "Employee.h"
#include "Engineer.h"
#include "Project.h"

std::vector<Employee*> read_data(std::string input) {
  std::ifstream file(input);
  if (file.is_open()) {
    std::vector<Employee*> employee;
    std::string buf = "";
    if (file.good()) {
      getline(file, buf, '\n');
    }
    while (file.good()) {
      buf.clear();
      std::string id, fio, worktime, position, salary;
      getline(file, id, ';');
      getline(file, fio, ';'); 
      getline(file, worktime, ';');
      getline(file, position, ';');
      getline(file, salary, '\n');

      if (position == "tester") {
        employee.push_back(new Tester(stoi(id), fio,
          stoi(worktime), stoi(salary), TESTER, nullptr));
      } else if (position == "programmer") {
        employee.push_back(new Programmer(stoi(id), fio,
          stoi(worktime), stoi(salary), PROGRAMMER, nullptr));
      } else if (position == "teamleader") {
        employee.push_back(new TeamLeader(stoi(id), fio,
          stoi(worktime), stoi(salary), TEAMLEADER, nullptr));
      } else if (position == "cleaner") {
        employee.push_back(new Cleaner(stoi(id), fio,
          stoi(worktime), stoi(salary), CLEANER));
      } else if (position == "driver") {
        employee.push_back(new Driver(stoi(id), fio,
          stoi(worktime), stoi(salary), DRIVER));
      } else if (position == "project manager") {
        std::vector <Project*> projects;
        employee.push_back(new ProjectManager(stoi(id), fio,
          stoi(worktime), stoi(salary), PROJECTMANAGER, projects));
      } else if (position == "senior manager") {
        std::vector <Project*> projects;
        employee.push_back(new SeniorManager(stoi(id), fio,
          stoi(worktime), stoi(salary), SENIORMANAGER,projects));
      }
    }
    return employee;
  } else {
    throw "file error";
  }
}


