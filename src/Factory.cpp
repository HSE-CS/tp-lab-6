// Copyright 2021 Tatsenko Alexey
#include "Factory.h"
#include <fstream>
#include <iostream>
#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"

Position converse(std::string pos) {
  if (pos == "Programmer")
    return PROGRAMMER;
  else if (pos == "Tester")
    return TESTER;
  else if (pos == "Driver")
    return DRIVER;
  else if (pos == "Cleaner")
    return CLEANER;
  else if (pos == "Engineer")
    return ENGINEER;
  else if (pos == "SeniorManager")
    return SENIOR_MANAGER;
  else if (pos == "ProjectManager")
    return PROJECT_MANAGER;
  else if (pos == "TeamLeader")
    return TEAM_LEADER;
}

Project* find_project(std::string name, std::vector<Project*> projects) {
  for (auto& proj : projects) {
    if (proj->get_name() == name) return proj;
  }
}

std::vector<Employee*> Factory::make_staff(std::string project_filen,
                                           std::string staff_filen) {
  std::ifstream file1(project_filen);

  std::vector<Project*> projects;
  int number = 0;
  int budjet = 0;
  std::string str;

  while (!file1.eof()) {
    file1 >> str;
    file1 >> budjet;
    projects.push_back(new Project(str, budjet));
  }

  file1.close();

  std::ifstream file2;
  file2.open(staff_filen);

  std::vector<Employee*> employes;
  int id;
  std::string pos;
  Position pos_;
  int number_find_errors = 0;
  int salary_per_hour = 0;
  std::string project;
  std::string part;
  int worktime = 0;
  std::string n;

  while (!file2.eof()) {
    file2 >> id;
    file2 >> str >> pos;
    pos_ = converse(pos);
    if (pos_ == DRIVER) {
      file2 >> salary_per_hour;
      employes.push_back(new Driver(id, str, pos_, salary_per_hour));
    }
    if (pos_ == CLEANER) {
      file2 >> salary_per_hour;
      employes.push_back(new Cleaner(id, str, pos_, salary_per_hour));
    }
    if (pos_ == ENGINEER) {
      file2 >> salary_per_hour >> project >> part;

      employes.push_back(new Engineer(id, str, pos_, salary_per_hour,
                                      find_project(project, projects),
                                      stof(part)));
    }
    if (pos_ == TESTER) {
      file2 >> salary_per_hour >> project >> part >> number_find_errors;
      employes.push_back(new Tester(id, str, pos_, salary_per_hour,
                                    find_project(project, projects), stof(part),
                                    number_find_errors));
    }
    if (pos_ == PROGRAMMER) {
      file2 >> salary_per_hour;
      file2 >> project;
      file2 >> part;
      employes.push_back(new Programmer(id, str, pos_, salary_per_hour,
                                        find_project(project, projects),
                                        stof(part)));
      // std::cout << std::endl;
    }
    if (pos_ == TEAM_LEADER) {
      file2 >> salary_per_hour >> project >> part;
      employes.push_back(new TeamLeader(id, str, pos_, salary_per_hour,
                                        find_project(project, projects),
                                        stof(part)));
    }
    if (pos_ == SENIOR_MANAGER) {
      employes.push_back(new SeniorManager(id, str, pos_, projects));
    }
    if (pos_ == PROJECT_MANAGER) {
      file2 >> project;
      employes.push_back(new ProjectManager(id, str, pos_, projects, project));
    }
  }
  file2.close();
  return employes;
}
