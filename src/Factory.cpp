// Copyright 2021 by Bodrov Egor

#include "Factory.h"
#include <iostream>
#include <sstream>

std::vector<Employee*> FactoryWork::makeStaff() {
  std::vector<Employee*> staff;
  std::ifstream in("workers.txt");
  std::ifstream pr("projects.txt");

  if (in.is_open() == false || pr.is_open() == false) {
    std::cout << "No such file\n";
    return staff;
  }

  std::vector<Project*> projects;
  std::string budget, title;
  while (pr >> budget >> title) {
    Project* tmp = new Project(std::stoi(budget), title);
    projects.push_back(tmp);
  }

  std::string row;
  while (std::getline(in, row)) {
    std::string id, name, pos;
    std::istringstream f(row);

    std::getline(f, id, ',');
    std::getline(f, name, ',');
    std::getline(f, pos, ',');

    if (pos == "Programmer") {
      int project_num = std::rand() % projects.size();
      Programmer* tmp = new Programmer(std::stoi(id), 200, name, pos,
                                       projects[project_num], 0.3);
      staff.push_back(tmp);
    }

    if (pos == "Tester") {
      int project_num = std::rand() % projects.size();
      Tester* tmp =
          new Tester(std::stoi(id), 150, name, projects[project_num], 0.3);

      staff.push_back(tmp);
    }

    if (pos == "TeamLeader") {
      int project_num = std::rand() % projects.size();
      TeamLeader* tmp =
          new TeamLeader(std::stoi(id), 200, name, projects[project_num], 0.25);

      staff.push_back(tmp);
    }

    if (pos == "ProjectManager") {
      ProjectManager* tmp =
          new ProjectManager(std::stoi(id), name, pos, projects, 0.3);
      staff.push_back(tmp);
    }

    if (pos == "SeniorManager") {
      SeniorManager* tmp =
          new SeniorManager(std::stoi(id), name, projects, 0.3);

      staff.push_back(tmp);
    }

    if (pos == "Driver") {
      Driver* tmp = new Driver(std::stoi(id), 90, name);
      staff.push_back(tmp);
    }

    if (pos == "Cleaner") {
      Cleaner* tmp = new Cleaner(std::stoi(id), 70, name);
      staff.push_back(tmp);
    }
  }

  in.close();
  pr.close();
  return staff;
}
