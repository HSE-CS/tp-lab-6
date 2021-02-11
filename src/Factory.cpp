// Copyright 2020 Stanislav Stoianov

#include <fstream>
#include "../include/Factory.h"
#include "../include/Engineer.h"

std::vector<Employee *> Factory::makeStaff(char *filepath) {
  setlocale(LC_ALL, "rus");
  std::ifstream file(filepath);
  std::string string;
  getline(file, string);
  std::vector<Employee *> employees;
  while (getline(file, string)) {
    printf("%s\n", string.c_str());
    int id;
    std::string name;
    std::string position;
    int salary;
    auto *project = new Project(12, 12);
    std::vector<Project *> projects;
    projects.push_back(project);

    Employee *employee;

    if (position == "Pesonal")
      employee = new Personal(salary);
    else if (position == "Engineer")
      employee = new Engineer(salary, project);
    else if (position == "Cleaner")
      employee = new Cleaner(salary);
    else if (position == "Driver")
      employee = new Driver(salary);
    else if (position == "Programmer")
      employee = new Programmer(salary, project);
    else if (position == "Tester")
      employee = new Tester(salary, project);
    else if (position == "Team Lead")
      employee = new TeamLeader(salary, project);
    else if (position == "Project Manager")
      employee = new ProjectManager(project);
    else if (position == "Senior Manager")
      employee = new SeniorManager(project, projects);
    else
      employee = new Employee();

    employees.push_back(employee);
  }
  file.close();
  return std::vector<Employee *>();
}
