// Copyright 2021 Tatsenko Ilya
#include "Factory.h"
#include <fstream>
#include <iostream>
#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"

std::vector<Employee *> Factory::makeStaff(std::string project_filen,
                                           std::string staff_filen) {
  std::ifstream file1(project_filen);

  std::vector<Project *> projects;
  int number = 0;
  int budjet = 0;
  std::string str;
  std::string str;

  while (!file1.eof()) {
    file1 >> str;
    file1 >> budjet;
    file1 >> number;
    projects.push_back(new Project(str, budjet, number));
  }

  file1.close();

  std::ifstream file2;
  file2.open(staff_filen);

  std::vector<Employee *> employes;
  int id = 0;
  std::string pos;
  int k = 0;
  int salary = 0;
  int project = 0;
  std::string part;
  int worktime = 0;
  std::string n;

  while (!file2.eof()) {
    file2 >> id >> str >> pos;

    if (pos == "Driver") {
      file2 >> worktime >> salary;
      employes.push_back(new Driver(id, str, pos, worktime, salary));
    }
    if (pos == "Cleaner") {
      file2 >> worktime >> salary;
      employes.push_back(new Cleaner(id, str, pos, worktime, salary));
    }
    if (pos == "Engineer ") {
      file2 >> worktime >> salary >> project >> part;

      employes.push_back(new Engineer(id, str, pos, worktime, salary,
                                      projects[project], stof(part)));
    }
    if (pos == "Tester") {
      file2 >> worktime >> salary >> project >> part >> k;
      employes.push_back(new Tester(id, str, pos, worktime, salary,
                                    projects[project], stof(part), k));
    }
    if (pos == "Programmer") {
      file2 >> worktime;
      file2 >> salary;
      file2 >> project;
      file2 >> part;
      employes.push_back(new Programmer(id, str, pos, worktime, salary,
                                        projects[project], stof(part)));
      // std::cout << std::endl;
    }
    if (pos == "TeamLeader") {
      file2 >> worktime >> salary >> project >> part;
      employes.push_back(new TeamLeader(id, str, pos, worktime, salary,
                                        projects[project], stof(part)));
    }
    if (pos == "SeniorManager") {
      employes.push_back(new SeniorManager(id, str, pos, projects));
    }
    if (pos == "ProjectManager") {
      file2 >> project;
      employes.push_back(new ProjectManager(id, str, pos, projects, project));
    }
  }
  file2.close();
  return employes;
}
