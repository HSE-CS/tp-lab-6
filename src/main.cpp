#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "Engineer.h"
#include "Manager.h"
#include "Staff.h"

// Format:
//<id> <job> <first_name> <surname> [<salary>] [<number_of_projects>]
//[<project_id>]

std::vector<Employee*> makeStaff() {
  std::fstream staff("staff.txt");
  std::fstream projects_file("projects.txt");
  std::map<uint32_t, Project> projects;
  std::vector<Employee*> output;

  while (!projects_file.eof()) {
    uint32_t id, budget, staff_num;
    projects_file >> id >> budget >> staff_num;
    Project p = Project{.id = id, .budget = budget, .staff_num = staff_num};
    projects[id] = p;
  }

  while (!staff.eof()) {
    std::string job, firstname, surname;
    uint32_t id, salary, project_id;
    staff >> id >> job >> firstname >> surname;
    if (job == "Janitor") {
      staff >> salary;
      Janitor* ptr = new Janitor(id, firstname, surname, salary);
      output.push_back(ptr);
    } else if (job == "Driver") {
      staff >> salary;
      Driver* ptr = new Driver(id, firstname, surname, salary);
      output.push_back(ptr);
    } else if (job == "Programmer") {
      staff >> salary >> project_id;
      Programmer* ptr =
          new Programmer(id, firstname, surname, salary, projects[project_id]);
      output.push_back(ptr);
    } else if (job == "Tester") {
      staff >> salary >> project_id;
      Tester* ptr =
          new Tester(id, firstname, surname, salary, projects[project_id]);
      output.push_back(ptr);
    } else if (job == "ProjectManager") {
      staff >> project_id;
      ProjectManager* ptr =
          new ProjectManager(id, firstname, surname, projects[project_id]);
      output.push_back(ptr);
    } else if (job == "SeniorManager") {
      uint32_t project_num;
      staff >> project_num;
      std::vector<Project> senior_projects;
      for (uint32_t i = 0; i < project_num; ++i) {
        staff >> project_id;
        senior_projects.push_back(projects[project_id]);
      }
      SeniorManager* ptr =
          new SeniorManager(id, firstname, surname, senior_projects);
      output.push_back(ptr);
    } else if (job == "TeamLeader") {
      staff >> salary >> project_id;
      TeamLeader* ptr =
          new TeamLeader(id, firstname, surname, salary, projects[project_id]);
      output.push_back(ptr);
    }
  }
  return output;
}

int main() {
  // создание штата сотрудников на основе файла
  std::vector<Employee*> staff = makeStaff();

  // присвоение отработанного времени
  for (auto& emp : staff) {
    emp->setWorkTime(100);
  }

  // расчет зарплаты
  for (auto& emp : staff) {
    emp->calc();
  }

  // вывод данных о зарплате
  for (auto& emp : staff) {
    emp->printInfo();
    std::cout << std::endl;
  }
  return 0;
}
