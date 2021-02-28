// Copyright 2020 S. BOR

#include "Factory.h"
#include <vector>
#include <sstream>
#include <fstream>

static std::vector<Employee *> Factory::fileRead(std::string fileName) {
  std::fstream file(fileName);
  std::vector <Employee *> empls;
  if (file.is_open()) {
    int id, position, salary;
    std::string name, sname;
    while (!f.eof()) {
      f >> id >> name >> sname >> position >> salary;
      switch (position) {
      case 0:
        Cleaner *emp = new Cleaner;
        emp->id = id;
        emp->name = name + " " + sname;
        emp->setSalary(salary);
        emp->position = CLEANER;
        empls.push_back(emp);
        break;
      case 1:
        Driver *emp = new Driver;
        emp->id = id;
        emp->name = name + " " + sname;
        emp->setSalary(salary);
        emp->position = DRIVER;
        empls.push_back(emp);
        break;
      case 2:
        Tester *emp = new Tester;
        emp->id = id;
        emp->name = name + " " + sname;
        emp->setSalary(salary);
        emp->position = TESTER;
        empls.push_back(emp);
        break;
      case 3:
        Programmer *emp = new Programmer;
        emp->id = id;
        emp->name = name + " " + sname;
        emp->setSalary(salary);
        emp->position = PROGRAMMER;
        empls.push_back(emp);
        break;
      case 4:
        TeamLeader *emp = new TeamLeader;
        emp->id = id;
        emp->name = name + " " + sname;
        emp->setSalary(salary);
        emp->position = TEAMLEADER;
        empls.push_back(emp);
        break;
      case 5:
        ProjectManager *emp = new ProjectManager;
        emp->id = id;
        emp->name = name + " " + sname;
        emp->setSalary(salary);
        emp->position = PROJECTMANAGER;
        empls.push_back(emp);
        break;
      case 6:
        SeniorManager *emp = new SeniorManager;
        emp->id = id;
        emp->name = name + " " + sname;
        emp->setSalary(salary);
        emp->position = SENIORMANAGER;
        empls.push_back(emp);
        break;
      default:
        break;
      }

    }
  }
  return empsl;
}
