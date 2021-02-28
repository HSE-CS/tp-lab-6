// Copyright 27.02.21 DenisKabanov

#include "Factory.h"

void StaffFactory::makeStaff() {
  srand(time(NULL));
  std::vector<Employee*> employees;
  std::ifstream fin("employees.txt");
  std::vector<Project*> projects;
  std::string row;
  while (std::getline(fin, row)) {
    std::string id, name, pos, salary, project;
    std::istringstream f(row);

    std::getline(f, id, ',');
    std::getline(f, name, ',');
    std::getline(f, pos, ',');
    std::getline(f, salary, ',');

	if (pos == "projectManager") {
      std::getline(f, project, ',');
      Project pr;
      pr.id = project;
      pr.budget = 500000;
      projects.push_back(&pr);
      ProjectManager* tmp = new ProjectManager(std::stoi(id), name, &pr);
      employees.push_back(tmp);
    }

    if (pos == "seniorManager") {
      std::getline(f, project, ',');
      Project pr;
      pr.id = project;
      pr.budget = 500000;
      projects.push_back(&pr);
      SeniorManager* tmp = new SeniorManager(std::stoi(id), name, &pr);
      employees.push_back(tmp);
    }

	if (pos == "engineer") {
      std::getline(f, project, ',');
      Project proj;
      proj.id = project;
      proj.budget = 500000;
      projects.push_back(&proj);
      Engineer* tmp =
          new Engineer(std::stoi(id), name, std::stoi(salary), &proj);
      employees.push_back(tmp);
    }

    if (pos == "programmer") {
      std::getline(f, project, ',');
      Project pr;
      pr.id = project;
      pr.budget = 500000;
      projects.push_back(&pr);
      Programmer* tmp =
          new Programmer(std::stoi(id), name, std::stoi(salary), &pr);
      employees.push_back(tmp);
    }

    if (pos == "tester") {
      std::getline(f, project, ',');
      Project pr;
      pr.id = project;
      pr.budget = 500000;
      projects.push_back(&pr);
      Tester* tmp = new Tester(std::stoi(id), name, std::stoi(salary), &pr);
      employees.push_back(tmp);
    }

    if (pos == "teamLeader") {
      std::getline(f, project, ',');
      Project pr;
      pr.id = project;
      pr.budget = 500000;
      projects.push_back(&pr);
      TeamLeader* tmp =
          new TeamLeader(std::stoi(id), name, std::stoi(salary), &pr);
      employees.push_back(tmp);
    }

    if (pos == "driver") {
      Driver* tmp = new Driver(std::stoi(id), name, std::stoi(salary));
      employees.push_back(tmp);
    }

    if (pos == "cleaner") {
      Cleaner* tmp = new Cleaner(std::stoi(id), name, std::stoi(salary));
      employees.push_back(tmp);
    }
  }
  fin.close();
  staff = employees;
}