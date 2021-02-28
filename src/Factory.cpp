// Copyright 2021 ArinaMonicheva

#include <fstream>
#include "Factory.h"


StaffFactory::StaffFactory() {
}

std::vector<Employee*> StaffFactory::makeStaff(std::ifstream &employeesFile,
 std::ifstream &projectsFile) {
  std::vector <Project*> projects;
  std::vector <Employee*> employees;
  int managerIndex = 0, progIndex = 0, leadIndex = 0, testIndex = 0;

  while (!projectsFile.eof()) {
    std::string id;
    std::string budget;
    std::string temp;
    std::getline(projectsFile, temp);
    std::istringstream toVar(temp);
    toVar >> id;
    toVar >> budget;
    Project* tempObj = new Project(std::stod(id), std::stod(budget));
    projects.push_back(tempObj);
  }

  while (!employeesFile.eof()) {
    std::string id;
    std::string fio;
    std::string position;
    std::string payment;
    std::string temp;
    std::getline(employeesFile, temp);
    std::istringstream toVar(temp);
    std::getline(toVar, temp, ';');
    id = temp;
    std::getline(toVar, temp, ';');
    fio = temp;
    std::getline(toVar, temp, ';');
    position = temp;
    std::getline(toVar, temp, ';');
    payment = temp;
    if (position == "Cleaner") {
      employees.push_back(new Cleaner(std::stoi(id), fio,
       position, std::stod(payment)));

    } else if (position == "Driver") {
      employees.push_back(new Driver(std::stoi(id), fio,
       position, std::stod(payment)));

    } else if (position == "Project Manager") {
      std::vector <Project*> mProjects;
      mProjects.push_back(projects[managerIndex]);
      projects[managerIndex]->updateStaffNum();
      employees.push_back(new ProjectManager(std::stoi(id), fio,
       position, std::stod(payment), mProjects));
      managerIndex = (managerIndex + 1) % projects.size();

    } else if (position == "Senior Manager") {
      employees.push_back(new SeniorManager(std::stoi(id), fio,
      position, std::stod(payment), projects));

    } else if (position == "Programmer") {
      employees.push_back(new Programmer(std::stoi(id), fio,
       position, std::stod(payment), projects[progIndex]));
      projects[progIndex]->updateStaffNum();
      progIndex = (progIndex + 1) % projects.size();

    } else if (position == "Tester") {
      employees.push_back(new Tester(std::stoi(id), fio,
       position, std::stod(payment), projects[testIndex]));
      projects[testIndex]->updateStaffNum();
      testIndex = (testIndex + 1) % projects.size();

    } else if (position == "Team Leader") {
      employees.push_back(new TeamLeader(std::stoi(id), fio,
       position, std::stod(payment), projects[leadIndex]));
      projects[leadIndex]->updateStaffNum();
      leadIndex = (leadIndex + 1) % projects.size();
    }
  }
  return employees;
}
