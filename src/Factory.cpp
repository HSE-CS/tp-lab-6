// Copyright 2021 Dumarevskaya
#include "Factory.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Manager.h"
#include "Engineer.h"
#include "Interfaces.h"
#include <cstring>

std::vector<Employee*> StaffFactory::makeStaff(std::string file_name) {
  std::ifstream file(file_name);
  if (file.is_open()) {
    std::string temp;
    std::vector<Employee*> staff;
    while (file) {
      std::string id, name, salary, position, pro, budget;
      getline(file, id, ';');
      getline(file, name, ';');
      getline(file, salary, ';');
      getline(file, position, ';');
      getline(file, pro, ';');
      getline(file, budget, '\n');

      if (position == "Cleaner") {
        staff.push_back(new Cleaner(id, name, stof(salary),
          Position(CLEANER)));
      } else if (position == "Driver") {
        staff.push_back(new Driver(id, name, stof(salary),
          Position(DRIVER)));
      } else if (position == "Tester") {
        staff.push_back(new Tester(id, name, stof(salary),
          Position(TESTER), new Project(pro, stof(budget))));
      } else if (position == "Programmer") {
        staff.push_back(new Programmer(id, name, stof(salary),
          Position(PROGRAMMER), new Project(pro, stof(budget))));
      } else if (position == "Teamleader") {
        staff.push_back(new TeamLeader(id, name, stof(salary),
          Position(TEAMLEADER), new Project(pro, stof(budget))));
      } else if (position == "Project Manager") {
        std::vector <Project*> pr;
        pr.push_back(new Project(pro, stof(budget)));
        staff.push_back(new ProjectManager(id, name, stof(salary),
          Position(PROJECTMANAGER), pr));
      } else if (position == "Senior Manager") {
        std::vector <Project*> pr;
        pr.push_back(new Project(pro, stof(budget)));
        staff.push_back(new SeniorManager(id, name, stof(salary),
          Position(SENIORMANAGER), pr));
      }
    }
    return staff;
  }
}
