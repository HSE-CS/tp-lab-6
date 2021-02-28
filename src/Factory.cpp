// Copyright 2021 Egor Buzanov

#include "Factory.h"

std::vector<Employee *> Factory::makeStaff(std::string _project_filename,
                                           std::string _staff_filename) {
  std::ifstream project_file(_project_filename);
  std::vector<Project *> projects;
  int project_id = 0;
  int project_budget = 0;
  while (project_file >> project_id) {
    projects.push_back(new Project(project_id, project_budget));
  }
  project_file.close();

  std::ifstream file(_staff_filename);
  std::vector<Employee *> staff;
  int id = 0;
  std::string name;
  std::string position;
  int salary = 0;
  int project = 0;
  double part;
  while (file >> id) {
    file >> name >> position >> salary >> project >> part;
    if (position == "Driver") {
      staff.push_back(new Driver(id, name, salary));
    }
    if (position == "Cleaner") {
      staff.push_back(new Cleaner(id, name, salary));
    }
    if (position == "ProjectManager") {
      staff.push_back(
          new ProjectManager(id, name, salary, projects[project], part));
    }
    if (position == "Tester") {
      staff.push_back(new Tester(id, name, salary, projects[project], part));
    }
    if (position == "Programmer") {
      staff.push_back(
          new Programmer(id, name, salary, projects[project], part));
    }
    if (position == "TeamLeader") {
      staff.push_back(
          new TeamLeader(id, name, salary, projects[project], part));
    }
    if (position == "SeniorManager") {
      staff.push_back(new SeniorManager(id, name, salary, projects, part));
    }
    if (position == "Engineer ") {
      staff.push_back(new Engineer(id, name, salary, projects[project], part));
    }
  }
  file.close();
  return staff;
}
