// Copyright 2021 Ryzhova Irina


#include "Factory.h"

std::vector<Employee*> StaffFactory::makeStaff(std::string data) {
  std::ifstream file(data);
  if (!file.is_open())
    return;
  std::vector<Employee*> employee;
  std::string id, budget;
  getline(file, id, ';');
  getline(file, budget);
  Project *project = new Project(stoi(id), stod(budget));
  std::vector <Project*> projects = {project};
  while (getline(file, id, ';')) {
    std::string name, position, payment;
    getline(file, name, ';');
    getline(file, position, ';');
    getline(file, payment);
    if (position == "driver") {
      employee.push_back(new Driver(stoi(payment), name,
                         position, stoi(id), 15000));
    } else if (position == "cleaner") {
      employee.push_back(new Cleaner(stoi(payment), name,
                         position, stoi(id), 14000));
    } else if (position == "programmer") {
      employee.push_back(new Programmer(stoi(id), name, 25000,
                         position, stoi(payment), project));
    } else if (position == "tester") {
      employee.push_back(new Tester(stoi(id), name, 20000,
                         position, stoi(payment), project));
    } else if (position == "team leader") {
      employee.push_back(new TeamLeader(stoi(id), name, 30000,
                         position, stoi(payment), project));
    } else if (position == "project manager") {
      employee.push_back(new ProjectManager(stoi(id), name,
                         position, stoi(payment), projects));
    } else if (position == "senior manager") {
      employee.push_back(new SeniorManager(stoi(id), name,
                         position, stoi(payment), projects));
    }
  }
  return employee;
}
