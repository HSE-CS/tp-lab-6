// Copyright 2021 Arina Simonova

#include "Factory.h"

vector<Employee *> makeStaff(char *staffList, char *projectsList) {
  vector<Employee *> res;
  vector<Project> allProjects;
  string read, elem, arr[5];
  int i;
  setlocale(LC_ALL, "rus");
  ifstream staff(staffList), projects(projectsList);
  while (getline(projects, read)) {
    i = 0;
    stringstream strStream(read);
    while (getline(strStream, elem, ',')) arr[i++] = elem;
    allProjects.push_back(Project(stoi(arr[0]), stoi(arr[1])));
  }
  projects.close();
  while (getline(staff, read)) {
    i = 0;
    stringstream strStream(read);
    while (getline(strStream, elem, ',')) {
      arr[i++] = elem;
    }
    int id = stoi(arr[0]), salary = stoi(arr[3]), projectId = stoi(arr[4]);
    string name = arr[1], position = arr[2];
    int projectBudget;
    for (i = 0; i < allProjects.size(); ++i) {
      if (allProjects[i].GetId() == projectId) {
        projectBudget = allProjects[i].GetBudget();
        break;
      }
    }
    Project currentProject(projectId, projectBudget);
    Employee *newEmployee;
    if (position == "Personal")
      newEmployee = new Personal(id, name, position, 0, 0, salary);
    else if (position == "Driver")
      newEmployee = new Driver(id, name, position, 0, 0, salary);
    else if (position == "Cleaner")
      newEmployee = new Cleaner(id, name, position, 0, 0, salary);
    else if (position == "Engineer")
      newEmployee = new Engineer(id, name, position, 0, 0, salary,
        currentProject);
    else if (position == "Programmer")
      newEmployee = new Programmer(id, name, position, 0, 0, salary,
        currentProject);
    else if (position == "Tester")
      newEmployee = new Tester(id, name, position, 0, 0, salary,
        currentProject);
    else if (position == "Team Lead")
      newEmployee = new TeamLead(id, name, position, 0, 0, salary,
        currentProject);
    else if (position == "Project Manager")
      newEmployee = new ProjectManager(id, name, position, 0, 0, salary,
        currentProject);
    else if (position == "Senior Manager")
      newEmployee = new SeniorManager(id, name, position, 0, 0, salary,
        allProjects);
    res.push_back(newEmployee);
  }
  staff.close();
  return res;
}

