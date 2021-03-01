// Copyright 2021 Egor Trukhin
#include "Factory.h"

#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>

Factory::Factory(const char* filename_staff, const char* filename_projects) {
  // Read projects
  std::ifstream ifprojects(filename_projects);
  if (!ifprojects.is_open())
    throw std::runtime_error("Input file is not opened!");
  std::vector<std::string> projects_info;
  while (!ifprojects.eof()) {
    std::string line;
    std::getline(ifprojects, line);
    if (line.length() < 2) continue;
    projects_info.push_back(line);
  }
  ifprojects.close();

  // Read staff
  std::ifstream ifemployees(filename_staff);
  if (!ifemployees.is_open())
    throw std::runtime_error("Input file is not opened!");
  std::vector<std::string> employees_info;
  while (!ifemployees.eof()) {
    std::string line;
    std::getline(ifemployees, line);
    if (line.length() < 2) continue;
    employees_info.push_back(line);
  }
  ifemployees.close();

  createProjects(projects_info);
  createStaff(employees_info);
}

void Factory::createProjects(const std::vector<std::string>& projects_info) {
  std::random_device rd;
  std::mt19937 gen(rd());

  for (auto project_info : projects_info) {
    project_t* project = new project_t;
    project->name = project_info;
    project->budget = 10000 + gen() % 90000;
    project->staff_size = 0;
    projects.push_back(project);
  }
}

void Factory::createStaff(const std::vector<std::string>& employees_info) {
  std::random_device rd;
  std::mt19937 gen(rd());

  for (auto employee_info : employees_info) {
    std::istringstream info(employee_info);
    std::string id_str, name, name1, name2, position, salary_str;
    info >> id_str >> name >> name1 >> name2 >> position;

    uint32_t id = std::stoi(id_str);
    name += " " + name1;
    name += " " + name2;

    if (position == "Cleaner" || position == "Driver") {
      info >> salary_str;
      uint32_t salary = std::stoi(salary_str);
      if (position == "Cleaner")
        staff.push_back(new Cleaner(id, name, salary));
      else if (position == "Driver")
        staff.push_back(new Driver(id, name, salary));

    } else if (position != "Project_manager" && position != "Senior_manager") {
      info >> salary_str;
      uint32_t salary = std::stoi(salary_str);

      project_t* project = this->projects[gen() % this->projects.size()];
      project->staff_size += 1;

      if (position == "Programmer")
        staff.push_back(new Programmer(id, name, salary, project));
      if (position == "Tester")
        staff.push_back(new Tester(id, name, salary, project));
      if (position == "Team_leader")
        staff.push_back(new TeamLeader(id, name, salary, project));

    } else if (position == "Project_manager") {
      std::vector<project_t*> tmp;
      std::string project_name;
      info >> project_name;

      for (uint32_t id = 0; id < this->projects.size(); id++)
        if (this->projects[id]->name == project_name) {
          tmp.push_back(this->projects[id]);
          break;
        }

      staff.push_back(new ProjectManager(id, name, tmp));
    } else if (position == "Senior_manager") {
      std::vector<project_t*> tmp;
      auto projects_names =
          std::vector<std::string>(std::istream_iterator<std::string>(info),
                                   std::istream_iterator<std::string>());

      for (auto name : projects_names)
        for (uint32_t id = 0; id < this->projects.size(); id++)
          if (this->projects[id]->name == name) {
            tmp.push_back(this->projects[id]);
            break;
          }
      staff.push_back(new SeniorManager(id, name, tmp));
    }
  }
}

std::vector<Employee*>& Factory::getStaff() { return this->staff; }
