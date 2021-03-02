// Copyright 2021 Shirokov Alexander
#include <iostream>
#include <sstream>
#include "Factory.h"

std::vector<Employee*> FactoryWork::makeStaff() {
  std::vector<Employee*> staff;
  std::ifstream input("workers.txt");
  std::ifstream pr("projects.txt");

  if (input.is_open() == false || pr.is_open() == false) {
    std::cout << "File does not exist\n";
    return staff;
  }

  std::vector<Project*> projects;
  std::string budget, title;
  while (pr >> budget >> title) {
    Project* tmp = new Project(std::stoi(budget), title);
    projects.push_back(tmp);
  }

  std::string row;
  while (std::getline(input, row)) {
    std::string id, name, p;
    std::istringstream f(row);

    std::getline(f, id, ';');
    std::getline(f, name, ';');
    std::getline(f, p, ';');

    std::istringstream is(p);
    int e;
    is >> e;
    Position pos = static_cast<Position>(e);

    if (pos == PROGRAMMER) {
      int project_num = std::rand() % projects.size();
      Programmer* tmp = new Programmer(std::stoi(id), 200, name, pos,
      projects[project_num], 0.3);
      staff.push_back(tmp);
    }

    if (pos == TESTER) {
      int project_num = std::rand() % projects.size();
      Tester* tmp =
      new Tester(std::stoi(id), 150, name, pos, projects[project_num], 0.3);
      staff.push_back(tmp);
    }

    if (pos == TEAM_LEADER) {
      int project_num = std::rand() % projects.size();
      TeamLeader* tmp =
      new TeamLeader(std::stoi(id), 200, name, pos, projects[project_num], 0.2);
      staff.push_back(tmp);
    }

    if (pos == PROJECT_MANAGER) {
      ProjectManager* tmp =
      new ProjectManager(std::stoi(id), name, pos, projects, 0.3);
      staff.push_back(tmp);
    }

    if (pos == SENIOR_MANAGER) {
      SeniorManager* tmp =
      new SeniorManager(std::stoi(id), name, projects, pos, 0.4);
      staff.push_back(tmp);
    }

    if (pos == DRIVER) {
      Driver* tmp = new Driver(std::stoi(id), 100, name, pos);
      staff.push_back(tmp);
    }

    if (pos == CLEANER) {
      Cleaner* tmp = new Cleaner(std::stoi(id), 75, name, pos);
      staff.push_back(tmp);
    }
  }

  input.close();
  pr.close();
  return staff;
}
