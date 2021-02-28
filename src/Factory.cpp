#include"Employee.h"
#include"Engineer.h"
#include"Manager.h"
#include"Personal.h"
#include "Factory.h"
#include<fstream>

std::vector<Employee *> Factory::makeStaff(std::string project_filen,
                                           std::string staff_filen) {
  std::ifstream file1(project_filen);
  std::vector<Project *> projects;
  int number = 0;
  int budjet = 0;
  std::string name;
  while (file1 >> name || file1 >> number) {
    projects.push_back(new Project(name, budjet, number));
  }
  file1.close();

  std::ifstream file2(staff_filen);
  std::vector<Employee *> staff;
  int id = 0;
  std::string name;
  std::string position;
  int k = 0;
  int salary = 0;
  int project = 0;
  double part;
  int worktime = 0;
  while (file2 >> id) {
    file2 >> name >> position >> worktime >> salary >> project >> part >> k;
    if (position == "Driver") {
      staff.push_back(new Driver(id, name, position, 8, salary));
    }
    if (position == "Cleaner") {
      staff.push_back(new Cleaner(id, name, position, 8, salary));
    }
    if (position == "Engineer ") {
      staff.push_back(new Engineer(id, name, position, worktime, salary,
                                   projects[project], part));
    }
    if (position == "Tester") {
      staff.push_back(new Tester(id, name, position, worktime, salary,
                                 projects[project], part, k));
    }
    if (position == "Programmer") {
      staff.push_back(new Programmer(id, name, position, worktime, salary,
                                     projects[project], part));
    }
    if (position == "TeamLeader") {
      staff.push_back(new TeamLeader(id, name, position, worktime, salary,
                                     projects[project], part));
    }
    if (position == "SeniorManager") {
      staff.push_back(new SeniorManager(id, name, position, projects));
    }
    if (position == "ProjectManager") {
      staff.push_back(new ProjectManager(id, name, position, projects));
    }
  }
  file2.close();
  return staff;
}