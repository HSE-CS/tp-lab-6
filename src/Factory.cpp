// Copyright 2020 Stanislav Stoianov

#include "../include/Factory.h"
#include "../include/Personal.h"
#include "../include/Engineer.h"
#include <sstream>

std::vector<Employee *> Factory::makeStaff(char *staffpath, char *projectspath) {
  setlocale(LC_ALL, "rus");
  std::ifstream staff(staffpath), projects(projectspath);
  std::string string;
  getline(staff, string);
  getline(projects, string);

  std::vector<Employee *> employees;
  std::vector<Project *> blueprints;
  Project *project;
  Project *project2;

  /**
   * получаем проект
   */
  while (getline(projects, string)) {
    int i = 0;
    std::string temp, arr[3];
    std::stringstream stringstream(string);
    while (std::getline(stringstream, temp, ',')) arr[i++] = temp;
    if (std::stoi(arr[0]) == 1) {
      project = new Project(std::stoi(arr[0]), std::stoi(arr[2]));
    } else {
      project2 = new Project(std::stoi(arr[0]), std::stoi(arr[2]));
    }
  }

  blueprints.push_back(project);
  blueprints.push_back(project2);

  /**
   * получаем персонал
   */
  while (getline(staff, string)) {

    int i = 0;
    std::string temp, arr[5];
    std::stringstream stringstream(string);
    while (std::getline(stringstream, temp, ',')) arr[i++] = temp;
    int id = std::stoi(arr[0]), payment = std::stoi(arr[3]);
    std::string name = arr[1], position = arr[2], projectName = arr[4];

    Employee *employee;
    Project *localProject = projectName == "ВТБ" ? project : project2;

    if (position == "Engineer")
      employee = new Engineer(id, name, position, payment, localProject);
    else if (position == "Cleaner")
      employee = new Cleaner(id, name, position, payment);
    else if (position == "Driver")
      employee = new Driver(id, name, position, payment);
    else if (position == "Programmer")
      employee = new Programmer(id, name, position, payment, localProject);
    else if (position == "Tester")
      employee = new Tester(id, name, position, payment, localProject);
    else if (position == "Team Lead")
      employee = new TeamLeader(id, name, position, payment, localProject);
    else if (position == "Project Manager")
      employee = new ProjectManager(id, name, position, payment, localProject);
    else if (position == "Senior Manager")
      employee = new SeniorManager(id, name, position, payment, localProject, blueprints);

    employees.push_back(employee);
  }
  staff.close();
  return employees;
}

