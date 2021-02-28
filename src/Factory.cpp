// Copyright 2021 Schenikova
#include "Factory.h"
#include <fstream>

void intoProject(std::vector <Project> projects, int idproject,
Engineer * employee) {
  int flag = 0;
  for (auto p : projects) {
    if (p.id == idproject) {
      employee->setProject(p);
      flag = 1;
      break;
    }
  }
  if (!flag) {
    Project * project = new Project;
    project->id = idproject;
    project->budget = 1000000;
    employee->setProject(*project);
  }
}

std::vector <Project> intoProjects(std::vector <Project> projects, int * id,
ProjectManager * employee) {
  std::vector <Project> mypro;
  int flag = 0;
  for (size_t i = 0; i < 3; i++) {
    for (auto p : projects) {
      if (p.id == id[i]) {
        mypro.push_back(p);
        flag = 1;
        break;
      }
    }
    if (!flag) {
      Project * project = new Project;
      project->id = id[i];
      project->budget = 1000000;
      mypro.push_back(*project);
    }
  }
  return mypro;
}

std::vector<Employee*> StaffFactory::makeStaff(std::string filename) {
  std::vector <Project> projects;
  std::ifstream f(filename);
  if (!f.is_open()) {
    std::cout << "File cannot open\n";
    throw -1;
  }
  std::vector<Employee*> vector;
  std::string fullname;
  std::string name, fname;
  int id, position, salary, idproject;
  while (!f.eof()) {
    f >> id >> name >> fname >> position >> salary;
    fullname = name + " " + fname;
    if (position == 0) {
      Engineer * employee = new Engineer;
      employee->id = id;
      employee->name = fullname;
      employee->position = ENGINEER;
      employee->setSalary(salary);
      f >> idproject;
      intoProject(projects, idproject, employee);
      vector.push_back(employee);
    } else if (position == 1) {
      Cleaner * employee = new Cleaner;
      employee->id = id;
      employee->name = fullname;
      employee->position = CLEANER;
      employee->setSalary(salary);
      vector.push_back(employee);
    } else if (position == 2) {
      Driver * employee = new Driver;
      employee->id = id;
      employee->name = fullname;
      employee->position = DRIVER;
      employee->setSalary(salary);
      vector.push_back(employee);
    } else if (position == 3) {
      Programmer * employee = new Programmer;
      employee->id = id;
      employee->name = fullname;
      employee->position = PROGRAMMER;
      employee->setSalary(salary);
      f >> idproject;
      intoProject(projects, idproject, employee);
      vector.push_back(employee);
    } else if (position == 4) {
      Tester * employee = new Tester;
      employee->id = id;
      employee->name = fullname;
      employee->position = TESTER;
      employee->setSalary(salary);
      f >> idproject;
      intoProject(projects, idproject, employee);
      vector.push_back(employee);
    } else if (position == 5) {
      TeamLeader * employee = new TeamLeader;
      employee->id = id;
      employee->name = fullname;
      employee->position = TEAMLEADER;
      employee->setSalary(salary);
      f >> idproject;
      intoProject(projects, idproject, employee);
      vector.push_back(employee);
    } else if (position == 6) {
      int id1, id2, id3;
      ProjectManager * employee = new ProjectManager;
      employee->id = id;
      employee->name = fullname;
      employee->position = PROJECTMANAGER;
      f >> idproject;
      int _id[1] = {id};
      employee->setProjects(intoProjects(projects, _id, employee));
      vector.push_back(employee);
    } else if (position == 7) {
      SeniorManager * employee = new SeniorManager;
      employee->id = id;
      employee->name = fullname;
      employee->position = SENIORMANAGER;
      employee->setProjects(projects);
      vector.push_back(employee);
    }
  }
  return vector;
}
