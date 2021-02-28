// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iostream>
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"

Employee *MakeWorker(int id, const std::string &name, int workTime,int salary,std::string posVal,
                      int project, std::vector<Project *> projects) {
  if (posVal == "project_manager") {
    auto pos = Positions(project_manager);
    Project *my = projects[project];
    return new ProjectManager(id, name, workTime, pos, my);
  } else if (posVal == "team_leader") {
    auto pos = Positions(team_leader);
    return new TeamLeader(id, name, workTime, salary, pos, projects[project]);
  } else if (posVal == "tester") {
    auto pos = Positions(tester);
    return new Tester(id, name, workTime, salary, pos, projects[project]);
  } else if (posVal == "programmer") {
    auto pos = Positions(programmer);
    return new Programmer(id, name, workTime, salary, pos, projects[project]);
  } else if (posVal == "senior_manager") {
    auto pos = Positions(senior_manager);
    return new SeniorManager(id, name, workTime, pos, projects);
  } else if (posVal == "driver") {
    auto pos = Positions(driver);
    return new Driver(id, name,workTime,salary, pos);
  } else if (posVal == "cleaner") {
    auto pos = Positions(cleaner);
    return new Cleaner(id, name,workTime, salary,pos);
  }
  return nullptr;
}

std::vector<Employee *> StaffFactory::makeStaff() {
  std::ifstream dataP("projects.txt");
  std::vector<Project *> projects;
  int projectId = 0;
  int amountOfWorkers = 0;
  int budget = 0;

  std::ifstream dataS("staff.txt");
  std::string name;
  int id = 0;
  int workTime=0;
  int salary = 0;
  std::string posVal;
  if (!dataP.is_open()) {
    throw "no open dataP";
  }
  if (!dataS.is_open()) {
    throw "no open dataS";
  }
  std::string templ;
  while (!dataP.eof()) {
    getline(dataP, templ);
    if (!templ.empty()) {
      projectId = atoi(templ.c_str());
      getline(dataP, templ);
      budget = atoi(templ.c_str());
      getline(dataP, templ);
      amountOfWorkers = atoi(templ.c_str());
      projects.push_back(new Project(projectId, budget, amountOfWorkers));
    }
  }

  std::vector<Employee *> staff;
  std::cout<<std::endl;
  while (!dataS.eof()) {
    getline(dataS, templ);
    if (!templ.empty()) {
      id = atoi(templ.c_str());
      getline(dataS, name);
      getline(dataS, templ);
      workTime = atoi(templ.c_str());
      getline(dataS, templ);
      salary = atoi(templ.c_str());
      getline(dataS, posVal);
      getline(dataS, templ);
      projectId = atoi(templ.c_str());
      staff.push_back(
          MakeWorker(id, name, workTime, salary, posVal,projectId, projects));
    }
  }
  return staff;
}