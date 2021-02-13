// Copyright 2020 Stanislav Stoianov

#include "../include/Factory.h"
#include "../include/Personal.h"
#include "../include/Engineer.h"

std::vector<Employee *> Factory::makeStaff(char *filepath, char *projectspath) {
  setlocale(LC_ALL, "rus");
  std::ifstream file(filepath);
  std::string string;
  getline(file, string);
  std::vector<Employee *> employees;

  while (getline(file, string)) {
    int id = 0, payment = 0;
    std::string name, position;

    auto *project = new Project(1, 120000);
    auto *project2 = new Project(2, 300000);
    std::vector<Project *> projects;
    projects.push_back(project);
    projects.push_back(project2);

    Employee *employee;

    if (position == "Engineer")
      employee = new Engineer(id, name, position, payment, project);
    else if (position == "Cleaner")
      employee = new Cleaner(id, name, position, payment);
    else if (position == "Driver")
      employee = new Driver(id, name, position, payment);
    else if (position == "Programmer")
      employee = new Programmer(id, name, position, payment, project);
    else if (position == "Tester")
      employee = new Tester(id, name, position, payment, project);
    else if (position == "Team Lead")
      employee = new TeamLeader(id, name, position, payment, project);
    else if (position == "Project Manager")
      employee = new ProjectManager(id, name, position, payment, project);
    else if (position == "Senior Manager")
      employee = new SeniorManager(id, name, position, payment, project, projects);

    employees.push_back(employee);
  }
  file.close();
  return employees;
}

